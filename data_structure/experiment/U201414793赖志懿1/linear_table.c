#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linear_table.h"

Status InitaList (List *lp, char name[NAME_LEN])
{
    *lp = (List) malloc (sizeof (struct Node));
    if (*lp)
    {
        (*lp)->length = 0;
        strcpy ((*lp)->name, name);
        ClearList (*lp);
        return TRUE;
    }else
    {
        return ABNORMAL;
    }
}

Status DestroyList (List *lp)
{
    if (*lp == NULL) return ABNORMAL;
    else
    {
        free (*lp);
        *lp = NULL; 
        return TRUE;
    }
}

Status ClearList (List l)
{
    if (!l) return ABNORMAL;
    l->length = 0;
    return TRUE;
}

Status ListEmpty (List l)
{
    if (!l) return ABNORMAL;
    else if (l->length)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

int ListLength (List l)
{
    if (!l) return ABNORMAL;

    return l->length;
}

Status GetElem (List l, int i, Elemtype *e)
{
    if (!l) return ABNORMAL;
    if (i<1 || i>l->length)
        return FALSE;
    *e = l->elems[i-1];
    return TRUE;
}

int LocateElem (List l, Elemtype e)
{
    if (!l) return ABNORMAL;
    int i=1, pos=0;
    while (i<=l->length && l->elems[i-1] != e) i++;

    if (i<=l->length) pos = i;

    return pos;
}

Status PriorElem (List l, Elemtype cur_e, Elemtype *pre_e)
{
    if (!l) return ABNORMAL;
    int loc;
    loc = LocateElem (l, cur_e);
    if (loc && loc != 1)
    {
        *pre_e = l->elems[loc-2];
    }
    else
    {
        *pre_e = MEANINGLESS;
    }
    return TRUE;
}

Status NextElem (List l, Elemtype cur_e, Elemtype *next_e)
{
    if (!l) return ABNORMAL;
    int loc;
    loc = LocateElem (l, cur_e);
    if (loc && loc != l->length)
    {
        *next_e = l->elems[loc];
    }
    else
    {
        *next_e = MEANINGLESS;
    }
    return TRUE;
}

Status ListInsert (List l, int i, Elemtype e)
{
    if (!l) return ABNORMAL;
    if (l->length == LIST_SIZE || i>l->length+1 || i < 1 || e> MAX_DATA || e <-MAX_DATA)
    {
        return FALSE;
    }
    else
    {
        int m;
        for (m = l->length; m>=i; m--)
            l->elems[m] = l->elems[m-1];
        l->elems[m] = e;
        l->length++;

        return TRUE;
    }
}

Status ListDelete (List l, int i, Elemtype *e)
{
    if (!l) return ABNORMAL;
    if (l->length == 0 || i > l->length || i < 1)
    {
        *e = MEANINGLESS;
    }
    else
    {
        *e = l->elems[i-1];

        int m;
        for (m = i-1;m<l->length; m++)
            l->elems[m] = l->elems[m+1];
        l->length--;
    }
    return TRUE;
}

Status ListTraversal (List l)
{
    if (!l) return ABNORMAL;
    int i;
    printf("-------------------------------------------------\n");
    printf ("\n%s: \n\n", l->name);
    for (i=0; i<l->length; i++)
        printf ("%d: %d\n", i+1, l->elems[i]);
    printf("-------------------------------------------------\n");
    return TRUE;
}
