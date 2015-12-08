//
//  main.c
//  lzy_ex2.7_2_2
//
//  Created by 赖志懿 on 15/5/21.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define M 10
#define  N 3
#define OUT -1

int main(void) {
    int a[M],b[M];
    int i,j,k;
    for (i=0;i<M;i++)
        a[i]=i+1;
    for (i=M,j=0;i>1;i--){
        for (k=1;k<=N;k++){
            while (a[j]==OUT) j++;
            if (++j>M-1) j=0;                   //1
        }
        b[M-i]=j?a[j-1]:a[M-1];                 //2
        if(j)
            a[--j]=OUT;
        else
            a[M-1]=OUT;                         //3
    }
    for (i=0;i<M-1;i++)
        printf("%6d",b[i]);
    for (i=0;i<M-1;i++)                         //4
        if (a[i]!=OUT) printf("%6d",a[i]);
    return 0;
}