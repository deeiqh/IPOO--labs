#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int numero;
    struct nodo *siguiente;
};

struct nodo *crear(int);
void imprimir(struct nodo *);
void eliminar(struct nodo **, int);
void concatenar(struct nodo **, struct nodo *);
void agregar(struct nodo **, int, int);

int main(void)
{
    struct nodo *head = crear(5); // del 0 al 4
    imprimir(head);
    
    eliminar(&head,5); //el free, a un int lo vuelve cero y a un puntero lo deja como esta (no lo pone a NULL)
    imprimir(head);
    
    struct nodo *head1 = NULL;
    concatenar(&head1, head);
    imprimir(head1);
    
    struct nodo *head3 = crear(3);
    concatenar(&head1, head3);
    imprimir(head1);
    
    agregar(&head, 9, 6);
    imprimir(head);
    
    return 0;
}

struct nodo *crear(int n)
{
    if (n>0){
        //cabeza de lista
        struct nodo *head = malloc(sizeof(struct nodo));
        head->numero = 7;
        head->siguiente = NULL;
        //lo demás
        if (n>1){            
            struct nodo *cur = head; //tengo un current, ahora voy a agregar
            for (int i = 1; i != n; i++){
                struct nodo *nuevo = malloc(sizeof(struct nodo));                 
                nuevo->numero = i;
                nuevo->siguiente = NULL;
                cur->siguiente = nuevo;
                cur = nuevo;
            }   
        }
        return head;
    }
    return NULL;
}

void imprimir(struct nodo *head)
{
    if (head == NULL)
        printf("NULL\n");
    else{
        //imprime cabeza
        printf("%d -> ",head->numero);
        //lo demás
        struct nodo *cur = head->siguiente; //tengo un current, ahora voy a imprimir
        while (cur != NULL){
            printf("%d -> ",cur->numero);
            cur = cur->siguiente;
        }
        printf("NULL\n");
    }
}

/*
void eliminar(struct nodo *head2, int posicion) // head2 copia por valor de head; es decir, head nunca se va a modificar
{
    if (head2 != NULL){
        //eliminar cabeza
        if (posicion == 0){
            struct nodo *temp = head2;
            head2 = head2->siguiente;
            free(temp); //el free, a un int lo vuelve cero y a un puntero lo deja como esta (no lo pone a NULL)
            
        }
            
    }
}
*/

void eliminar(struct nodo **dir_head, int posicion)
{
    if (*dir_head != NULL){
        //eliminar cabeza
        if (posicion == 0){
            struct nodo *temp = *dir_head;
            *dir_head = (*dir_head)->siguiente;
            free(temp);  
        }
        // lo demás
        else{
            struct nodo *anterior = *dir_head;
            struct nodo *cur = (*dir_head)->siguiente;
            int i = 1;
            while ((cur != NULL) && (anterior == NULL || cur == NULL || i != posicion)){
                anterior = cur;
                cur = cur->siguiente;
                i++;
            }
            if (cur == NULL)
                return;
            else{
                anterior->siguiente = cur->siguiente;
                free(cur);
            }
        }
    }
}

void concatenar(struct nodo **dir_head1, struct nodo *head2)
{
    if (*dir_head1 == NULL){
        *dir_head1 = head2;
        return;
    }
    else{
        struct nodo *cur = *dir_head1;
        while (cur->siguiente != NULL)
            cur = cur->siguiente;
        cur->siguiente = head2;
        
    }
}

void agregar(struct nodo **dir_head, int numero, int posicion)
{
    struct nodo *nuevo = malloc(sizeof(struct nodo));
    nuevo->numero = numero;
    nuevo->siguiente = NULL;
    //agregar a cabeza
    if (posicion == 0){
        nuevo->siguiente = *dir_head;
        *dir_head = nuevo;
    }
    else{
        struct nodo *anterior = *dir_head;
        struct nodo *cur = (*dir_head)->siguiente;
        for(int i = 1; i != posicion; anterior = cur, cur = cur->siguiente, i++)
            ;
        anterior->siguiente = nuevo;
        nuevo->siguiente = cur;
    }
    
}
