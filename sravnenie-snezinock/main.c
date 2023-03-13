#include <stdio.h>

#define SNOW 6 // 6-кол-во граней снежинки
#define SIZE 1000

int identical_right(int snow1[], int snow2[], int start)
{
    for (int i = 0; i < SNOW; i++)
    {
        if (snow1[i] != snow2[(start + i) % 6])
            return 0;
    }
    return 1;
}

int identical_letf(int snow1[], int snow2[], int start)
{
    int snow2_index;
    for (int i = 0; i < SNOW; i++)
    {
        snow2_index = start - i;
        if (snow2_index < 0)
            snow2_index += SNOW;
        if (snow1[i] != snow2[snow2_index])
            return 0;
    }
    return 1;
}

int are_identical(int snow1[], int snow2[])
{
    for (int start = 0; start < SNOW; start++)
    {
        if (identical_right(snow1, snow2, start))
            return 1;
        if (identical_letf(snow1, snow2, start))
            return 1;
    }
    return 0;
}


void identify_identical(int snowflakes[][6], int size){
    for (int i = 0; i < size; i++){
        for (int j = 1+i; j < size; j++){
            if (are_identical(snowflakes[i], snowflakes[j])){
                printf("Существуют одинаковые снежинки\n");
                return;
            }
        }
    }
    printf("Одинаковых снежинок нет\n");
}


int main()
{

/*тестирование are_identical()
    // снежинки не похожи
        int a[SNOW] = {1, 2, 3, 4, 5, 6};
        int b[SNOW] = {11, 9, 6, 0, 2, 3};

    // снежинки похожи
        int a[SNOW] = {1, 2, 3, 4, 5, 6};
        int b[SNOW] = {4, 5, 6, 1, 2, 3};
    
    // снежики похожи
        int a[SNOW] = {1, 2, 3, 4, 5, 6};
        int b[SNOW] = {3, 2, 1, 6, 5, 4};
*/

    int snowflakes[SIZE][6];
    int n;// кол-во снежинок
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < SNOW; j++)
            scanf("%d", &snowflakes[i][j]);
    
    identify_identical(snowflakes, n);


    return 0;
}