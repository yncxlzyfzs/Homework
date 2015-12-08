//
//  main.c
//  lzy_5.1
//
//  Created by 赖志懿 on 15/4/22.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_NUMBER 6

int getNumber(void);

int main(void) {
    int num1,num2;
    srand(time(NULL));
    printf("Game on\nPress 'Enter' to roll the dice\n");
    num1 = getchar();
    num1 = getNumber();
    num2 = getNumber();
    printf("Sum of your dice is : %d\n",num1+num2);
    if (num1+num2==7 || num1+num2==11) {
        printf("You win this game!\n");
        return 0;
    }else if(num1+num2==2 || num1+num2==3 || num1+num2==12){
        printf("You lose\n");
        return 0;
    }else{
        int sum = num1+num2;
        do {
            printf("Press 'Enter' to roll again");
            num1 = getchar();
            num1 = getNumber();
            num2 = getNumber();
            printf("Sum of your dice is : %d\n",num1+num2);
            if (num1+num2==7){
                printf("You lose\n");
                return 0;
            }
        } while (num1+num2!=sum);
        printf("You win this game!\n");
    }
    
    return 0;
}

int getNumber(void){
    int num;
    num = rand();
    num = num%MAX_NUMBER+1;
    return num;
}