//
//  main.c
//  lzy_9.7
//
//  Created by 赖志懿 on 15/6/8.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <string.h>

struct student{
    int num;
    char name[12];
    double score;
};

int main(void) {
    int i;
    struct student s[] = {{1,"a",90.0},{2,"b",85.0},{3,"c",80.0}},*p;//声明、赋初始值
    
    p=s;                                                //(1)
    
    printf("print with s:\n");                          //(2)
    for (i = 0; i < 3; i++) {
        printf("num :%d\n",s[i].num);
        printf("name :%s\n",s[i].name);
        printf("score :%.2f\n",s[i].score);
        printf("\n");
    }
    
    printf("\n");
    
    printf("print with p:\n");                          //(3)
    for (i = 0; i < 3; i++) {
        printf("num :%d\n",(p+i)->num);
        printf("name :%s\n",(p+i)->name);
        printf("score :%.2f\n",(p+i)->score);
        printf("\n");
    }
    
    return 0;
}