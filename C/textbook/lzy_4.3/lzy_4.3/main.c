//
//  main.c
//  lzy_4.3
//
//  Created by 赖志懿 on 15/4/18.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>

int isLeap(int year);

int main(int argc, const char * argv[]) {
    int year,month,day,days;
    printf("Input the date like \"year month day\"\n");
input_date:
    scanf("%d%d%d",&year,&month,&day);
    if (year<0 || (month<0 || month>12) || (day<0 || day>31) ||(month==2 && day>28+isLeap(year))) {
        printf("Date error,Please input it again!\n");
        goto input_date;
    }
    switch (month) {
        case 1:
            days = 0;
            break;
        case 2:
            days = 31;
            break;
        case 3:
            days = 59;
            break;
        case 4:
            days = 90;
            break;
        case 5:
            days = 120;
            break;
        case 6:
            days = 151;
            break;
        case 7:
            days = 181;
            break;
        case 8:
            days = 212;
            break;
        case 9:
            days = 243;
            break;
        case 10:
            days = 273;
            break;
        case 11:
            days = 304;
            break;
        case 12:
            days = 334;
            break;
        default:
            break;
    }
    days += day;
    
    /*判断是否是闰年*/
    if (month > 2) {
        days += isLeap(year);
    }
    
    
    printf("%d.%d.%d is the %d days of %d\n",year,month,day,days,year);
    return 0;
}


/*判断是否是闰年*/
int isLeap(int year){
    if(year%400==0 || (year%4==0 && year%100!=0))
        return 1;
    else
        return 0;
}