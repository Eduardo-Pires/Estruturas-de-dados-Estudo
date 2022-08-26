#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

/*              PILHA ESTÁTICA
 * Uma estrutura de dados com tamanho préfixado
 * Segue o princípio FILO (First In Last Out)
 */

 //Struct
 typedef struct
 {
     char top;
     char elem[MAX];
     int numElem;
 }Stack;

 //Operações
Stack CreateStack();
bool isFull(Stack *stk);
bool isEmpty(Stack *stk);
void push(Stack *stk, char elem, bool *ok);
void pop(Stack *stk, char *elem, bool *ok);
void showAll(Stack *stk);
void showTop(Stack *stk);
void obliterate(Stack *stk);

 //Funções
Stack *createStack()
{
    Stack *stk;
    stk = (Stack *)malloc(sizeof(Stack));

    if(stk != NULL)
    {
        stk->numElem = -1;
    }

    return stk;
}

bool isFull(Stack *stk)
{
    if(stk->numElem == MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty(Stack *stk)
{
    if(stk->numElem == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void push(Stack *stk, char elem, bool *ok)
{
    if(isFull(stk))
    {
        *ok = false;
    }
    else
    {
        *ok = true;
        stk->top = elem;
        stk->numElem = stk->numElem + 1;
        stk->elem[stk->numElem] = elem;
    }
}

void pop(Stack *stk, char *elem, bool *ok)
{
    if(isEmpty(stk))
    {
        *ok = false;
    }
    else
    {
        *ok = true;
        *elem = stk->elem[stk->numElem];
        stk->numElem = stk->numElem - 1;
        stk->top = stk->elem[stk->numElem];
    }
}

void obliterate(Stack *stk)
{
    if(stk!= NULL)
    {
        free(stk);
    }
}

void showAll(Stack *stk)
{
    int elem = 0;
    while(elem != stk->numElem+1)
    {
        printf("%c ", stk->elem[elem]);
        elem++;
    }
    printf("\n");
}

void showTop(Stack *stk)
{
    printf("%c\n", stk->top);
}


int main()
{
    bool ok;
    char retirado;

    Stack *pilha;
    pilha = createStack();

    push(pilha, 'a', &ok);
    push(pilha, 'b', &ok);
    push(pilha, 'c', &ok);
    printf("push 3 elements: ");
    showAll(pilha);

    pop(pilha, &retirado, &ok);
    printf("pop 1 element: ");
    showAll(pilha);

    push(pilha, 'd', &ok);
    printf("push 1 element: ");
    showAll(pilha);

    printf("top of the list: ");
    showTop(pilha);

    obliterate(pilha);

return 0;

}
