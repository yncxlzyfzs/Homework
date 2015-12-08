//
//  main.c
//  lzy_ex2.3_2_2
//
//  Created by 赖志懿 on 15/4/27.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    long S;
    int n,s=1;
    printf("Please enter S: ");
    scanf("%ld",&S);
    for (n=1; ; n++) {
        s*=n;
        if (s>=S) break;
    }
    
    printf("%d!>=%ld",n,S);
    
    return 0;
}
