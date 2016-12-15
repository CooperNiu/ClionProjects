//
// Created by Cooper on 15/12/2016.
//
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
#define OVERFLOW -2  //��Ϊ��math.h���Ѷ���OVERFLOW��ֵΪ3,��ȥ������
typedef int Status; /* Status�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
typedef int Boolean; /* Boolean�ǲ�������,��ֵ��TRUE��FALSE */
typedef int ElemType;

#ifndef LQUEUE_LQUEUE_H
#define LQUEUE_LQUEUE_H
typedef struct node{
    ElemType data;
    struct node *next;
}QNode; // ���ӽ������
typedef struct{
    QNode *front, *rear; // ��ͷβָ���װ��һ�������
}LQueue;

#endif //LQUEUE_LQUEUE_H
