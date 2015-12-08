//
//  main.c
//  lzy_8.3
//
//  Created by 赖志懿 on 15/5/17.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void bubble_sort(int *p,int n);

int main(void) {
    int x[] = {10,9,8,7,6,5,4,3,2,1};
    int *p = x;
    bubble_sort(p, 10);
    return 0;
}

void bubble_sort(int *p,int n){
    int i,j,k,t;
    for (i=0; i<n-1; i++) {
        for (j=0; j<n-i-1; j++)
            if (*(p+j) > *(p+j+1))
                t=*(p+j),*(p+j)=*(p+j+1),*(p+j+1)=t;
        printf("第 %d 次排序: ",n-j);
        for (k=0; k<n; k++)
            printf("%d ",*(p+k));
        printf("\n");
    }
}