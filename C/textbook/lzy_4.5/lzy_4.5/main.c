//
//  main.c
//  lzy_4.5
//
//  Created by 赖志懿 on 15/4/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    char operator;
    float a,b;
    printf("Please input two numbers a,b and the operator(+,-,*,/) \neg. : a+b\n");
    scanf("%f%c%f",&a,&operator,&b);
    switch (operator) {
        case '+':
            printf("%f\n",a+b);
            break;
        case '-':
            printf("%f\n",a-b);
            break;
        case '*':
            printf("%f\n",a*b);
            break;
        case '/':
            if (b==0) {
                printf("Divisor can't be 0\n");
                return 0;
            }else{
                printf("%f\n",a/b);
            }
            break;
        default:
            printf("Operator error!\n");
            break;
    }
    /*
     if实现：
     if (operator == '+') {
        printf("%f\n",a+b);
     }else if(operator == '-'){
        printf("%f\n",a-b);
     }else if(operator == '*'){
        printf("%f\n",a*b);
     }else if(operator == '/'){
        if (b==0) {
            printf("Divisor can't be 0\n");
            return 0;
        }else{
        printf("%f\n",a/b);
     }
     }else{
        printf("Operator error!\n");
     }
     */
    return 0;
}
