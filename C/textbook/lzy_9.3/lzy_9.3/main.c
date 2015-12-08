//
//  main.c
//  lzy_9.3
//
//  Created by 赖志懿 on 15/6/8.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

struct date{                                                                                        //日期结构
    int year,month,day;
} date;

int is_leap_year(int y)                                                                             //判断闰年
{
    if((y%4==0 && y%100!=0) || y%400==0)
        return 1;
    return 0;
}

int main(void) {

    printf("Please input a date in \"year month day\": \n");                                        //输入日期
    scanf("%d %d %d",&date.year,&date.month,&date.day);
    
    switch (date.month) {                                                                           //根据月份输出日期
        case 1:
            printf("This is the %dth day of %d",date.day,date.year);
            break;
        case 2:
            printf("This is the %dth day of %d",31+date.day,date.year);
            break;
        case 3:
            printf("This is the %dth day of %d",59+is_leap_year(date.year)+date.day,date.year);
            break;
        case 4:
            printf("This is the %dth day of %d",90+is_leap_year(date.year)+date.day,date.year);
            break;
        case 5:
            printf("This is the %dth day of %d",120+is_leap_year(date.year)+date.day,date.year);
            break;
        case 6:
            printf("This is the %dth day of %d",151+is_leap_year(date.year)+date.day,date.year);
            break;
        case 7:
            printf("This is the %dth day of %d",181+is_leap_year(date.year)+date.day,date.year);
            break;
        case 8:
            printf("This is the %dth day of %d",212+is_leap_year(date.year)+date.day,date.year);
            break;
        case 9:
            printf("This is the %dth day of %d",243+is_leap_year(date.year)+date.day,date.year);
            break;
        case 10:
            printf("This is the %dth day of %d",273+is_leap_year(date.year)+date.day,date.year);
            break;
        case 11:
            printf("This is the %dth day of %d",304+is_leap_year(date.year)+date.day,date.year);
            break;
        case 12:
            printf("This is the %dth day of %d",334+is_leap_year(date.year)+date.day,date.year);
            break;
            
        default:
            break;
    }
    return 0;
}
