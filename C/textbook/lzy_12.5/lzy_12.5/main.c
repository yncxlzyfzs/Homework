//
//  main.c
//  lzy_12.5
//
//  Created by 赖志懿 on 15/5/9.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int Palindrome(char s[],int test,int len);
int len(char s[]);
int main(void) {
    char s[30];
    printf("Please input a string: ");
    scanf("%s",s);
    
    if (Palindrome(s,0,len(s))) {
        printf("Its a palindrome.\n");
    }else{
        printf("Its not a palindrome.\n");
    }
    
    return 0;
}

int Palindrome(char s[],int test,int len){
    if (len%2) return 0;
    if (s[test]!=s[len-test-1]) return 0;
    if (test>len/2) return 1;
    
    return Palindrome(s, test+1, len);
}

int len(char s[]){
    int count=0;
    while (s[count]!='\0') {
        count++;
    }
    return count;
}