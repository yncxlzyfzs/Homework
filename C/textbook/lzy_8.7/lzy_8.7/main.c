//
//  main.c
//  lzy_8.7
//
//  Created by 赖志懿 on 15/5/17.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define N 5                                     /*输入整数的总个数n*/

void reverse(int *p,int n);

int main(void) {
    int i,a[N];
    int *p;
    p=a;
    
    printf("Please input %d integers: ",N);     /*输入n个整数*/
    for (i=0; i<N; i++) {
        scanf("%d",p+i);
    }
    
    reverse(p,N);                               /*调用颠倒顺序函数reverse()*/
    
    return 0;
}

void reverse(int *p,int n){
    int i,t;
    for (i=0; i<n/2; i++) {                     /*用第三个函数颠倒中心对称的两个数*/
        t=*(p+i);
        *(p+i)=*(p+n-i-1);
        *(p+n-i-1)=t;
    }
    
    for (i=0; i<n; i++)                         /*输出数组中整数*/
        printf("%d ",*(p+i));
}