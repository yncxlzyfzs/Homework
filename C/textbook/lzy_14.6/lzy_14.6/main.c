//
//  main.c
//  lzy_14.6
//
//  Created by 赖志懿 on 15/6/9.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct infinity_string{
    char c;
    struct infinity_string *next;
};

void create_inf_string(struct infinity_string **headp);                             //创建字符串函数
struct infinity_string *delete_node(struct infinity_string **headp,char c);         //删除字符
void add_node(struct infinity_string **headp,char c);                               //添加字符



int main(void) {
    
    struct infinity_string *head=NULL,*p;
    
    
    printf("Please input a string end with 'Enter': \n");                                            //输入字符串
    create_inf_string(&head);
    
    
    printf("Please input one more character: ");
    char c;
    scanf("%c",&c);
    if (!delete_node(&head, c))
        add_node(&head, c);
        
    
    p=head;                                                                         //遍历输出
    while (p) {
        printf("%c",p->c);
        p = p->next;
    }
    printf("\n");
    
    
    return 0;
}

void create_inf_string(struct infinity_string **headp){
    struct infinity_string *loc_head=NULL,*tail;
    char c;
    if ((c=getchar()) == '\n');
    else{
        loc_head = (struct infinity_string *)malloc(sizeof(struct infinity_string));
        loc_head->c = c;
        tail = loc_head;
        while ((c=getchar())!='\n') {
            tail->next = (struct infinity_string *)malloc(sizeof(struct infinity_string));
            tail = tail->next;
            tail->c = c;
        }
        tail->next = NULL;
    }
    *headp = loc_head;
}


struct infinity_string *delete_node(struct infinity_string **headp,char c){
    struct infinity_string *current = *headp,*prior = *headp;
    while (current->c != c) {
        prior = current;
        current = current->next;
        if (!current) break;
    }
    if (!current)
        return NULL;
    if (current == *headp)
        *headp = current->next;
    else
        prior->next = current->next;
    free(current);
    return current;
}

void add_node(struct infinity_string **headp,char c){
    struct infinity_string *current = *headp,*least = *headp,*node = NULL;
    node = (struct infinity_string *)malloc(sizeof(struct infinity_string));
    node->c = c;
    node->next = NULL;
    
    unsigned a = abs(current->c - c);
    while (current) {
        if (abs(current->c - c) < a){
            a = abs(current->c - c);
            least = current;
        }
        current = current->next;
    }
    
    node->next = least->next;
    least->next = node;
}