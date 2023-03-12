#include <stdio.h>
#include <stdlib.h>


struct tree
{
    int i;
    struct tree *left;
    struct tree *right;
};


void creat_tree(struct tree **head){
        
   *head = (struct tree *) malloc (sizeof(struct tree));

   if (*head == NULL){
    printf("Malloc error\n");
   }
   
}

void tree_add(int num, struct tree **head){

    if (*head == NULL){
        creat_tree(head);
        (*head)->i = num;
        (*head)->left = NULL;
        (*head)->right = NULL;
        return;
    }

//shift left
    if (num < (*head)->i){
        tree_add(num, &(*head)->left);
    }

//shift right
    if(num >= (*head)->i){
        tree_add(num, &(*head)->right);
    }
    
}
int tab = 0;

//print Tree
void treeprint(struct tree *head){

    if (head == NULL){
        return;
    }

    tab += 1;
    treeprint(head->right);

    for (int i = 0; i < tab; i++){
        printf("\t");
    }

    printf("%d\n", head->i);

    treeprint(head->left);

    tab -= 1;

}

int main(){

    struct tree *head = NULL;
    tree_add(6, &head);
    tree_add(5, &head);
    tree_add(7, &head);
    tree_add(3, &head);

    printf("Print fisic the tree:\n");
    treeprint(head);

    return 0;
}