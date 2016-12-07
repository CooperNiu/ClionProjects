//
// Created by Cooper on 21/10/2016.
//
/* MacroDef.h 宏定义 */
#ifndef CH1_MACRODEF_H
#define CH1_MACRODEF_H

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
#define INFEASIBLE -1
typedef int ElemType; /* 定义抽象数据类型ElemType在本程序中为整型 */

typedef int Status;/* 定义函数返回的状态值为整形 */

/*typedef double ElemType; /* 定义抽象数据类型ElemType在本程序中为双精度型 */
#define OVERFLOW -2
/* #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行 */
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */

#endif //CH1_MACRODEF_H
