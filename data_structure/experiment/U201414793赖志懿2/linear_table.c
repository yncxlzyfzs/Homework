#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linear_table.h"

Status InitaList (List *lp, char name[NAME_LEN])
{
    //申请内存空间
    *lp = (List) malloc (sizeof (struct Node));
    //判断内存申请是否成功
    if (*lp)
    {
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
    //判断线性表是否存在
    if (*lp == NULL) return ABNORMAL;
    else
    {
        free (*lp);
        return TRUE;
    }
}

Status ClearList (List l)
{
    Elemtype e;
    //判断线性表是否存在
    if (!l) return ABNORMAL;
    while (!ListEmpty (l))
        ListDelete (l, 1, &e);
    return TRUE;
}

Status ListEmpty (List l)
{
    if (!l) return ABNORMAL;
    else if (l->next)
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

    Position pos;
    int n;

    //获取相应位置
    pos = l;
    for (n=0; n<i; n++)
        pos = pos->next;
    //获取位置数据
    *e = pos->data;
    return TRUE;
}

int LocateElem (List l, Elemtype e)
{
    if (!l) return ABNORMAL;
    int i=1;
    Position pos;
    pos = l->next;;
    while (i<=l->length && pos->data != e)
    {
        pos = pos->next;
        i++;
    }

    //判断数据是否存在
    if (i<=l->length)
        return i;
    else
        return ABNORMAL;
}

Position PriorElem (List l, Elemtype cur_e, Elemtype *pre_e)
{
    if (!l) return NULL;

    Position pos;
    pos = l;
    while (pos->next->next && pos->next->data != cur_e)
        pos = pos->next;

    //cur_e是第一个结点的数据
    if (l == pos)
    {
        *pre_e = MEANINGLESS;
        return NULL;
    }

    if (pos->next->next || pos->next->data == cur_e)
    {
        *pre_e = pos->data;
        return pos;
    }
    else
    {
        *pre_e = MEANINGLESS;
        return NULL;
    }
}

Position NextElem (List l, Elemtype cur_e, Elemtype *next_e)
{
    if (!l) return NULL;

    Position pos;
    pos = l;
    while (pos->next && pos->data != cur_e)
        pos = pos->next;

    if (pos->next && pos->data == cur_e)
    {
        pos = pos->next;
        *next_e = pos->data;
        return pos;
    }
    else
    {
        *next_e = MEANINGLESS;
        return NULL;
    }
}

Status ListInsert (List l, int i, Elemtype e)
{
    if (!l) return ABNORMAL;
    Position pos;
    pos = l;
    while (i>1 && pos)
    {
        pos = pos->next;
        i--;
    }

    if (pos)
    {
        Position tmp_pos;
        tmp_pos = (Position) malloc (sizeof (struct Node));
        tmp_pos->data = e;
        tmp_pos->next = pos->next;
        pos->next = tmp_pos;
        l->length++;
        return TRUE;
    }
    else
        return FALSE;
}

Status ListDelete (List l, int i, Elemtype *e)
{
    if (!l) return ABNORMAL;
    if (ListEmpty (l) || i > l->length || i < 1)
    {
        *e = MEANINGLESS;
        return FALSE;
    }
    else
    {
        GetElem (l, i, e);
        Position pos, tmp_pos;
        pos = l;
        while (i>1)
        {
            pos = pos->next;
            i--;
        }

        tmp_pos = pos->next;
        pos->next = tmp_pos->next;
        free (tmp_pos);
        l->length--;
        return TRUE;
    }
}

Status ListTraversal (List l)
{
    if (!l) return ABNORMAL;
    int i=0;
    printf("-------------------------------------------------\n");
    printf ("\n%s: \n\n", l->name);
    l = l->next;
    while (l)
    {
        printf ("%d: %d\n", ++i, l->data);
        l = l->next;
    }
    printf("-------------------------------------------------\n");
    return TRUE;
}
