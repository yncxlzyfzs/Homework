//
//  main.c
//  lzy_7.9
//
//  Created by 赖志懿 on 15/5/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
enum counter {NUMBER, LETTER, OTHER};

int main(void) {
    char c;
    int counter[3]={0,0,0};
    while ((c=getchar())!=EOF) {
        
        if (c==' ' || c=='\n') continue;
        
        if (c>='0'&&c<='9') {
            counter[NUMBER]++;
        }else if((c>='a'&&c<='z') || (c>='A'&&c<='Z')){
            counter[LETTER]++;
        }else{
            counter[OTHER]++;
        }
    }
    
    printf("Counter:\n\tNumber: %d\n\tLetter: %d\n\tOther: %d\n",counter[NUMBER],counter[LETTER],counter[OTHER]);
    return 0;
}
