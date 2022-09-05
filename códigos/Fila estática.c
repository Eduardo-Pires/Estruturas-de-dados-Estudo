#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 5

typedef struct
{
    char front;
    char back;
    char elements[MAX];
    int numElem;
} Queue;

Queue *createQueue()
{
    Queue *queue;
    queue = (Queue*)malloc(sizeof(Queue));

    if(queue != NULL)
    {
        queue->numElem = -1;
    }

    return queue;
}

void eliminate(Queue *queue)
{
    if(queue != NULL && queue->numElem >= 0)
    {
        free(queue);
    }
}

bool isEmpty(Queue *queue)
{
    if(queue->numElem <= -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isFull(Queue *queue)
{
    if(queue->numElem >= MAX)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void enqueue(Queue *queue, char elem, bool *ok)
{
    if(isFull(queue))
    {
        *ok = false;
    }
    else
    {
        *ok = true;

        queue->numElem = queue->numElem + 1;
        queue->elements[queue->numElem] = elem;

        if(queue->numElem == 0)
        {
            queue->front = queue->elements[0];
        }
        queue->back = queue->elements[queue->numElem];
    }
}

void dequeue(Queue *queue, char *elem, bool *ok)
{
    if(isEmpty(queue))
    {
        *ok = false;
    }
    else
    {
       queue->numElem = queue->numElem - 1;
       queue->back = queue->elements[queue->numElem];




    }
}

void showAll(Queue *queue)
{
    int i = 0;
    while(i <= queue->numElem)
    {
        printf("%c ", queue->elements[i]);
        i++;
    }
    printf("\n");
}


int main()
{
    bool ok;
    char elem;
    Queue *fila;
    fila = createQueue();

    enqueue(fila, 'a', &ok);
    enqueue(fila, 'b', &ok);
    enqueue(fila, 'c', &ok);
    enqueue(fila, 'd', &ok);

    printf("%c\n", fila->front);
    printf("%c\n", fila->back);
    showAll(fila);

    dequeue(fila, &elem, &ok);
    printf("%c\n", fila->front);
    printf("%c\n", fila->back);

    showAll(fila);



    return 0;
}
