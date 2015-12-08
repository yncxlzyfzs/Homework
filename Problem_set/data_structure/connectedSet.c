#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int visited;
    struct node *last;
    struct node *next;
}Node;

typedef struct queue
{
    Node *first;
    Node *last;
}Queue;

//stack func.
void enStack (Node *stack, int data)
{
    Node *newNode = (Node *) malloc (sizeof (Node));
    newNode->data = data;
    newNode->next = stack->next;
    stack->next = newNode;
}

Node *pop (Node **table, Node *stack)
{
    if (stack->next == NULL) return NULL;
    Node *tmpNode;
    int result;
    result = stack->next->data;
    tmpNode = stack->next;
    stack->next = tmpNode->next;
    free (tmpNode);
    return table [result];
}

//queue func.
void enQueue (Queue *queue, int data)
{
    Node *newNode;
    newNode = (Node *) malloc (sizeof (Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->first == NULL) queue->first = queue->last = newNode;
    else
    {
        queue->last->next = newNode;
        queue->last = newNode;
    }
}

Node *deQueue (Node **table, Queue *queue)
{
    if (queue->first == NULL) return NULL;
    
    Node *tmpNode;
    int result;
    result = queue->first->data;
    tmpNode = queue->first;
    queue->first = tmpNode->next;
    if (queue->first == NULL) queue->last = NULL;
    return table [result];
}


Node *DSearch (Node **table, int i)
{
    Node *dataList, *stack, *tmpNode;
    dataList = (Node *) malloc (sizeof (Node));
    dataList->next = NULL;
    dataList->last = dataList;
    stack = (Node *) malloc (sizeof (Node));
    stack->next = NULL;
    enStack (stack, i);
    while (stack->next)
    {
        tmpNode = pop (table, stack);
        if (tmpNode->visited) continue;
        tmpNode->visited = 1;
        dataList->last->next = (Node *) malloc (sizeof (Node));
        dataList->last = dataList->last->next;
        dataList->last->data = tmpNode->data;
        dataList->last->next = NULL;

        //insure ascending sequence。
        Node *revStack;
        revStack = (Node *) malloc (sizeof (Node));
        revStack->next = NULL;

        while (tmpNode->next)
        {
            tmpNode = tmpNode->next;
            enStack (revStack, tmpNode->data);
        }

        tmpNode = pop (table, revStack);

        while (tmpNode)
        {
            if (!tmpNode->visited)
            {
                enStack (stack, tmpNode->data);
            }
            tmpNode = pop (table, revStack);
        }
    }
    tmpNode = dataList;
    dataList = dataList->next;
    free (tmpNode);

    return dataList;
}

void DFS (Node **table, int n)
{
    int i;
    Node *dataList, *tmpNode;
    for (i=0; i<n; i++)
    {
        if (!table[i]->visited)
        {
            dataList = DSearch (table, i);
            printf ("{ ");
            while (dataList)
            {
                printf ("%d ", dataList->data);
                tmpNode = dataList;
                dataList = dataList->next;
                free (tmpNode);
            }
            printf ("}\n");
        }
    }
}

Node *BSearch (Node **table, int i)
{
    Node *dataList, *tmpNode;
    dataList = (Node *) malloc (sizeof (Node));
    dataList->next = NULL;
    dataList->last = dataList;
    Queue *queue;
    queue = (Queue *) malloc (sizeof (Queue));
    queue->first = queue->last = NULL;
    enQueue (queue, i);
    table [i]->visited = 1;
    while (queue->first)
    {
        tmpNode = deQueue (table, queue);
        dataList->last->next = (Node *) malloc (sizeof (Node));
        dataList->last = dataList->last->next;
        dataList->last->data = tmpNode->data;
        dataList->last->next = NULL;
        tmpNode = tmpNode->next;
        while (tmpNode)
        {
            if (!table [tmpNode->data]->visited)
            {
                enQueue (queue, tmpNode->data);
                table [tmpNode->data]->visited = 1;
            }
            tmpNode = tmpNode->next;
        }
    }
    tmpNode = dataList;
    dataList = dataList->next;
    free (tmpNode);

    return dataList;
}

void BFS (Node **table, int n)
{
    int i;
    Node *dataList, *tmpNode;
    for (i=0; i<n; i++)
    {
        if (!table[i]->visited)
        {
            dataList = BSearch (table, i);
            printf ("{ ");
            while (dataList)
            {
                printf ("%d ", dataList->data);
                tmpNode = dataList;
                dataList = dataList->next;
                free (tmpNode);
            }
            printf ("}\n");
        }
    }
}

int main(int argc, char *argv[])
{
    int n,e;
    scanf ("%d %d", &n, &e);

    //create linked table.
    int i;
    Node *table[n];
    Node *newNode;
    for (i=0; i<n; i++)
    {
        newNode = (Node *) malloc (sizeof (Node));
        newNode->data = i;
        newNode->visited = 0;
        newNode->last = newNode;
        newNode->next = NULL;
        table[i] = newNode;
    }

    int first, second;
    Node *tmpNode;
    for (i=0; i<e; i++)
    {
        scanf (" %d %d", &first, &second);
        tmpNode = table[first];
        newNode = (Node *) malloc (sizeof (Node));
        newNode->data = second;
        newNode->visited = 0;
        while (tmpNode->next && tmpNode->next->data < second) tmpNode = tmpNode->next;
        newNode->next = tmpNode->next;
        tmpNode->next = newNode;

        tmpNode = table[second];
        newNode = (Node *) malloc (sizeof (Node));
        newNode->data = first;
        newNode->visited = 0;
        while (tmpNode->next && tmpNode->next->data < first) tmpNode = tmpNode->next;
        newNode->next = tmpNode->next;
        tmpNode->next = newNode;
    }

    DFS (table, n);

    for (i=0; i<n; i++) table [i]->visited = 0;

    BFS (table, n);

    return 0;
}
