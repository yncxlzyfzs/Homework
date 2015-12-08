#include "stack.h"

struct Node
{
    Elemtype data[MAX_LEN];
    int length;
};

Status InitStack (Stack *s)
{
    if (*s) free (*s);
    *s = (Stack) malloc (sizeof (struct Node));
    if (!(*s)) return ABNORMAL;
    ClearStack (*s);
    return TRUE;
}

Status DestroyStack (Stack *s)
{
    if (!(*s)) return ABNORMAL;
    ClearStack (*s);
    free (*s);
    *s = NULL;
    return TRUE;
}

Status ClearStack (Stack s)
{
    if (!s) return ABNORMAL;
    s->length = 0;
    return TRUE;
}

Status StackEmpty (Stack s)
{
    if (!s) return ABNORMAL;
    if (s->length) return FALSE;
    else return TRUE;
}

int StackLength (Stack s)
{
    if (!s) return ABNORMAL;
    return s->length;
}

Status GetTop (Stack s, Elemtype *e)
{
    if (!s) return ABNORMAL;
    if (StackEmpty (s)) return FALSE;
    *e = s->data[s->length-1];
    return TRUE;
}

Status Push (Stack s, Elemtype e)
{
    if (!s) return ABNORMAL;
    if (s->length == MAX_LEN) return FALSE;
    s->data[s->length++] = e;
    return TRUE;
}

Status Pop (Stack s, Elemtype *e)
{
    if (!s) return ABNORMAL;
    if (StackEmpty (s)) return FALSE;
    *e = s->data[--s->length];
    return TRUE;
}

Status StackTraversal (Stack s)
{
    if (!s) return ABNORMAL;
    int i;
    printf("-------------------------------------------------\n");
    printf ("Stack: \n");
    for (i=0; i<s->length; i++)
        printf ("Element %d: %.2f\n", i+1, s->data[i]);
    printf("-------------------------------------------------\n");
    return TRUE;
}
