//
//  main.c
//  lzy_ex2.2_3_2
//
//  Created by 赖志懿 on 15/4/19.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void print_2(unsigned short x);

int main(void) {
    unsigned short x,m,n;
    printf("Please input three numbers(x>=0,0<=m<=15,1<=n<=16-m) : ");
input:
    scanf("%hu%hu%hu",&x,&m,&n);
    if (x<0 || !(0<=m && m<=15) || !(1<=n && n<=16-m)) {
        printf("Number error,please input your numbers again! : ");
        goto input;
    }
    
    printf("x1 = ");
    print_2(x);
    
    x=(x>>m)<<(16-n);
    
    printf("x2 = ");
    print_2(x);
    
    return 0;
}

/*输出二进制数*/
void print_2(unsigned short x){
    int i;
    for (i=1; i<=16; i++) {
        printf("%d",x/32768);
        x <<= 1;
    }
    printf("\n");
}