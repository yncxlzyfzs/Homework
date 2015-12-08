//
//  main.c
//  lzy_ex2.3_3_3
//
//  Created by 赖志懿 on 15/4/27.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int row,count;

void yanghui_tri(int n);
int print_row(int n);/*输出每行数字*/

int main(void) {
    int n;
    printf("Please input row number: ");
    scanf("%d",&n);
    count=2*(n-1);
    yanghui_tri(n-1);
    return 0;
}

void yanghui_tri(int n){
    if (n==0) {
        int a;
        for (a=1; a<=count; a++) {
            printf(" ");
        }
        count-=2;
        print_row(n);
        printf("\n");
    }else{
        yanghui_tri(n-1);
        int a;
        for (a=1; a<=count; a++) {
            printf(" ");
        }
        count-=2;
        row = n;
        print_row(n);
        printf("\n");
    }
}

/*输出每行数字*/
int print_row(int column){
    if (column==0) {
        printf("%d",1);
        return 1;
    }else{
        int m=print_row(column-1)*(row-column+1)/column;
        printf("%4d",m);
        return m;
    }
    return -1;
}