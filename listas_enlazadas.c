#include <stdio.h>
#include <stdlib.h>

struct node{
    int num;
    struct node* next;
};

void anhade_a_nodo(struct node*, int);
void imp_listas(struct node*);
struct node* delete_all_de_lista(struct node*, int);
void concat(struct node *, struct node *);
struct node *anhade(struct node *, int , int);
struct node *crear(int);

int main()
{   
    struct node *head = crear(3);
    
    imp_listas(head);  
    
    //anhade_a_nodo(head,4);
    imp_listas(head);
    
    head = delete_all_de_lista(head,0);
    imp_listas(head);
    
    struct node* head2 = malloc(sizeof(struct node));
    head2->num = 77;
    head2->next = NULL;
    concat(head,head2);
    imp_listas(head);
    
    head = anhade(head,56,3);
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

struct node* delete_all_de_lista(struct node* head, int n)
{
    struct node* cur = head->next;
    struct node* prev = head;
    printf("%d\n",head->num);
    if (head-> num == n){
        head = head->next;
        free(prev);
    }
    else
         while (cur != NULL){
            if (cur->num == n){
                prev->next = cur->next;
                free(cur);
            }
            prev = cur;
            cur = cur->next;
        }    
    return head;
}

void concat(struct node * head1, struct node *head2)
{
    struct node *cur = head1;
    for (; cur->next != NULL; cur = cur->next)
        ;
    cur->next = head2;
}

struct node *anhade(struct node * head, int num, int pos)
{
    struct node *prev = head,*cur = head->next,*nodo = malloc(sizeof(struct node));
    nodo->num = num;
    if (pos == 0){
        nodo->next = prev;
        head = nodo;
        return head;
    }
    int cont;
    for(cont = 1; cont != pos; cont++, prev = cur, cur = cur->next)
        ;
    prev->next = nodo;
    nodo->next = cur;
    
    return head;
}

struct node *crear(int n)
{
    struct node* head = malloc(sizeof(struct node));
    head->num = 0;
    struct node* cur = head;    
    for(int i = 1; i<=n; i++){      
        struct node* nodo = malloc(sizeof(struct node));
        nodo-> num = i;
        cur-> next = nodo;
        cur = nodo;
    }
    cur-> next = NULL;
    return head;
}




























