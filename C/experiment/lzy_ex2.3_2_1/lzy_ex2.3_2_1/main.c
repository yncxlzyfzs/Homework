//
//  main.c
//  lzy_ex2.3_2_1
//
//  Created by 赖志懿 on 15/4/27.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    int i=1,n,s=1;
    printf("Please enter: ");
    scanf("%d",&n);
    while (i<=n) {
        s*=i;
        i++;
    }
    
    /*
     do {
        s*=i;
        i++;
     } while (i<=n);
     
     */
    
    printf("%d!=%d",n,s);

    return 0;
}

