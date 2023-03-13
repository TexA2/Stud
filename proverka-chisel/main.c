#include <stdio.h>

#define MAX 100

void idenfyli(int buf[], int size)
{
    int m;

    for (int i = 0; i < size; i++)
    {
        scanf("%d", &m);
        buf[i] = m;
    }
}

void proverka(int buf[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 1 + i; j < size; j++)
        {
            if (buf[i] == buf[j])
            {
                printf("Пара найдена %d %d\n", buf[i] , buf[j]);
                return;
            }
        }
    }
    printf("Пара не найдена\n");
}

int main()
{
    int n; // кол-во снежинок
    int buf[MAX];
    scanf("%d", &n);
    idenfyli(buf, n);
    proverka(buf, n);

    return 0;
}