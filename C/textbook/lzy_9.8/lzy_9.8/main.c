//
//  main.c
//  lzy_9.8
//
//  Created by 赖志懿 on 15/6/8.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#define N 4
#define NOT_FOUND -1

struct web{
    char short_name[10];
    char full_name[20];
    char URL[60];
};

int search_web(struct web *s,char *s1){                                 //查找函数
    int i;
    for (i=0; i<N; i++) {
        if (!strcmp(s[i].short_name, s1))
            return i;
    }
    return NOT_FOUND;
}

int main(void) {
    int i,j,k;
    char s1[10],s2[20],s3[60];
    
    struct web tmp,s[N];
    
    printf("Please input %d of your commonly used web sites: \n",N);
    
    for (i=0; i<N; i++) {                                               //初始化网址数组
        scanf("%s %s %s",s1,s2,s3);
        strcpy(s[i].short_name, s1);
        strcpy(s[i].full_name, s2);
        strcpy(s[i].URL, s3);
    }
    
    
    for (i=0; i<N; i++) {                                               //升序冒泡排序
        for (j=0; j<N-i-1; j++) {
            for (k=0; k<10; k++) {
                if (s[j].short_name[k] > s[j+1].short_name[k]) {
                    tmp = s[j];
                    s[j] = s[j+1];
                    s[j+1] = tmp;
                    break;
                }
            }
        }
    }
    
    printf("please input a short name: ");
    scanf("%s",s1);
    if (search_web(s, s1) != NOT_FOUND)
        printf("URL :%s",s[search_web(s, s1)].URL);
    else
        printf("Web is not found!\n");
    
    return 0;
}