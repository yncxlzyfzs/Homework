//
//  main.c
//  lzy_ex2.9_4_1
//
//  Created by 赖志懿 on 15/6/17.
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
float *average_score(struct students *,int);                                                    //平均成绩
void sort(struct students *);                                                                   //升序排序



int main(void) {
    struct students *head;
    int n;
    printf("Please input student number: ");
    scanf("%d",&n);
    printf("Please input students' information:(num name grades)\n");
    add_student(&head, n);                                                                      //添加数据
    
    sort(head);                                                                                 //排序
    print_information(head);                                                                    //输出
    
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

void sort(struct students * head){
    struct students *current,*prior;
    prior = current = head;
    int n=0,i,j,k;
    
    
    
    while (current) {                                                                           //统计结点数
        n++;
        current = current->next;
        
    }
    
    for (i=0; i<n-1; i++,prior=prior->next) {
        for (j=i+1,current=prior->next; current; current=current->next,j++) {                   //交换数据域
            float *average;                                                                     //计算平均成绩
            average = average_score(head,n);
            if (average[i] < average[j]) {
                char num[15];
                char name[10];
                float grades[4];
                for (k=0;k<15;k++)
                    num[k] = prior->num[k];
                for (k=0;k<10;k++)
                    name[k] = prior->name[k];
                for (k=0;k<4;k++)
                    grades[k] = prior->grades[k];
                
                for (k=0;k<15;k++)
                    prior->num[k] = current->num[k];
                for (k=0;k<10;k++)
                    prior->name[k] = current->name[k];
                for (k=0;k<4;k++)
                    prior->grades[k] = current->grades[k];
                
                for (k=0;k<15;k++)
                    current->num[k] = num[k];
                for (k=0;k<10;k++)
                    current->name[k] = name[k];
                for (k=0;k<4;k++)
                    current->grades[k] = grades[k];
            }
        }
    }
    
    
}