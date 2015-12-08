//
//  main.c
//  lzy_ex2.3_1
//
//  Created by 赖志懿 on 15/4/27.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main()
{
    int i,n,s=1;
    printf("Please enter n: ");
    scanf("%d",&n);//缺少&
    for(i=1;i<=n;i++)//把","改成";"
        s=s*i;
    printf("%d!=%d",n,s);
    
    return 0;//把return语句移到花括号内
}