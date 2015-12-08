//
//  main.c
//  lzy_3.5
//
//  Created by 赖志懿 on 15/4/11.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(void) {
    char c;
    scanf("%c",&c);
    if ((c>='0'&&c<='9')||(c>='a'&&c<='f')||(c>='A'&&c<='F')) {
        if (c>='0'&&c<='9') {
            printf("%d\n",c-'0');
        }else if(c>='a'&&c<='f'){
            printf("%d\n",c-'a'+10);
        }else{
            printf("%d\n",c-'A'+10);
        }
    }else{
        printf("%d\n",c);
    }
    return 0;
}
