//
//  main.c
//  lzy_enumeration1
//
//  Created by 赖志懿 on 15/4/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

void triangle(int count,int a,int b,int c,int d,int e,int f);

int main(int argc, const char * argv[]) {
    int a,b,c,d,e,f,sum1,sum2,sum3,count=0;
    for (a=1; a<=6; a++) {
        for (b=1; b<=6; b++) {
            if (b==a){
                continue;
            }
            for (c=1; c<=6; c++) {
                if (c==a || c==b){
                    continue;
                }
                for (d=1; d<=6; d++) {
                    if (d==a || d==b || d==c){
                        continue;
                    }
                    for (e=1; e<=6; e++) {
                        if (e==a || e==b || e==c || e==d) {
                            continue;
                        }
                        for (f=1; f<=6; f++) {
                            if(f==a || a==b || f==c || f==d || f==e) {
                                continue;
                            }
                            
                            sum1 = a+b+c;
                            sum2 = c+d+e;
                            sum3 = e+f+a;
                            if (sum1==sum2 && sum1==sum3) {
                                triangle(++count,a, b, c, d, e, f);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}

void triangle(int count,int a,int b,int c,int d,int e,int f){
    printf("<%d>\n%6d\n%4d%4d\n%2d%4d%4d\n\n",count,a,b,f,c,d,e);
}