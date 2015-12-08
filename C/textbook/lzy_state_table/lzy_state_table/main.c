//
//  main.c
//  lzy_state_table
//
//  Created by 赖志懿 on 15/5/10.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#define T 100
#define F 200

enum event {
    invalid,
    sign,
    point,
    e,
    space,
    end,
    num,
    sum
    };

int table[][sum]={  {F,  1,  4,  F,  0,  F,  5},    /*0: start  */
                    {F,  F,  4,  F,  F,  F,  5},    /*1: sign   */
                    {F,  F,  F,  F,  2,  T,  F},    /*2: space  */
                    {F,  1,  F,  F,  F,  F,  5},    /*3: e      */
                    {F,  F,  F,  3,  F,  T,  5},    /*4: point  */
                    {F,  F,  4,  3,  2,  T,  5}     /*5: number */
                };


int getEvent(char c);
int isInt(const char s[]);


int main(void) {
    const char *s[]={".9","9.","9.2e-12","  p12"," - 98  "," 1  ", " 12a  "};
    int i;
    
    for (i=0; i<7; i++) {
        if (isInt(s[i])) printf("%s : OK\n",s[i]);
        else printf("%s : NO\n",s[i]);
    }
    
    return 0;
}

int isInt(const char s[]){
    int event,state=0;
    int i=0;
    do {
        event = getEvent(s[i]);
        state = table[state][event];
        
        i++;
    } while (state!=F && state!=T);
    return (state==T);
}

int getEvent(char c){
    if(c=='+' || c=='-') return sign;
    else if (c=='.') return point;
    else if (c==' ') return space;
    else if (c=='e') return e;
    else if (c<='9' && c>='0') return num;
    else if (c=='\0') return end;
    else return invalid;
}