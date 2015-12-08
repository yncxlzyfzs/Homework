//
//  main.c
//  lzy_ex2.8_5_1
//
//  Created by 赖志懿 on 15/6/10.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define N 20
#define M 10

int *input_long(void);
int *add_long_num(int *,int *);

int main(void) {
    int  *a,*b,*result;
    int i;
    
    printf("Please input a:\n");
    a = input_long();
    
    printf("Please input b:\n");
    b = input_long();
    
    if (a == NULL || b == NULL){
        printf("Enter Error !");
        return 0;
    }
    
    result =  add_long_num(a, b);
    
    
    printf("result:\n");                                        //输出结果
    int dot=0,start=0;
    for (i=0; i<N+M; i++) {
        if (i == N-1){
            if (!start)
                printf("0");
            dot = 1;
        }
        
        if (!dot && !start && !*(result+i))                     //跳过零位
            continue;
        
        printf("%d",*(result+i));
        if (dot == 1) {                                         //输出小数点
            printf(".");
            dot = 2;
        }
        start = 1;
    }
    
    return 0;
}

int *input_long(void){
    int *result = (int *)malloc((M+N)*sizeof(int));
    char c;
    int i,*p;
    
    for (i=0; i<M+N; i++)                                       //初始化超长数组
        *(result+i) = 0;
    
    i=0;
    while ((c = getchar()) != '.') {                            //整数部分输入模式
        p = result+N-1;
        for (i=0; i<N-1; i++)
            *(result+i) = *(result+i+1);
        *(p--) = c-'0';
    }
    
    p = result+N;
    i=0;
    while ((c = getchar()) != '\n') {                            //小数部分输入模式
        *(p++) = c-'0';
    }

    return result;
}


int *add_long_num(int *a,int *b){
    int *result = (int *)malloc((M+N)*sizeof(int));
    int i,sum,carry = 0;
    for (i=0; i<M+N; i++)                                       //初始化超长数组
        *(result+i) = 0;
    
    for (i=M+N-1; i>=0; i--) {
        sum = *(a+i)+*(b+i)+carry;
        *(result+i) = sum%10;
        if (carry) {
            carry = 0;
        }
        if (sum/10)
            carry = sum/10;
    }
    
    return result;
}