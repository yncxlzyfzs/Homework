//
//  main.c
//  lzy_ex2.9_3_1
//
//  Created by 赖志懿 on 15/6/16.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

struct bits{
    unsigned char bit0:1;
    unsigned char bit1:1;
    unsigned char bit2:1;
    unsigned char bit3:1;
    unsigned char bit4:1;
    unsigned char bit5:1;
    unsigned char bit6:1;
    unsigned char bit7:1;
}test;

union save{
    unsigned char input;
    struct bits bit;
}save;

void f0(unsigned char b){
    printf("the function %d is called!\n",b);
}
void f1(unsigned char b){
    printf("the function %d is called!\n",b);
}
void f2(unsigned char b){
    printf("the function %d is called!\n",b);
}
void f3(unsigned char b){
    printf("the function %d is called!\n",b);
}
void f4(unsigned char b){
    printf("the function %d is called!\n",b);
}
void f5(unsigned char b){
    printf("the function %d is called!\n",b);
}
void f6(unsigned char b){
    printf("the function %d is called!\n",b);
}
void f7(unsigned char b){
    printf("the function %d is called!\n",b);
}


int main(void) {
    void (*p_fun[])(unsigned char)={f0,f1,f2,f3,f4,f5,f6,f7};
    printf("please input an integer: ");
    scanf("%d",&save.input);
    
    if (save.bit.bit0) p_fun[0](save.bit.bit0);
    if (save.bit.bit1) p_fun[1](save.bit.bit1);
    if (save.bit.bit2) p_fun[2](save.bit.bit2);
    if (save.bit.bit3) p_fun[3](save.bit.bit3);
    if (save.bit.bit4) p_fun[4](save.bit.bit4);
    if (save.bit.bit5) p_fun[5](save.bit.bit5);
    if (save.bit.bit6) p_fun[6](save.bit.bit6);
    if (save.bit.bit7) p_fun[7](save.bit.bit7);
    
    return 0;
}
