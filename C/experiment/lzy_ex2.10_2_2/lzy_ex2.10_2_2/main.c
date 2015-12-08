//
//  main.c
//  lzy_ex2.10_2_2
//
//  Created by 赖志懿 on 15/6/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char ch;
    if (argc!=2) {
        printf("Arguments error!\n");
        exit(-1);
    }
    if (freopen("filename", "r", stdin)==NULL) {                        /*输入重定向到 filename*/
        printf("Can't open %s file!\n",argv[1]);
        exit(-1);
    }
    while ((ch=getchar())!=EOF)                                         /*从 filename 中读字符*/
        putchar(ch);                                                    /*向显示器中写字符*/
    fclose(stdin);                                                      /*关闭 filename*/
    
    return 0;
}
