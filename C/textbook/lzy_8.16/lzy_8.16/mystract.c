//
//  main.c
//  lzy_8.16
//
//  Created by 赖志懿 on 15/6/2.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    int i,j,k,sum;
    for (i=1; i<argc; i++){                         //统计总字数
        for (j=0; argv[i][j] != '\0'; j++);
        sum += j;
    }
    
    char newString[sum+1];                          //创建新字符串
    
    for (i=1,k=0; i<argc; i++)                      //合并字符串
        for (j=0; argv[i][j] != '\0'; j++) {
            newString[k++] = argv[i][j];
        }
    newString[k] = '\0';
    
    printf("%s\n",newString);                       //输出合并后的字符串
    
    return 0;
}