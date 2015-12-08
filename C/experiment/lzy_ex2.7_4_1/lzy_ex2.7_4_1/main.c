//
//  main.c
//  lzy_ex2.7_4_1
//
//  Created by 赖志懿 on 15/5/21.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void output(int a[3][4]);

int main(void) {
    int i,j,a[3][4],b[4][3];
    
    /* input */
    printf("Please input a 3X4 matrix: \n");
    for (i=0; i<3; i++)
        scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
    for (i=0; i<3; i++)
        for (j=0; j<4; j++)
            b[j][i]=a[i][j];
    
    /* output */
    printf("matrix:\n");
    for (i=0; i<3; i++) {
        for (j=0; j<4; j++)
            printf("%4d",a[i][j]);
        printf("\n");
    }
    printf("transposed matrix:\n");
    for (i=0; i<4; i++) {
        for (j=0; j<3; j++)
            printf("%4d",b[i][j]);
        printf("\n");
    }
    
    return 0;
}