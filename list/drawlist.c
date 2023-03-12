#include <stdio.h>
#include <stdlib.h>

struct list
{
    int coin;
    int i;
    struct list *next;
};

void printlist(struct list *);

void creatlist(struct list **head){
    *head = (struct list *) malloc (sizeof(struct list));

    if (*head == NULL){
        printf("Malloc error\n");
    }
}

void addhead (struct list **head, int i){
        static int coin = 1;

        struct list *temp = NULL;
        creatlist(&temp);
        
        temp->i = i;
        temp->coin = coin;
        temp->next = *head;
        *head = temp;
        coin +=1;
}

void addfooter(struct list **head, int i){
    static int coin2 = -1;

    if (*head == NULL){
        creatlist(&(*head));
        (*head)->i = i;
        (*head)->coin = coin2;
        (*head)->next = NULL;
        coin2--;
        return;
    }

    struct list *temp = NULL;
    creatlist(&temp);
    temp->i = i;
    temp->coin = coin2;
    temp->next = NULL;
    
    struct list *temp2 = *head;

    while ( (*head)->next != NULL){
        *head = (*head)->next;
    }

    (*head)->next = temp;
    *head = temp2;
    coin2--;
}

void pop(struct list **head){
    if (*head == NULL){
        printf("list empty\n");
        return;
    }

    struct list *temp = (*head)->next;
    free(*head);
    *head = temp;
}

void delete_tail(struct list **head){

    if (*head == NULL){
        printf("list empty\n");
        return;
    }

    if ((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }

    struct list *temp = *head;

    while (temp->next->next != NULL){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

}

void freelist(struct list **head){

    if ( (*head)->next != NULL){
        *head = (*head)->next;
        freelist(&(*head));
    }

    free(*head);
    *head = NULL;
}


void delete_pos(struct list **head, int pos){
    int i = 0;

    if (*head != NULL){
        i++;
    } else {
        printf("list empty\n");
        return;
    }

    struct list *temp = *head;


// проходим по всему списку
    while (temp->next != NULL){
        temp = temp->next;
        i++;
    }

// возращаем temp на старт
    temp = *head;

    if ( (pos == 1) && (i == 1) ){
        free(*head);
        *head = NULL;
        return;
    }

    if ( (pos == 1) && (i > 1) ){
        *head = (*head)->next;
        free(temp);
        return;
    }

    if ( pos > i){
        printf("Такого элемента не существует\n");
        return;
    }

    struct list *temp2 = *head;

    if (i >= pos){
            if (pos > 1){
                for (int i = 1; i < pos; i++){
                    temp = temp->next;
                }
            
            }
            while (temp2->next != temp)
                temp2= temp2->next;
        
        struct list *temp3 = temp->next;

        temp2->next = temp3;
        free(temp);
    }

}

int main(){

    struct list *list = NULL;


    addfooter(&list, -1);
    addhead(&list, 5);
    addfooter(&list, 0);
    addhead(&list, 6);
    addfooter(&list, -100);
    addhead(&list, 7);
    pop(&list);
    delete_tail(&list);


  delete_pos(&list,5);
    printlist(list);
    printf("end\n");
/*
    freelist(&list);
    printlist(list);

    printf("end2\n");
*/
    return 0;
}


void printlist (struct list *head){
    if (head == NULL){
        printf("list empty\n");
        return;
    }

    while (head != NULL){
        printf("№add%3.1d:%2.1d   %p\n", head->coin ,head->i, head->next);
        head = head->next;
    }
}