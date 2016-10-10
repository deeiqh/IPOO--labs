#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct tnode{
    char *word;              // points to the text
    int count;               // number of occurrences
    struct tnode *left;      // left child
    struct tnode *right;     // right child
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
struct tnode *talloc(void);
char *strdup2(char *);
struct tnode *balancear_arbol(struct tnode *);
struct tnode *arbol_a_lista(struct tnode*, struct tnode**);
int cantidad_nodos(struct tnode *);
struct tnode* lista_a_arbol(struct tnode**, int );
void pre_orden(struct tnode*);

/* word frequency count*/
int main(void){
    struct tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
        root = addtree(root, word);
    treeprint(root);
    
    pre_orden(root);
    root = balancear_arbol(root);
    printf("\n");
    pre_orden(root);
    
    return 0;
}

struct tnode *balancear_arbol(struct tnode * root)
{
    struct tnode *cabeza = NULL; //cabeza de lista
    arbol_a_lista(root, &cabeza);
    int n = cantidad_nodos(cabeza);
    return lista_a_arbol(&cabeza,n);
}

struct tnode *arbol_a_lista(struct tnode* root, struct tnode** cabeza_dir)
{
    if (root == NULL)
        return NULL;
    arbol_a_lista(root->right, cabeza_dir);
    root->right = *cabeza_dir;
    if(*cabeza_dir != NULL)
        (*cabeza_dir)->left = root;
    *cabeza_dir = root;
    arbol_a_lista(root->left,cabeza_dir);
}

int cantidad_nodos(struct tnode * cabeza)
{
    int cant = 0;
    while (cabeza)
    {
        cabeza = cabeza->right;
        cant++; 
    }
    return cant;
}

struct tnode* lista_a_arbol(struct tnode** cabeza_dir, int n)
{
    if (n<=0)
        return NULL;
    struct tnode* left = lista_a_arbol(cabeza_dir, n/2);
    struct tnode* root = *cabeza_dir;
    root->left = left;
    *cabeza_dir = (*cabeza_dir)-> right;
    root->right = lista_a_arbol(cabeza_dir, n-n/2-1);
    return root;
}

void pre_orden(struct tnode* root)
{
    if (root == NULL)
        return;
    printf("%s ", root->word);
    pre_orden(root->left);
    pre_orden(root->right);
}

/* addtree: add a node with 2, at or below p */
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond;

    if (p == NULL){               // a new word has arrive
        p = talloc();            // make a new node
        p->word = strdup2(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;               // repeated word
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

/* treeprint: in-order print of tree p */
void treeprint(struct tnode *p){
    if (p != NULL){
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

#include <stdlib.h>
/* talloc: make a tnode */
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

char *strdup2(char *s)    // make a duplicate of s
{
    char *p;

    p = (char *) malloc(strlen(s)+1);   // +1 for '\0'
    if (p != NULL)
        strcpy(p, s);
    return p;
}

/* getword: get next word or character from input */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)){
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())){
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

#define BUFFSIZE 100

char buf[BUFFSIZE];  // buffer for ungetch
int bufp = 0;        // next free posotion in buf

int getch(void)      // get a (possibly pushed back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  // push back on input
{
    if (bufp >= BUFFSIZE)
        printf("ungetch: too many characters\n");
    else buf[bufp++] = c;
}
