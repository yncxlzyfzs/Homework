//
//  main.c
//  lzy_ex2.10_2_1
//
//  Created by 赖志懿 on 15/6/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char ch;
    FILE *fp;
    if (argc!=2) {
        printf("Arguments error!\n");
        exit(-1);
    }
    if ((fp=fopen(argv[1], "r"))==NULL) {                       /*fp 指向 filename*/
        printf("Can't open %s file!\n",argv[1]);
        exit(-1);
    }
    while ((ch=fgetc(fp))!=EOF)                                 /*从 filename 中读字符*/
        putchar(ch);                                            /*向显示器中写字符*/
    fclose(fp);                                                 /*关闭 filename*/
    
    return 0;
}
