//
//  main.c
//  lzy_ex2.10_1
//
//  Created by 赖志懿 on 15/6/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    short a=0x253f,b=0x7b7d;
    char ch;
    FILE *fp1,*fp2;
    fp1=fopen("abc1.bin", "wb+");
    fp2=fopen("abc2.txt", "w+");
    fwrite(&a, sizeof(short), 1, fp1);
    fwrite(&b, sizeof(short), 1, fp1);
    fprintf(fp2, "%d %d",a,b);
    rewind(fp1);rewind(fp2);
    while ((ch=fgetc(fp1))!=EOF)
        putchar(ch);
    putchar('\n');
    while ((ch=fgetc(fp2))!=EOF)
        putchar(ch);
    putchar('\n');
    fclose(fp1);
    fclose(fp2);
    
    return 0;
}