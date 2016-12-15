/* constant.h (������) */
//
// Created by Cooper on 28/10/2016.
//

#ifndef MAZE_CONSTANT_H
#define MAZE_CONSTANT_H

#include<string.h>
#include<ctype.h>
#include<malloc.h> /* malloc()�� */
#include<limits.h> /* INT_MAX�� */
#include<stdio.h> /* EOF(=^Z��F6),NULL */
#include<stdlib.h> /* atoi() */
#include<io.h> /* eof() */
#include<math.h> /* floor(),ceil(),abs() */
#include<process.h> /* exit() */
/* �������״̬���� */
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFEASIBLE -1
/* #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������ */
typedef int Status; /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */

//typedef int QElemType, SElemType;
typedef struct /* �������Ԫ�غ�ջԪ��Ϊͬ���͵Ľṹ�� */
{
    int x,y; /* ��ǰ�����ֵ����ֵ */
    int pre; /* ǰһ���ڶ����е���� */
}ElemType;
//        QElemType,SElemType; /* ����ջԪ�غͶ���Ԫ�� */
#endif //MAZE_CONSTANT_H
