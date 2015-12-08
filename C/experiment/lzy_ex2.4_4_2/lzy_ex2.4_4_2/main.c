//
//  main.c
//  lzy_ex2.4_4_2
//
//  Created by 赖志懿 on 15/5/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void goldbach(long n);
int isPrime(long n);

int main(void) {
    long n;
    printf("Please input a even number which greater than or equal to 4: \n");
    scanf("%ld",&n);
    
    if (n<4) {
        printf("Enter error!\n");
        return 0;
    }
    
    goldbach(n);
    return 0;
}

void goldbach(long n){
    long k;
    for (k=2; k<=n/2; k++) {
        if (!isPrime(k)) continue;
        if (isPrime(n-k)){
            printf("%ld = %ld + %ld\nGoldbach conjecture is correct!\n",n,k,n-k);
            break;
        }
    }
    if (k>n/2) printf("Goldbach conjecture is wrong!\n");
}

int isPrime(long n){
    long k,limit;
    
    if (n==2) return 1;
    if (!(n%2)) return 0;
    limit=n/2;
    for (k=3; k<=limit; k+=2)
        if (!(n%k)) return 0;
    return 1;
}