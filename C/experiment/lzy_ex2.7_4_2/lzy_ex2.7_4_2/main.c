//
//  main.c
//  lzy_ex2.7_4_2
//
//  Created by 赖志懿 on 15/5/21.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    int n,i;
    char a[100];
    printf("Please input an integer: ");
    scanf("%d",&n);
    
    for (i=0; n/2.0; i++) {                 //反向存入字符数组
        a[i]=n%2+'0';
        n/=2;
    }
    
    printf("binary form: ");                //反向输出得到正序二进制表示
    for (; i>0;i--)
        printf("%c",a[i-1]);
    
    return 0;
}