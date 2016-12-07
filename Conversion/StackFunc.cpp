//
// Created by Cooper on 26/10/2016.
//
//
// Created by Cooper on 23/10/2016.
//
#include "StackHeader.h"
#include "CommonHeader.h"

#ifndef STACK_STACKFUNC_CPP
#define STACK_STACKFUNC_CPP

/*  顺序栈（存储结构由c3-1.h定义）的基本操作（9个） */
Status InitStack(SqStack *S)
{ /* 构造一个空栈S */
    (*S).base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(!(*S).base)
        exit(OVERFLOW); /* 存储分配失败 */
    (*S).top=(*S).base;
    (*S).stacksize=STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack(SqStack *S)
{ /* 销毁栈S，S不再存在 */
    free((*S).base);
    (*S).base=NULL;
    (*S).top=NULL;
    (*S).stacksize=0;
    return OK;
}

Status ClearStack(SqStack *S)
{ /* 把S置为空栈 */
    (*S).top=(*S).base;
    return OK;
}

Status StackEmpty(SqStack S)
{ /* 若栈S为空栈，则返回TRUE，否则返回FALSE */
    if(S.top==S.base)
        return TRUE;
    else
        return FALSE;
}

int StackLength(SqStack S)
{ /* 返回S的元素个数，即栈的长度 */
    return S.top-S.base;
}

Status GetTop(SqStack S,ElemType *e)
{ /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
    if(S.top>S.base)
    {
        *e=*(S.top-1);
        return OK;
    }
    else
        return ERROR;
}

Status Push(SqStack *S,ElemType e)
{ /* 插入元素e为新的栈顶元素 */
    if((*S).top-(*S).base>=(*S).stacksize) /* 栈满，追加存储空间 */
    {
        (*S).base=(ElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(ElemType));
        /* 分配新的空间是将栈整体存入新的更大的存储空间,所以要用realloc()函数 */
        if(!(*S).base)
            exit(OVERFLOW); /* 存储分配失败 */
        (*S).top=(*S).base+(*S).stacksize;
        (*S).stacksize+=STACKINCREMENT;
    }
    *((*S).top)++=e;
    return OK;
}

Status Pop(SqStack *S,ElemType *e)
{ /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
    if((*S).top==(*S).base)
        return ERROR;
    *e=*--(*S).top; //先减一, 指向栈顶元素, 然后传值给e
    return OK;
}

Status StackTraverse(SqStack S,Status(*visit)(ElemType))
{ /* 从栈底到栈顶依次对栈中每个元素调用函数visit()。 */
    /* 一旦visit()失败，则操作失败 */
    while(S.top>S.base)
        visit(*S.base++);//从栈底到栈顶遍历
    printf("\n");//全部输出完毕后换行
    return OK;
}

Status visit(ElemType c)
{
    printf("%d ", c);
    return  OK;
}

#endif //STACK_STACKFUNC_CPP

