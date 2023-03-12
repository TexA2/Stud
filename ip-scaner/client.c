#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <time.h>
#include <sys/select.h>

#define PORT 50000 // ПОРТ по которому опрашиваем доступные сервера
#define TIMESEC 1  // кол-во секунд для опроса

static char ipstr[16]; // локальный ip-адрес компьютера
static char ipbrc[16]; // широковещательный адресс

struct scan
{
    char ip[16];
    struct scan *next;
};

typedef struct scan iplist;

void getIP();
void new_unit_head(iplist **, char *); // добавление в начало
void output_iplist_head(iplist *);     /*Функция вывод списка*/

int main()
{
    struct sockaddr_in scan_client, scan_broadcast;
    int scan_socket_client;
    char otvet[16];

    iplist *head = NULL;

    getIP(); // получаем Ip адрес.

    /***********CLIENT**************/
    memset(&scan_client, 0, sizeof(scan_client));
    scan_client.sin_family = AF_INET;   // Используем протокол IPv4
    scan_client.sin_port = htons(PORT); // используем свободный порт 50000
    if (!inet_aton(ipstr, &scan_client.sin_addr))
    {
        perror("inet_aton");
    }

    /**********BROADCAST***************/
    memset(&scan_broadcast, 0, sizeof(scan_broadcast));
    scan_broadcast.sin_family = AF_INET;   // используем протокол IPv4
    scan_broadcast.sin_port = htons(PORT); // Используем свободный порт 50000
    if (!inet_aton(ipbrc, &scan_broadcast.sin_addr))
    {
        perror("inet_aton");
    }

    printf("Ip-adres: %s\n", ipstr);
    printf("Broadcast: %s\n", ipbrc);

    // ************Генерируем socket-client********************
    // AF_INET - используем протокол IPv4
    // SOCK_DGRAM - используем UDP
    if ((scan_socket_client = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("Не удалось создать сокет!\n");
        exit(0);
    }

    // Настраиваем возможность броадкаст вещения
    int yes = 1;

    if (setsockopt(scan_socket_client, SOL_SOCKET, SO_BROADCAST, &yes, sizeof(yes)) < 0)
    {
        perror("setsockopt failed\n");
        exit(0);
    }

    if (bind(scan_socket_client, (struct sockaddr *)&scan_client, sizeof(scan_client)) < 0)
    {
        perror("bind error\n");
        close(scan_socket_client);
        exit(1);
    }

    // Отправляем серверам сообщение
    if (sendto(scan_socket_client, ipstr, strlen(ipstr) + 1, 0, (struct sockaddr *)&scan_broadcast, sizeof(scan_broadcast)) < 0)
    {
        perror("Ошибка отправки\n");
        exit(1);
    }

    // получаем ответ
    printf("Ответы>\n");
    int size_broad = sizeof(scan_broadcast);


    struct timeval tv;
    tv.tv_sec = TIMESEC;

    for (;;)
    {
        fd_set rfd;
        FD_ZERO(&rfd);
        FD_SET(scan_socket_client, &rfd);

        // блокируемся пока не получим данные или не истечет время
        int n = select(scan_socket_client + 1, &rfd, 0, 0, &tv);

        if (n < 0)
        {
            break;
        } // произошла ошибка

        if (n == 0)
        {
            break;
        } // выходим из цикла по таймауту

        if (FD_ISSET(scan_socket_client, &rfd))
        {
            if (recvfrom(scan_socket_client, otvet, 16, 0, (struct sockaddr *)&scan_broadcast, &size_broad) < 0)
            {
                perror("Ошибка при приеме сообщения\n");
                exit(0);
            }

            new_unit_head(&head, otvet);
        }
    }

    output_iplist_head(head);
    close(scan_socket_client);
}

// работает только для частынх сетей класса С 192.168.0.0 с маской 24
void getIP()
{
    struct ifaddrs *ifap, *ifa;
    struct sockaddr_in *sa;
    int len;        // длина ip-адреса
    int j = 0;      // адрес 3 точки в ip-адресе
    int tochka = 3; // в IP-адресе 3 точки, после 3 должны делать замену
    static char *addr;

    getifaddrs(&ifap);
    for (ifa = ifap; ifa; ifa = ifa->ifa_next)
    {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET)
        {
            sa = (struct sockaddr_in *)ifa->ifa_addr;
            addr = inet_ntoa(sa->sin_addr);

            if (addr[0] == '1' && addr[1] == '9' && addr[2] == '2')
            {
                strcpy(ipstr, addr);
                len = strlen(ipstr);
                strcpy(ipbrc, addr);
                for (int i = 0; i < len; i++)
                {
                    if (addr[i] == '.')
                    {
                        j = i;
                    }
                }

                ipbrc[j + 1] = '2';
                ipbrc[j + 2] = '5';
                ipbrc[j + 3] = '5';
            }
        }
    }

    freeifaddrs(ifap);
}

void new_unit_head(iplist **head, char *ipaddr)
{
    iplist *tmp = (iplist *)malloc(sizeof(iplist));
    strcpy(tmp->ip, ipaddr);

    tmp->next = (*head);
    *head = tmp;
}

void output_iplist_head(iplist *head)
{
    iplist *start = head;
    int i = 1;
    while (start != NULL)
    {
        printf("%d: %s\n", i++, start->ip);
        start = start->next;
    }
}
