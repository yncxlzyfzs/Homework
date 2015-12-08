#ifndef _Stack_H
#define _Stack_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int Status;
#define TRUE 1
#define FALSE 0
#define ABNORMAL -1

#define MAX_LEN 20
#define MAX_EXP_LEN 30

struct Node;

typedef float Elemtype;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;

/*
（1）InitStack
    操作结果：构造一个空栈S。 
*/
Status InitStack (Stack *s);

/*
（2）DestroyStack
    初始条件：栈S存在。
    操作结果：栈S被销毁，不在存在。 
*/
Status DestroyStack (Stack *s);

/*
（3）ClearStack
    初始条件：栈S存在。
    操作结果：将S清成空栈。 
*/
Status ClearStack (Stack s);

/*
（4）StackEmpty
    初始条件：栈S存在。
    操作结果：若S为空栈,则返回值为TRUE；否则为FALSE。
*/
Status StackEmpty (Stack s);

/*
（5）StackLength
    初始条件：栈S存在。
    操作结果：返回栈S的元素个数。
*/
int StackLength (Stack s);

/*
（6）GetTop
    初始条件：栈S存在并且非空。
    操作结果：将栈顶元素拷贝到e。
*/
Status GetTop (Stack s, Elemtype *e);

/*
（7）Push
    初始条件：栈S存在。
    操作结果：插入元素e为新的栈顶元素。
*/
Status Push (Stack s, Elemtype e);

/*
（8）Pop
    初始条件：栈S存在并且非空。
    操作结果：删除栈S的栈顶元素，并送入e。
*/
Status Pop (Stack s, Elemtype *e);

/*
（9）StackTraversal
    初始条件：栈S存在。
    操作结果：从栈底到栈顶依次对栈S中的元素使用函数visit进行访问。（visit() 简化为输出）
*/
Status StackTraversal (Stack s);

#endif
