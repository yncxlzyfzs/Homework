//
//  main.c
//  lzy_ex2.7_1
//
//  Created by 赖志懿 on 15/5/21.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void sort(int[],int);

int main(void) {
    int a[10]={27,13,5,32,23,3,17,43,55,39};
    int i;
    sort(a,10);
    for(i=0;i<10;i++)
        printf("%6d",a[i]);
    printf("\n");
    return 0;
}

void sort(int b[],int n){
    int i,j,t;
    for (i=0;i<n-1;i++)
        for (j=0;j<n-i-1;j++)
            if (b[j]>b[j+1])
                t=b[j],b[j]=b[j+1],b[j+1]=t;
}