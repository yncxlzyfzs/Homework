//
//  main.c
//  lzy_ex2.9_3_2
//
//  Created by 赖志懿 on 15/6/16.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct students{
    char num[15];
    char name[10];
    float grades[4];
    struct students *next;
};

void add_student(struct students **,int);                                                       //添加学生
void print_information(struct students *);                                                      //输出信息
void alter_information(struct students *,char *);                                               //更改数据
float *average_score(struct students *,int);                                                    //平均成绩
void print_all_information(struct students *);                                                  //输出所有信息




int main(void) {
    struct students *head;
    int n;
    printf("Please input student number: ");
    scanf("%d",&n);
    printf("Please input students' information:(num name grades)\n");
    add_student(&head, n);                                                                      //(1)
    
    printf("\n\n");
    print_information(head);                                                                    //(2)
    
    
    printf("\n\n");
    printf("Please input num of student you want to alter: ");                                  //(3)
    char s[15];
    scanf("%s",s);
    alter_information(head, s);
    print_information(head);
    
    
    printf("\n\n");
    float *average;                                                                             //(4)
    average = average_score(head,n);
    int i;
    struct students *p;
    p=head;
    printf("average_score:\n");
    for (i=0; i<n; i++) {
        printf("%s: %.2f\n",p->name,*(average+i));
        p=p->next;
    }
    
    printf("\n\n");
    printf("All_information:\n");                                                               //(5)
    print_all_information(head);
    
    return 0;
}




void add_student(struct students **headp,int n){
    struct students *loc_head = (struct students*)malloc(sizeof(struct students)),*tail = NULL;
    char num[15],name[10];
    int i,grades[4];
    
    scanf("%s %s %d %d %d %d",num,name,&grades[0],&grades[1],&grades[2],&grades[3]);
    for (i=0;i<15;i++)
        loc_head->num[i] = num[i];
    for (i=0;i<10;i++)
        loc_head->name[i] = name[i];
    for (i=0;i<4;i++)
        loc_head->grades[i] = grades[i];
    loc_head->next = NULL;
    tail = loc_head;
    
    for (i=1; i<n; i++) {
        tail->next = (struct students*)malloc(sizeof(struct students));
        tail = tail->next;
        
        scanf("%s %s %d %d %d %d",num,name,&grades[0],&grades[1],&grades[2],&grades[3]);
        int j;
        for (j=0;j<15;j++)
            tail->num[j] = num[j];
        for (j=0;j<10;j++)
            tail->name[j] = name[j];
        for (j=0;j<4;j++)
            tail->grades[j] = grades[j];
    }
    
    *headp = loc_head;
}

void print_information(struct students *head){
    struct students *current = head;
    int i=0;
    while (current) {
        printf("<%d>\nnum: %s\nname: %s\nscore:\n\tEnglish: %.2f\n\tMath: %.2f\n\tPhysics: %.2f\n\tC_Programing: %.2f\n",
               ++i,current->num,current->name,current->grades[0],current->grades[1],current->grades[2],current->grades[3]);
        current = current->next;
    }
}

void alter_information(struct students *head,char *num){
    struct students *current;
    current = head;
    char s[15];
    while (current) {
        if (strcmp(current->num,num) == 0) {                                                //判断更改数据的类型
            printf("Please input item_name and data: ");
            scanf("%s",s);
            if (strcmp("num", s) == 0)
                scanf("%s",current->num);
            else if (strcmp("name", s) == 0)
                scanf("%s",current->name);
            else if (strcmp("English", s) == 0)
                scanf("%f",&current->grades[0]);
            else if (strcmp("Math", s) == 0)
                scanf("%f",&current->grades[1]);
            else if (strcmp("Physics", s) == 0)
                scanf("%f",&current->grades[2]);
            else if (strcmp("C_Programing", s) == 0)
                scanf("%f",&current->grades[3]);
            else
                printf("Input Error!");
            
            return;
        }
        current = current->next;
    }
}

float *average_score(struct students *head,int n){
    struct students *current;
    current = head;
    float *average = (float *)malloc(n*sizeof(float));
    int i=0;
    while (current) {
        *(average+i++)=(current->grades[0]+current->grades[1]+current->grades[2]+current->grades[3])/4;
        current = current->next;
    }
    
    return average;
}

void print_all_information(struct students *head){
    struct students *current = head;
    int i=0;
    while (current) {
        printf("<%d>\nnum: %s\nname: %s\nall_score: %.2f\naverage_score: %.2f\n",
               ++i,current->num,current->name,(current->grades[0]+current->grades[1]+current->grades[2]+current->grades[3]),
               (current->grades[0]+current->grades[1]+current->grades[2]+current->grades[3])/4);
        current = current->next;
    }
}