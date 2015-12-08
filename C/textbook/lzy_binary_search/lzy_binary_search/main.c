//
//  main.c
//  lzy_binary_search
//
//  Created by 赖志懿 on 15/5/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void binarySearch(int key,int a[],int front,int middle,int back);

int main(void) {
    
    int key,front=1,middle,back,a[]={1,2,10,11,22,67,100};
    back=sizeof(a)/sizeof(int);
    middle=back/2+1;
    
    printf("Please input a key: ");
    scanf("%d",&key);
    
    binarySearch(key,a, front, middle, back);
    
    return 0;
}

void binarySearch(int key,int a[],int front,int middle,int back){
    /*查找成功*/
    if (key==a[middle-1]){
        printf("a[%d] = %d\n",middle-1,key);
        return;
    }
    
    /*结束条件*/
    if (front==middle && middle==back) {
        printf("Your key is not found.\n");
        return ;
    }
    
    if (key<a[middle-1]) binarySearch(key, a, front, middle/2,middle-1);
    else binarySearch(key, a, middle+1, (back+middle)/2+1,back);
}