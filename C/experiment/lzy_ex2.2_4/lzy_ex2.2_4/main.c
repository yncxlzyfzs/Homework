//
//  main.c
//  lzy_ex2.2_4
//
//  Created by 赖志懿 on 15/4/19.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define N 32768 //2的15次方

void print_2(unsigned short x);

int main(void) {
    unsigned short a,b;
    scanf("%hu%hu",&a,&b);
    
    printf("<0>\na = ");
    print_2(a);
    printf("b = ");
    print_2(b);
    
    a = a+b;
    
    printf("<1>\na = ");
    print_2(a);
    printf("b = ");
    print_2(b);
    
    b = a-b;
    
    printf("<2>\na = ");
    print_2(a);
    printf("b = ");
    print_2(b);
    
    a = a-b;
    
    printf("<3>\na = ");
    print_2(a);
    printf("b = ");
    print_2(b);
    
    return 0;
}

/*输出二进制数*/
void print_2(unsigned short x){
    int i;
    for (i=1; i<=16; i++) {
        printf("%d",x/N);
        x <<= 1;
    }
    printf("\n");
}