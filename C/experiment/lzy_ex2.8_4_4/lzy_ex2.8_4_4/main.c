//
//  main.c
//  lzy_ex2.8_4_4
//
//  Created by 赖志懿 on 15/6/4.
//  Copyright (c) 2015年 Lteam.lzy. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define N 5
#define M 3
#define STRLEN 10

float *student_average(float grades[N][M]);                                 //每个学生各门课程平均成绩函数
float *class_average(float grades[N][M]);                                   //全班每门课程平均成绩函数
int *lower_than_average(float grades[N][M]);                                //低于各门课程平均成绩人数函数
int *special_student(float grades[N][M]);                                   //不及格人数和90以上人数函数

int main(void) {
    char classes[M][STRLEN];
    float grades[N][M];
    int i,j;
    
    printf("Please input classes: \n");                                     //输入课程名称及学生成绩
    for (i=0; i<M; i++) {
        scanf("%s",classes[i]);
    }
    printf("Please input students' grades: \n");
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            scanf("%f",&grades[i][j]);
        }
    }
    
    float *s_average;                                                     //每个学生各门课程平均成绩
    s_average = student_average(grades);
    printf("student_average: \n");
    for (i=0; i<N; i++) {
        printf("<%d> %.2f\n",i+1,*(s_average+i));
    }
    
    float *c_average;                                                     //全班每门课程平均成绩
    c_average = class_average(grades);
    printf("class_average: \n");
    for (i=0; i<M; i++) {
        printf("<%d> %.2f\n",i+1,*(c_average+i));
    }
    
    int *l_average;                                                     //低于各门课程平均成绩人数
    l_average = lower_than_average(grades);
    printf("lower_than_average: \n");
    for (i=0; i<M; i++) {
        printf("<%s> %d\n",classes[i],*(l_average+i));
    }
    
    int *s_student;
    s_student = special_student(grades);
    printf("Special student:\n");
    printf("score < 60:\n");                                            //输出各科不及格人数
    for (i=0; i<M; i++) {
        printf("<%s> %d\n",classes[i],*(s_student+i));
    }
    printf("score >= 90:\n");                                           //输出各科90分及以上人数
    for (i=0; i<M; i++) {
        printf("<%s> %d\n",classes[i],*(s_student+3+i));
    }
    return 0;
}



float *student_average(float grades[N][M]){
    float *result = (float *)malloc(N*sizeof(float));
    float *p = &grades[0][0];
    int i,j;
    
    for (i=0; i<N; i++) {                                                   //初始化数组
        *(result+i) = 0;
    }
    
    for (i=0; i<N; i++) {
        for (j=0; j<M; j++) {
            *(result+i) += *(p+i*M+j);
        }
        *(result+i) /= M;
    }
    
    return result;
}

float *class_average(float grades[N][M]){
    float *result = (float *)malloc(M*sizeof(float));
    float *p = &grades[0][0];
    int i,j;
    
    for (i=0; i<M; i++) {                                                   //初始化数组
        *(result+i) = 0;
    }
    
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            *(result+i) += *(p+j*M+i);
        }
        *(result+i) /= N;
    }
    
    return result;
}

int *lower_than_average(float grades[N][M]){
    int *result = (int *)malloc(M*sizeof(int));
    float *p = &grades[0][0],*average = class_average(grades);
    int i,j;

    for (i=0; i<M; i++) {                                                   //初始化数组
        *(result+i) = 0;
    }
    
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            if (*(p+M*j+i) < *(average+i))
                *(result+i) += 1;
        }
    }
    
    return result;
}

int *special_student(float grades[N][M]){
    int *result =(int *)calloc(2, M*sizeof(int));
    int *rp = &result[0];
    float *p = &grades[0][0];
    int i,j;
    
    for (i=0; i<M*2; i++) {                                                   //初始化数组
        *(result+i) = 0;
    }
    
    for (i=0; i<M; i++) {
        for (j=0; j<N; j++) {
            if (*(p+M*j+i) < 60)
                *(rp+i) += 1;
            if (*(p+M*j+i) >= 90)
                *(rp+3+i) += 1;
        }
    }
    
    return result;
}