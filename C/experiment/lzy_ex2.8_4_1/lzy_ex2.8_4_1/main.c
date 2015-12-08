//
//  main.c
//  lzy_ex2.8_4_1
//
//  Created by 赖志懿 on 15/6/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void print_4_bit(long);

int main(void) {
    int i;
    long a;
    char *p,key1=240,key2=15,r1,r2;                         //标尺
    
    printf("Please input a long integer: ");                //输入长整数
    scanf("%lu",&a);
    
    
    printf("the hexadecimal form of it is: \n");            //输出
    p=&a;                                                   //字节指针指向长整型数据
    for (i=0; i<4; i++) {
        r1 = (p[3-i]&key1)>>4&key2;
        r2 = p[3-i]&key2;
        if (r1<10)
            printf("%c",r1+'0');
        else
            printf("%c",r1-10+'a');
        if (r2<10)
            printf("%c",r2+'0');
        else
            printf("%c",r2-10+'a');
    }
    printf("\n");
    
    return 0;
}

