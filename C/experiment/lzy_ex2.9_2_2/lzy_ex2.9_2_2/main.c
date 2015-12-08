//
//  main.c
//  lzy_ex2.9_2_2
//
//  Created by 赖志懿 on 15/6/11.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
struct s_list{
    int data;
    struct s_list *next;                /*指针域*/
};

void create_list(struct s_list **headp,int *p);

int main(void) {
    struct s_list *head=NULL,*p;
    int s[]={1,2,3,4,5,6,7,8,0};        /*0 为结束标记*/
    create_list(&head,s);                /*创建新链表*/
    p=head;                             /*遍历指针 p 指向链头*/
    while (p) {
        printf("%d\t",p->data);         /*输出数据域的值*/
        p=p->next;                      /*遍历指针 p 指向下一个结点*/
    }
    printf("\n");
    return 0;
}

void create_list(struct s_list ** headp,int *p){
    struct s_list *loc_head=NULL,* tail,* prior;
    if (p[0]==0);
    else{
        loc_head = (struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data=*p++;                                            //赋值
        loc_head->next=NULL;
        prior = loc_head;                                               //prior是指向前一个进入的结点的指针
        while (*p) {
            tail = (struct s_list *)malloc(sizeof(struct s_list));
            tail->next = prior;
            tail->data=*p++;
            prior = tail;
        }
    }
    *headp=tail;                                                        //将最后进入的结点地址赋值给指向head的指针
}