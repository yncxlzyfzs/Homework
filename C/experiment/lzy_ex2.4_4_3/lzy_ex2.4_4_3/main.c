//
//  main.c
//  lzy_ex2.4_4_3
//
//  Created by 赖志懿 on 15/5/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define BEGIN 10
#define END 20

void goldbach(long n);
int isPrime(long n);

int main(void) {
    long count=0,a[END-BEGIN];
    int i;
    printf("GOLDBACH'S CONJECTURE:/nEvery even number n>=4 is the sum of two primes.\n");
    
    for (i=BEGIN; i<=END; i++) {
        if (!(i%2)) {
            a[count++]=i;
        }
    }
    
    for (i=0; i<count; i++) goldbach(a[i]);
    
    return 0;
}

void goldbach(long n){
    long k;
    for (k=2; k<=n/2; k++) {
        if (!isPrime(k)) continue;
        if (isPrime(n-k)){
            printf("%ld = %ld + %ld\n",n,k,n-k);
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