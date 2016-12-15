//
// Created by Cooper on 15/12/2016.
//
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
#define OVERFLOW -2  //因为在math.h中已定义OVERFLOW的值为3,故去掉此行
typedef int Status; /* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */
typedef int ElemType;

#ifndef LQUEUE_LQUEUE_H
#define LQUEUE_LQUEUE_H
typedef struct node{
    ElemType data;
    struct node *next;
}QNode; // 链队结点类型
typedef struct{
    QNode *front, *rear; // 将头尾指针封装在一起的链队
}LQueue;

#endif //LQUEUE_LQUEUE_H
