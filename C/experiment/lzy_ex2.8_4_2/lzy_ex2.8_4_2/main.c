//
//  main.c
//  lzy_ex2.8_4_2
//
//  Created by 赖志懿 on 15/6/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 5
#define STRLEN 80

void deleteSpace(char *);

int main(void) {
    int i;
    char *ps[N];
    
    printf("Please input N rows:\n");
    for (i=0; i<N; i++) {
        ps[i] = calloc(80,sizeof(char));
        gets(ps[i]);
    }
    
    for (i=0; i<N; i++) {
        deleteSpace(ps[i]);
        printf("\n");
    }
    
    for (i=0; i<N; i++)
        if (ps[i][0] != '\0')
            printf("%s\n",ps[i]);
    
    return 0;
}

void deleteSpace(char *p){
    char *current = p, *prior = p;
    while (!(*current == '\0')) {
        *prior++ = *current++;
        if (*current == ' ') {
            *prior++ = *current++;
            while (*current == ' ')
                current++;
        }
    }
    *prior = '\0';
}