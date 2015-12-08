//
//  main.c
//  lzy_factorial
//
//  Created by 赖志懿 on 15/5/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define N 80

void factorial(int n,int *a);
void mul(int n, int *a);

int main(void) {
    int n,i,flag=0,a[N];
    
    for (i=0; i<=N; i++)                    /*数组初始化*/
        a[i] = -1;
    
    printf("Please input n: ");
    scanf("%d",&n);
    
    printf("%d! = ",n);
    
    factorial(n,a);
    
    for(i=N-1; i>=0; i--){                  /*输出结果*/
        if (flag == 0 && *(a+i) != -1){     /*数组以两位为单位存储数字*/
            flag=1;
            printf("%d",*(a+i));            /*如果检测到数字，直接输出并跳过防止在一位数前补零*/
            continue;
        }
        if (flag == 1){
            if (*(a+i) < 10)                /*如果该组数字为一位数，在其前补零*/
                printf("%d",0);
            printf("%d",*(a+i));
        }
    }
    
    return 0;
}


void factorial(int n,int *a){
    int i;
    a[0] = 1;                               /*添加初始值*/
    for (i=2; i<=n; i++)
        mul(i, a);
}


void mul(int n, int *a){                    /*计算乘法*/
    int i,carry=0;
    
    for (i=0; *(a+i)!=-1; i++){
        int m;
        m = *(a+i)*n + carry;
        
        carry = m/100;
        *(a+i) = m%100;
    }
    
    if (carry != 0)
        *(a+i) = carry;
}