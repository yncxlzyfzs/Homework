#include "queue.h"

struct Node
{
    Elemtype data[MAX_LEN];
    int head, tail;
    int full;
};

Status InitQueue (Queue *qp)
{
    if (!qp) return ABNORMAL;
    *qp = (Queue) malloc (sizeof (struct Node));
    if (*qp) return TRUE;
    else return FALSE;
}

Status DestroyQueue (Queue *qp)
{
    if (!qp) return ABNORMAL;
    if (!*qp) return FALSE;
    free (*qp);
    *qp = NULL;
    return TRUE;
}

Status ClearQueue (Queue q)
{
    if (!q) return ABNORMAL;
    q->head = q->tail = 0;
    q->full = 0;
    return TRUE;
}

Status QueueEmpty (Queue q)
{
    if (!q) return ABNORMAL;
    if (q->head == q->tail && !q->full) return TRUE;
    else return FALSE;
}

int QueueLength (Queue q)
{
    if (!q) return ABNORMAL;
    int status = q->tail - q->head;
    if (status == 0)
    {
        if (q->full) return MAX_LEN;
        else return 0;
    }
    else
    {
        if (status > 0) return status;
        else return MAX_LEN + status;
    }
}

Status GetHead (Queue q, Elemtype *e)
{
    if (!q) return ABNORMAL;
    if (QueueEmpty (q) == TRUE) return FALSE;
    
    *e = q->data[q->head];
    return TRUE;
}

Status EnQueue (Queue q, Elemtype e)
{
    if (!q) return ABNORMAL;
    if (q->full) return FALSE;
    
    q->data[q->tail++] = e;
    q->tail = q->tail % MAX_LEN;
    if (q->tail == q->head) q->full = 1;
    return TRUE;
}

Status DeQueue (Queue q, Elemtype *e)
{
    if (!q) return ABNORMAL;
    if (QueueEmpty (q)) return FALSE;

    q->full = 0;
    *e = q->data[q->head];
    q->head = (q->head + 1) % MAX_LEN;
    return TRUE;
}

Status QueueTraversal (Queue q)
{
    if (!q) return ABNORMAL;
    if (QueueEmpty (q)) return FALSE;
    int i, counter = 0;
    printf("-------------------------------------------------\n");
    printf ("Queue: \n");
    i=q->head;
    do
    {
        printf ("%d: %d\n", ++counter, q->data[i++]);
        i = i % MAX_LEN;
    }while (i != q->tail);
    printf("-------------------------------------------------\n");
    return TRUE;
}
