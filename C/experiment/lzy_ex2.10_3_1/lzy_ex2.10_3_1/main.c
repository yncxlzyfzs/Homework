//
//  main.c
//  lzy_ex2.10_3_1
//
//  Created by 赖志懿 on 15/6/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    char ch;
    FILE *fp;
    fp = fopen("test", "w");                            /*创建文件*/
    printf("Please input an english sentence:\n");
    ch = getchar();
    fputc(ch-'a'+'A', fp);
    while ((ch = getchar())!='\n') {
        fputc(ch, fp);
        if (ch == ' ') {
            ch = getchar();
            if (ch>='a' && ch<='z')
                fputc(ch-'a'+'A', fp);
            else
                fputc(ch, fp);
        }
    }
    
    fclose(fp);                                         /*关闭文件*/
    return 0;
}
