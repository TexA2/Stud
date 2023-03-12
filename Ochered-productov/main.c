#include <stdio.h>
#include <stdlib.h>


void turn(int size, int **x){
    *x = (int *) malloc (size * (sizeof(int)));

    if ((*x) == NULL){
        printf("Malloc error\n");
    }

    for (int i = 0; i < size; i++){
        printf("Введтье кол-во людей в очереди №%d\n", i+1);
        scanf("%d", (*x+i));
    }
}

void wasturn(int size,int sizeman, int *x){
    int man = 1;
    int min = 100;
    int pos = 0;

    for (int i=0; i < sizeman; i++){
    
        for (int i=0; i < size; i++){
            if (x[i] <= min){
                min = x[i];
                pos = i;
            }
        }

    printf("изменим очереди с кол-во людей %d\n", x[pos]);

    x[pos] += man;
    min = 100;
        
    }
}



int main(){
    unsigned int n; // кол-во очередей
    unsigned int m; // кол-во людей

    int *x = NULL;

    printf("Введите данные 1)кол-во очередей 2)кол-во людей\n");

    scanf("%d%d", &n,&m);

    turn(n,&x);

    wasturn(n,m,x);

    free(x);
    return 0;
}