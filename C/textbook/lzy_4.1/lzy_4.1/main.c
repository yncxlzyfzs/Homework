//
//  main.c
//  lzy_4.1
//
//  Created by 赖志懿 on 15/4/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a,b,c;
    printf("Please input grades of A B C : ");
    scanf("%d%d%d",&a,&b,&c);
    
    if (a == b) {
        printf("A = B");
        if (a == c) printf(" = C");/*此时A=B=C*/
        printf(" : %d\n",a);
    }else if(a == c){
        printf("A = C : %d\n",a);
    }else if(b == c){
        printf("B = C : %d",b);/*此后A、B、C互不相等*/
    }else if ((b<a && a<c) || (c<a && a<b)) {
        printf("A : %d\n",a);
    }else if((a<b && b<c) || (c<b && b<a)){
        printf("B : %d\n",b);
    }else{
        printf("C : %d\n",c);
    }
    return 0;
}
