//
//  main.c
//  lzy_4.13
//
//  Created by 赖志懿 on 15/4/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define N 100

int main(int argc, const char * argv[]) {
    int i,j,sum=0,a[N+1];
    for (a[0]=a[1]=0,i = 2; i<=N+1; i++) {
        a[i] = 1;
    }
    for (i=2; i*i<=N+1; i++) {
        if (a[i]) {
            for (j=i*i; j<N; j+=i) {
                a[j] = 0;
            }
        }
    }
    
    for (int n=2; n<=N/2; n++) {
        for (i=1; i<=N; i++) {
            if (a[i] && a[2*n-i]) {
                printf("%d = %d + %d\n",2*n,i,2*n-i);
                sum+=1;/*输出的数字个数*/
                break;
            }
        }
    }
    if(sum==N/2-1){
        printf("The Goldbach conjecture is correct.");
    }else{
        printf("The Goldbach conjecture is wrong.");
    }
    return 0;
}
