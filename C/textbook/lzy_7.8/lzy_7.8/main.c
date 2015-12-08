//
//  main.c
//  lzy_7.8
//
//  Created by 赖志懿 on 15/5/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int k,n=-1,a[1000];

void exchange(int count);

int main(void) {
    int i;
    /*输入n与k*/
    printf("Please input n and k: \n");
    scanf("%d %d",&n,&k);
    n-=1;
    
    /*输入数组内数字*/
    printf("Please input your numbers: \n");
    for (i=0; i<=n; i++) {
        int x;
        scanf("%d",&x);
        a[i]=x;
    }
    
    /*调用函数*/
    exchange(0);
    
    /*输出新数组*/
    printf("Your number: \n");
    for (i=0; i<=n; i++) {
        printf("%d\n",a[i]);
    }
    
    return 0;
}

void exchange(int count){
    if (count==k){
        int i;
        for (i=k; i<=n; i++)
            a[i-k]=a[i];
        return;
    }
    int m=a[count];
    exchange(count+1);
    a[n-k+count+1]=m;
}