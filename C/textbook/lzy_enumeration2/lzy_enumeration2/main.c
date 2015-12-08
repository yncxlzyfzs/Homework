//
//  main.c
//  lzy_enumeration2
//
//  Created by 赖志懿 on 15/4/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int a,b,c,d,e,f,g,h,i,j,x,y1,y2;
input:
    printf("Please input a number between 2~79 : ");
    scanf("%d",&x);
    if (x<2 || x>79){
        printf("Number error,please input another one!\n");
        goto input;
        
    }
    for (f=0; f<=9; f++) {
        for (g=0; g<=9; g++) {
            if (g==f) continue;
            for (h=0; h<=9; h++) {
                if (h==f || h==g) continue;
                for (i=0; i<=9; i++) {
                    if (i==f || i==g || i==h) continue;
                    for (j=0; j<=9; j++) {
                        if (j==f || j==g || j==h || j==i) continue;
                        y2=10000*f+1000*g+100*h+10*i+j;
                        
                        for (a=0; a<=9; a++) {
                            if (a==f || a==g || a==h || a==i) continue;
                            for (b=0; b<=9; b++) {
                                if (b==f || b==g || b==h || b==i || b==a) continue;
                                for (c=0; c<=9; c++) {
                                    if (c==f || c==g || c==h || c==i || c==a || c==b) continue;
                                    for (d=0; d<=9; d++) {
                                        if (d==f || d==g || d==h || d==i || d==a || d==b || d==c) continue;
                                        for (e=0; e<=9; e++) {
                                            if (e==f || e==g || e==h || e==i || e==a || e==b || e==c || e==d) continue;
                                            y1=10000*a+1000*b+100*c+10*d+e;
                                            if(y1==x*y2){
                                                printf("%.5d/%.5d=%d\n",y1,y2,x);
                                            }
                                            
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}
