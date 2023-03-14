#include <stdio.h>
#include <stdlib.h> // malloc

// main_v2 это ускоренная версия main

#define SNOW 6 // 6-кол-во граней снежинки
#define SIZE 1000

struct snowflake_node
{
    int snowflake[SNOW];
    struct snowflake_node *next;
};

typedef struct snowflake_node snowflake_node;

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

void identify_identical(snowflake_node *snowflake[])
{
   snowflake_node *node1, *node2;
   
   for (int i = 0; i < SIZE; i++){
        node1 = snowflake[i];

        while (node1 != NULL){
            node2 = node1->next;
            while (node2 != NULL){
                if (are_identical(node1->snowflake, node2->snowflake)){
                    printf("Сушествуют одинаковые снежики\n");
                    return;
                }
                node2 = node2->next;
            }
            node1 = node1->next;
        }
   }
   printf("Одинаковых снежинок не обнаруженно\n");
}

// находим код(индекс) снежинки
int code(int snowflake[])
{
    return (snowflake[0] + snowflake[1] + snowflake[2] + snowflake[3] + snowflake[4] + snowflake[5]) % SIZE;
}

int main()
{
    snowflake_node *snowflake[SIZE] = {NULL};
    snowflake_node *snow = NULL;

    int n, snowflake_code;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        snow = (snowflake_node *)malloc(sizeof(snowflake_node));

        if (snow == NULL)
        {
            fprintf(stderr, "malloc error\n");
            exit(1);
        }

        for (int j = 0; j < SNOW; j++)
        {
            scanf("%d", &snow->snowflake[j]);
            snowflake_code = code(snow->snowflake);
            snow->next = snowflake[snowflake_code];
            snowflake[snowflake_code] = snow;// коллизия;
        }
    }

    identify_identical(snowflake);

    return 0;
}