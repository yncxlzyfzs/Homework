//
//  main.c
//  lzy_ex2.8_4_3
//
//  Created by 赖志懿 on 15/6/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define N 5

void increase(int *);
void decrease(int *);

int main(int argc, const char * argv[]) {
    int i,nums[N];
    void (*sort)(int *);                            //排序算法函数的指针
    
    printf("Please input %d integers: \n",N);
    for (i=0; i<N; i++){
        scanf("%d",&nums[i]);
    }
    
    if (argc-1)
        sort = decrease;                            //判断是否有参数-d输入
    else
        sort = increase;
    
    sort(nums);
    
    return 0;
}

void increase(int *nums){
    int i,j;
    for (i=0; i<N-1; i++)
        for (j=0; j<N-1-i; j++)
            if (nums[j]>nums[j+1]) {
                int tmp;
                tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
    
    for (i=0; i<N; i++)
        printf("%d ",nums[i]);
    printf("\n");
}

void decrease(int *nums){
    int i,j;
    for (i=0; i<N-1; i++)
        for (j=0; j<N-1-i; j++)
            if (nums[j]<nums[j+1]) {
                int tmp;
                tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
            }
    
    for (i=0; i<N; i++)
        printf("%d ",nums[i]);
    printf("\n");
}