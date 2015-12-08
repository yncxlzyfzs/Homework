//
//  main.c
//  lzy_4.17
//
//  Created by 赖志懿 on 15/4/19.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int sum=0,count=0,nub;
    printf("Please input 10 numbers : ");
    for (int i=1; i<=10; i++) {
        scanf("%d",&nub);
        if (nub>0) {
            sum += nub;
            count++;
        }
    }
    if (count) {
        printf("numbers=%d, average=%f\n",count,1.0*sum/count);
    }
    return 0;
}
