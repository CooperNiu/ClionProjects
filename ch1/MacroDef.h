//
// Created by Cooper on 21/10/2016.
//
/* MacroDef.h �궨�� */
#ifndef CH1_MACRODEF_H
#define CH1_MACRODEF_H

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
#define INFEASIBLE -1
typedef int ElemType; /* ���������������ElemType�ڱ�������Ϊ���� */

typedef int Status;/* ���庯�����ص�״ֵ̬Ϊ���� */

/*typedef double ElemType; /* ���������������ElemType�ڱ�������Ϊ˫������ */
#define OVERFLOW -2
/* #define OVERFLOW -2 ��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������ */
typedef int Status; /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */

#endif //CH1_MACRODEF_H
