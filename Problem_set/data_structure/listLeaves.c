#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct queue
{
    int queue[MAX_SIZE];
    int top, bottom;
}Queue;

Queue *createQueue ()
{
    Queue *queue;
    queue = (Queue *) malloc (sizeof (Queue));
    queue->top = queue->bottom = -1;

    return queue;
}

int isEmpty (Queue *queue)
{
    return !(queue->top == queue->bottom);
}

void enQueue (Queue *queue, int ele)
{
    queue->queue[++queue->top] = ele;
}

int deQueue (Queue *queue)
{
    if (!isEmpty (queue)) return 0;

    int ele;
    ele = queue->queue[++queue->bottom];

    return ele;
}

int main (int argc, char *argv[])
{
    int list[MAX_SIZE][2];
    int i, j, n;
    char tmp;
    scanf ("%d", &n);

    //initialize data
    for (i=0; i<n; i++)
    {
        for (j=0; j<2; j++)
        {
            scanf (" %c", &tmp);

            if (tmp == '-')
                list[i][j] = -1;
            else
                list[i][j] = tmp - '0';
        }
    }

    //find root
    int test [n],test_num;
    for (i=0; i<n; i++)
        test[i] = 1;
    for (i=0; i<n; i++)
    {
        for (j=0; j<2; j++)
        {
            test_num = list[i][j];
            if (test_num != -1) test[test_num] = 0;
        }
    }

    int root = -1;
    for (i=0; i<n; i++)
    {
        if (test[i])
        {
            root = i;
            break;
        }
    }

    if (root == -1) return 1;

    //find leaves
    Queue *queue;
    queue = createQueue ();
    enQueue (queue, root);

    int ele, mark;
    mark = 0;
    while (isEmpty (queue))
    {
        ele = deQueue (queue);
        if (list[ele][0] == -1 && list[ele][1] == -1)
        {
            if (!mark)
            {
                printf ("%d", ele);
                mark = 1;
            }
            else printf (" %d", ele);

            continue;
        }

        for (i=0; i<2; i++)
            if (list[ele][i] != -1) enQueue (queue, list[ele][i]);
    }

    printf ("\n");

    return 0;
}
