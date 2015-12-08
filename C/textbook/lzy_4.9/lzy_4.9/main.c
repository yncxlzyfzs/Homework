//
//  main.c
//  lzy_4.9
//
//  Created by 赖志懿 on 15/4/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n,x1=1,x2=1;
    printf("Please input a number > 20 : ");
    scanf("%d",&n);
    if (n<1){
        printf("Your number is illegal\n");
        return 0;
    }
    printf(" 1 1");
    for (int i=3; i<=n; i++) {
        printf(" %d",x1+x2);
        x2 = x1+x2;
        x1 = x2-x1;
        if (i%8==0) printf("\n");
    }
    printf("\n");
    return 0;
}
