#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node* next;
};

void anhade_a_nodo(struct node*, int);
void imp_listas(struct node*);
void delete_all_de_lista(struct node*, int);

int main()
{   
    struct node* head = malloc(sizeof(struct node));
    head->num = 0;
    struct node* cur = head;    
    for(int i = 1; i<=3; i++){      
        struct node* nodo = malloc(sizeof(struct node));
        nodo-> num = i;
        cur-> next = nodo;
        cur = nodo;
    }
    cur-> next = NULL;
    
    imp_listas(head);    
    anhade_a_nodo(cur,4);
    imp_listas(head);
    delete_all_de_lista(head,0);
    imp_listas(head);
    
    return 0;
}

void imp_listas(struct node* head)
{
    struct node* cur;
    for(cur = head; cur != NULL; cur = cur->next){
        printf("%d -> ", cur->num);
    }
    printf("\n");
    return;
}

void anhade_a_nodo(struct node* cur, int n)
{
    struct node* nodo = malloc(sizeof(struct node));
    nodo-> num = n;
    nodo-> next = NULL;
    cur->next = nodo;
    return;    
}

void delete_all_de_lista(struct node* head, int n)
{
    struct node* cur = head;
    struct node* prev = head;
    printf("%d\n",head->num);
    if (head-> num == n){
        head = head->next;
        free(prev);
    }
    //for(cur = head; cur != NULL; cur = cur->next){}
    return;
}





