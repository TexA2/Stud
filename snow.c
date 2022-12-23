#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define I 80
#define J 23

void newsnow (char (*s)[J]);
void printfield (char (*s)[J]);
void linerand (char (*s)[J]);
void snow_move (char (*s)[J]);

int main()
{
    srand(time(NULL));
    char a[I][J];

    system("clear");

    printf("\t######  #    #   #####   #####   #      #  #       #\n");
    printf("\t##      #    #  #     #  #    #  #      #  # #   # #\n");
    printf("\t##      ######  #     #  ####    ###### #  #   #   #\n");
    printf("\t##      #    #  #     #  #    #  #    # #  #       #\n");
    printf("\t######  #    #   #####   #####   ###### #  #       #\n");

    printf("\n");
        printf("\t  #####    #####       #####     ####   #      #  #\n");
        printf("\t  #       #     #     #     #   #    #  # #  # #  #\n");
        printf("\t  #       #     #     #     #   #    #  #   #  #  #\n");
        printf("\t  #       #     #    #########  #    #  #      #   \n");
        printf("\t  #        #####      #     #    ####   #      #  #\n");
    
    sleep(3);
    system("clear");
    newsnow(a); 
    linerand(a); 
    printfield(a);
    sleep(1);

    do
    {
        snow_move(a);
        linerand(a);
        printfield(a);
        sleep(1);
        system("clear");
    } while (1);
    
    return 0;
}

void newsnow (char (*s)[J])
{
    for (int j = 0; j < J; j++)
        for (int i = 0; i < I; i++)
            s[i][j] = ' ';
}

void printfield (char (*s)[J]){

    for (int j = 0; j < J; j++){
        for (int i = 0; i < I; i++)
            printf("%c", s[i][j]);
        printf("\n");
    }
}

void linerand (char (*s)[J]){
    for (int i = 0; i < I; i++)
         s[i][0] = rand()%(100-98);
    for (int i = 0; i < I; i++){
        if (s[i][0] == 1) s[i][0] = '*';
        if (s[i][0] == 0) s[i][0] = ' ';
    }   
}

void snow_move (char (*s)[J])
{
    for (int j = J-2; j >= 0 ; j--)
        for (int i = 0; i < I; i++)
            s[i][j+1] = s[i][j];
}


