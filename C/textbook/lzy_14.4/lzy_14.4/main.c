//
//  main.c
//  lzy_14.4
//
//  Created by 赖志懿 on 15/6/8.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct infinity_string{
    char c;
    struct infinity_string *next;
};

void create_inf_string(struct infinity_string **headp);                             //创建字符串函数

int main(void) {
    
    struct infinity_string *head=NULL,*p;
    
    
    printf("Please input a string: \n");                                            //输入字符串
    create_inf_string(&head);
    
    
    printf("(1)\n");                                                                //(1)遍历输出
    p=head;
    while (p) {
        printf("%c",p->c);
        p = p->next;
    }
    printf("\n");
    
    
    printf("(2)\n");                                                                //(2)存放到数组中并输出
    
    int sum = 0;                                                                    //获取字符串长度
    p = head;
    while (p) {
        sum++;
        p = p->next;
    }
    
    char *s = (char *)malloc(sum*sizeof(char)+1);                                   //通过动态存储分配创建的字符数组
    int i = 0;
    p = head;
    while (p) {
        s[i++] = p->c;
        p = p->next;
    }
    s[i] = '\0';
    
    puts(s);                                                                        //输出字符串
    
    
    return 0;
}

void create_inf_string(struct infinity_string **headp){
    struct infinity_string *loc_head=NULL,*tail;
    char c;
    if ((c=getchar()) == EOF);
    else{
        loc_head = (struct infinity_string *)malloc(sizeof(struct infinity_string));
        loc_head->c = c;
        tail = loc_head;
        while ((c=getchar())!=EOF) {
            tail->next = (struct infinity_string *)malloc(sizeof(struct infinity_string));
            tail = tail->next;
            tail->c = c;
        }
        tail->next = NULL;
    }
    *headp = loc_head;
}