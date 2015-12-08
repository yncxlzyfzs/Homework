#ifndef _Queue_H
#define _Queue_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Status;
#define TRUE 1
#define FALSE 0
#define ABNORMAL -1

#define MAX_LEN 5

struct Node;

typedef int Elemtype;
typedef struct Node *PtrToNode;
typedef PtrToNode Queue;

/*
（1）InitQueue
    操作结果：构造一个空队列Q。 
*/
Status InitQueue (Queue *qp);

/*
（2） DestroyQueue
    初始条件：队列Q存在。
    操作结果：将队列Q销毁，不再存在。 
*/
Status DestroyQueue (Queue *qp);

/*
（3）ClearQueue
    初始条件：队列Q存在。
    操作结果：将队列Q清为空队列。 
*/
Status ClearQueue (Queue q);

/*
（4）QueueEmpty
    初始条件：队列Q存在。
    操作结果：若队列Q为空队列，返回TRUE，否则返回FALSE。 
*/
Status QueueEmpty (Queue q);

/*
（5）QueueLength
    初始条件：队列Q存在。
    操作结果：返回队列元素个数。 
*/
int QueueLength (Queue q);

/*
（6）GetHead
    初始条件：队列Q存在并且非空。
    操作结果：读取队列Q的首元素,送e返回其值。
*/
Status GetHead (Queue q, Elemtype *e);

/*
（7）EnQueue
    初始条件：队列Q存在。
    操作结果：插入元素e到队列Q中作为尾元素。 
*/
Status EnQueue (Queue q, Elemtype e);

/*
（8）DeQueue
    初始条件：队列Q存在并且非空。
    操作结果：删除队列Q的首元素,并且用e返回其值。 
*/
Status DeQueue (Queue q, Elemtype *e);

/*
（9）QueueTraversal
    初始条件：队列Q存在并且非空。
    操作结果：从队首到队尾依次对队列中的元素使用函数visit进行访问。(visit ()函数简化为输出数据)
*/
Status QueueTraversal (Queue q);

#endif
