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
    newsnow(a); 
    linerand(a); 
   

   for (int i = 0 ; i < 2000; i++){
        snow_move(a);
        linerand(a);
   }

    do
    {
        system("clear");
        snow_move(a);
        linerand(a);
        printfield(a);
        sleep(1);
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
    for (int j = J-1; j >= 0 ; j--)
        for (int i = 0; i < I; i++)

   
       s[i][j+1] = s[i][j];
       /*Проблема почему он не переносит всю строку вниз а только
       первый элемент s[0][0] и когда она пройдет полный путь
       s[0][J] только следующий элемент пойдет спускатся в низ.
       */
    
}


