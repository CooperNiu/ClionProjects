///* stack.h 栈的顺序存储表示 */
// Created by Cooper on 28/10/2016.
//

#ifndef MAZE_STACK_H
#define MAZE_STACK_H

#define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
#define STACKINCREMENT 2 /* 存储空间分配增量 */
typedef struct SqStack
{
    ElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
    ElemType *top; /* 栈顶指针 */
    int stacksize; /* 当前已分配的存储空间，以元素为单位 */
}SqStack; /* 顺序栈 */

Status InitStack(SqStack *S);
Status DestroyStack(SqStack *S);
Status StackEmpty(SqStack S);
Status ClearStack(SqStack *S);
int StackLength(SqStack S);
Status GetTop(SqStack S,ElemType *e);
Status Push(SqStack *S,ElemType e);
Status StackTraverse(SqStack S,Status(*visit)(ElemType));
Status Pop(SqStack *S,ElemType *e);

#endif //MAZE_STACK_H
