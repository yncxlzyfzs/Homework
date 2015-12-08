//
//  main.c
//  lzy_ex2.7_4_3
//
//  Created by 赖志懿 on 15/5/22.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define N 5
#define MAX_NAME_LEN 10
#define NOT_FIND -1

void sortItem(int *rank, float *score);
int binsearch(int *rank, float *score, float goal);

int main(void) {
    int i,a;
    int rank[N];
    char name[N][MAX_NAME_LEN];
    float goal,score[N];
    
    for (i=0; i<N; i++)                                             //初始化排名
        rank[i]=i;
    
    printf("Please inout %d students and their grades: \n",N);
    
    for (i=0; i<N; i++){                                            //输入
        scanf("%s %f",name[i],&score[i]);
    }
    
    sortItem(rank, score);
    
    printf("rank\n----------------\n");                             //输出
    for (i=0; i<N; i++){
        a = rank[i];
        printf("<%d> %s: %.2f\n",i+1,name[a],score[a]);
    }
    
    
    printf("Please input your score: ");                            //查询
    scanf("%f",&goal);
    
    
    
    if((a = binsearch(rank, score, goal)) != NOT_FIND){
        i=rank[a];
        printf("name: %s score: %.2f",name[i],score[i]);
    }else{
        printf("not found!\n");
    }
    
    return 0;
}

void sortItem(int *rank, float *score){
    int i,j,a,b,tmp;
    for (i=N; i>1; i--)
        for (j=0; j<i-1; j++){
            a = rank[j];
            b = rank[j+1];
            if (score[a]<score[b]) {
                tmp = rank[j];
                rank[j] = rank[j+1];
                rank[j+1] = tmp;
            }
        }
}

int binsearch(int *rank, float *score, float goal){
    int a,b,c,i = 0,j = N-1;
    while (i<j) {
        a=rank[i];
        b=rank[j];
        c=rank[(i+j)/2];
        if (goal < score[c]) {
            i=(i+j)/2+1;
        }else if(goal > score[c]){
            j=(i+j)/2;
        }else{
            return (i+j)/2;
        }
    }
    a = rank[i];
    if (score[a] == goal)
        return i;
    return NOT_FIND;
}

