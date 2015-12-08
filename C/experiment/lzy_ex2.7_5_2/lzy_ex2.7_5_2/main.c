//
//  main.c
//  lzy_ex2.7_5_2
//
//  Created by 赖志懿 on 15/6/3.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void eight_queens(int row);
void output_chessboard(int a[]);
int judge(int row,int i,int a[]);



int main(void) {
    eight_queens(1);
    return 0;
}

void eight_queens(int row){
    static int a[8];
    if (row>8) {
        output_chessboard(a);
    }else{
        int i;
        for (i=1; i<=8; i++) {
            a[row-1]=i;
            if (judge(row,i,a)) {
                eight_queens(row+1);
            }
        }
    }
}

void output_chessboard(int a[]){
    static int count=0;
    int m;
    printf("<%d>\n",++count);
    for (m=0; m<=7; m++) {
        printf("%d ",a[m]);
    }
    printf("\n");
}

int judge(int row,int i,int a[]){
    int m;
    for (m=0; m<row-1; m++) {
        if (a[m]==a[row-1] || ((float)(a[row-1]-a[m]))/((float)(row-m-1))==1 || ((float)(a[row-1]-a[m]))/((float)(row-m-1))==-1) {
            return 0;
        }
    }
    
    return 1;
}