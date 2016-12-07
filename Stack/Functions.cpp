/* Functions.cpp
 * 2016年10月26日21:33:36
 * 使用引用传参的函数
 * 目前功能已经实现, 调试没有通过
 * */
//
// #include "header.h"
//
//// Created by Cooper on 25/10/2016.
////
//Status  InitStack(SqStack &S)
//{
//    (S).base = (ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
//    if(!(S).base)
//        exit(OVERFLOW);
//    (S).base = (S).top = NULL;
//    S.stacksize = STACK_INIT_SIZE;
//    return OK;
//}
//
//Status Push(SqStack &S,ElemType e)
//{
//    if(S.top-S.base>=STACK_INIT_SIZE*sizeof(ElemType *))
//    {
//        S.base = (ElemType *)realloc(S.base, (S.stacksize+STACKINCREMENT)* sizeof(ElemType));
//        if(!S.base) exit(OVERFLOW);//存储空间分配失败应该返回 "溢出"
//        S.top = S.base + S.stacksize;
//        S.stacksize+=STACKINCREMENT;
//    }
//    *(S.top)++=e;//将e的值存在S.top所指向的地方;
//    return OK;
//}
//
//Status StackTraverse(SqStack S, Status(*visit)(ElemType))
//{
//    while(S.top>S.base)
//        visit(*S.base++);
//    printf("\n");
//    return OK;
//}
//
//Status Pop(SqStack &S, ElemType &e)
//{/* 如果栈为空,则返回ERROR, 否则删除栈顶元素, 并用e返回其值 */
//    if(S.top == S.base)
//        return ERROR;
//    e=*--(S.top);
//    return OK;
//}
//
//Status GetTop(SqStack S, ElemType &e)
//{//如果栈不空, 用e返回S栈顶的值,并返回OK 否则, 返回ERROR
//    if(S.top>S.base)
//    {
//        e=*--S.top;
//        return  OK;
//    }
//    else
//        return ERROR;
//}
//
//Status ClearStack(SqStack &S)
//{
//    S.top = S.base;
//    S.stacksize = 0;
//    return  OK;
//}
//
//Status DestroyStack(SqStack &S)
//{
//    free(S.base);
//    S.top = S.base = NULL;
//    S.stacksize = 0;
//    return OK;
//}
//
//Status StackEmpty(SqStack S)
//{
//    if(S.top == S.base)
//        return TRUE;
//    else
//        return FALSE;
//}
//
//int StackLength(SqStack S)
//{
//    return S.top-S.base;
//}