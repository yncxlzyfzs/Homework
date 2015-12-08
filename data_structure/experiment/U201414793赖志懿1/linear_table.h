#ifndef _List_H
#define _List_H

#define LIST_SIZE 20
#define MAX_LIST 20
#define NAME_LEN 20
#define MAX_DATA 10000
#define MEANINGLESS -MAX_DATA-1

typedef int Elemtype;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef struct Multi *PtrToMulti;
typedef PtrToMulti Table;

typedef int Status;
#define TRUE 1
#define FALSE 0
#define ABNORMAL -1

struct Node
{
    Elemtype elems[LIST_SIZE];
    char name[NAME_LEN];
    int length;
};

struct Multi
{
    List lists[MAX_LIST];
    int length;
};

/*
   (1）InitaList(&L)
   操作结果：构造一个空的线性表。
 */

Status InitaList (List *lp, char name[NAME_LEN]);

/*
   （2）DestroyList(&L)
   初始条件：线性表L已存在。
   操作结果：销毁线性表L。
 */

Status DestroyList (List *lp);

/*
   （3）ClearList (&L)
   初始条件：线性表L已存在。
   操作结果：将L重置为空表。
 */

Status ClearList (List l);

/*
   （4）ListEmpty(L)
   初始条件：线性表L已存在。
   操作结果：若L为空表，则返回TRUE,否则返回FALSE。
 */

Status ListEmpty (List l);

/*
   （5）ListLength(L)
   初始条件：线性表已存在。
   操作结果：返回L中数据元素的个数。
 */

int ListLength (List l);

/*
   （6）GetElem(L, i,&e)
   初始条件：线性表已存在，1≤i≤ListLength(L)。
   操作结果：用e返回L中第i个数据元素的值。
 */

Status GetElem (List l, int i, Elemtype *e);

/*
   （7）LocateElem(L, e，compare（）)
   初始条件：线性表已存在。
   操作结果：返回L中第1个与e满足关系compare（）关系的数据元素的
   位序，若这样的数据元素不存在，则返回值为0。(简化compare()为直接输出元素位序)
 */

int LocateElem (List l, Elemtype e);

/*
   （8）PriorElem（L，cur_e，&pre_e）
   初始条件：线性表L已存在。
   操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的
   前驱，否则操作失败，pre_e无定义。
 */

Status PriorElem (List l, Elemtype cur_e, Elemtype *pre_e);

/*
   （9）NextElem（L，cur_e，&next_e）
   初始条件：线性表L已存在。
   操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它
   的后继，否则操作失败，next_e无定义。
 */

Status NextElem (List l, Elemtype cur_e, Elemtype *next_e);

/*
   （10）ListInsert(&L,i,e)
   初始条件：线性表L已存在且非空，1≤i≤ListLength(L)+1。
   操作结果：在L的第i个位置之前插入新的数据元素e，L的长度加1
 */

Status ListInsert (List l, int i, Elemtype e);

/*
   （11）ListDelete(&L,i,&e)
   初始条件：线性表L已存在且非空，1≤i≤ListLength(L)。
   操作结果：删除L的第i个数据元素，用e返回其值，L的长度减1.
 */

Status ListDelete (List l, int i, Elemtype *e);

/*
   （12）ListTraversal(L，visit（）)
   初始条件：线性表L已存在。
   操作结果：依次对L的每个数据元素调用函数visit()。一旦调用失败，则操
   作失败。(简化visit()为输出数据数值)
 */

Status ListTraversal (List l);

#endif
