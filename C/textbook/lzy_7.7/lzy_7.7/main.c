//
//  main.c
//  lzy_7.7
//
//  Created by 赖志懿 on 15/5/3.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int a[1000];

void compare(int n);

int main(void) {
    int x,i,count=-1;
    
    printf("Please input numbers: \n");
    while (scanf("%d",&x)!=EOF) {
        count++;
        a[count]=x;
    }
    
    compare(count);
    
    printf("Your numbers: \n");
    for (i=0; i<=count; i++) {
        printf("%d\n",a[i]);
    }
    return 0;
}

void compare(int n){
    static int count=0;
    int i,mark=0,min=a[count];
    if (n==0) return;
    
    for (i=count; i<=n+count; i++) {
        if (a[i]<min){
            min=a[i];
            mark = i;
        }
    }
    if (mark!=0) {
        a[mark]=a[count];
        a[count]=min;
    }
    
    count++;
    compare(n-1);
}