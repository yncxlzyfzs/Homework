//
//  main.c
//  lzy_ex2.9_2_1
//
//  Created by 赖志懿 on 15/6/11.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include "stdio.h"
#include "stdlib.h"
struct s_list{
    int data;
    struct s_list *next;                /*指针域*/
};

void create_list(struct s_list **headp,int *p);

int main(void) {
    struct s_list *head=NULL,*p;
    int s[]={1,2,3,4,5,6,7,8,0};        /*0 为结束标记*/
    create_list(&head,s);                /*创建新链表*/                              //(修改)
    p=head;                             /*遍历指针 p 指向链头*/
    while (p) {
        printf("%d\t",p->data);         /*输出数据域的值*/
        p=p->next;                      /*遍历指针 p 指向下一个结点*/
    }
    printf("\n");
    return 0;
}

void create_list(struct s_list ** headp,int *p){
    struct s_list *loc_head=NULL,* tail;
    if (p[0]==0);                       /*相当于 *p == 0*/
    else{
        loc_head = (struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data=*p++;            /*对数据域赋值*/
        tail = loc_head;                /*tail指向第一个结点*/
        while (*p) {                    /*tail所指结点的指针域指向动态创建的结点*/
            tail->next = (struct s_list *)malloc(sizeof(struct s_list));
            tail = tail->next;          /*tail指向新创建的结点*/
            tail->data=*p++;            /*向新建结点的数据域赋值*/
        }
        tail->next=NULL;                /*对指针域赋NULL值*/
    }
    *headp=loc_head;                     /*使头指针 headp 指向新建的链表*/             //(修改)
}