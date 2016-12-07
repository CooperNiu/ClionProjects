//
// Created by Cooper on 26/10/2016.
//
#include "CommonHeader.h"
#ifndef CONVERSION_STACKHEADER_H
#define CONVERSION_STACKHEADER_H
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 2
/* 栈的顺序存储表示 */
typedef struct SqStack
{
    ElemType *base; //在栈构造之前和销毁之后,base的值为NULL
    ElemType *top; //栈顶指针
    int stacksize; //当前已分配的存储空间,  以元素为单位
}SqStack; //顺序栈

/* 使用指针传参的函数 */
Status InitStack(SqStack *S);
Status StackTraverse(SqStack S,Status(*visit)(ElemType));
Status Pop(SqStack *S,ElemType *e);
Status Push(SqStack *S,ElemType e);
Status GetTop(SqStack S,ElemType *e);
int StackLength(SqStack S);
Status StackEmpty(SqStack S) ;
Status ClearStack(SqStack *S);
Status DestroyStack(SqStack *S);
Status visit(ElemType);

void conversion(void);
#endif //CONVERSION_STACKHEADER_H
