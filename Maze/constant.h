/* constant.h (程序名) */
//
// Created by Cooper on 28/10/2016.
//

#ifndef MAZE_CONSTANT_H
#define MAZE_CONSTANT_H

#include<string.h>
#include<ctype.h>
#include<malloc.h> /* malloc()等 */
#include<limits.h> /* INT_MAX等 */
#include<stdio.h> /* EOF(=^Z或F6),NULL */
#include<stdlib.h> /* atoi() */
#include<io.h> /* eof() */
#include<math.h> /* floor(),ceil(),abs() */
#include<process.h> /* exit() */
/* 函数结果状态代码 */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFEASIBLE -1
/* #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行 */
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */

//typedef int QElemType, SElemType;
typedef struct /* 定义队列元素和栈元素为同类型的结构体 */
{
    int x,y; /* 当前点的行值，列值 */
    int pre; /* 前一点在队列中的序号 */
}QElemType,SElemType; /* 定义栈元素和队列元素 */
#endif //MAZE_CONSTANT_H
