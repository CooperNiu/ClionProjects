///* StackFunc.cpp ˳��ջ���洢�ṹ��c3-1.h���壩�Ļ���������9���� */
// Created by Cooper on 28/10/2016.
//
#include "constant.h"
#include "stack.h"

Status GetTop(SqStack S, ElemType *e) { /* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
    if(S.top>S.base)
    {
        *e=*(S.top-1);
        return OK;
    }
    else
        return ERROR;
}

Status Push(SqStack *S, ElemType e) { /* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
    if((*S).top-(*S).base>=(*S).stacksize) /* ջ����׷�Ӵ洢�ռ� */
    {
        (*S).base=(ElemType *)realloc((*S).base,((*S).stacksize+STACKINCREMENT)*sizeof(ElemType));
        if(!(*S).base)
            exit(OVERFLOW); /* �洢����ʧ�� */
        (*S).top=(*S).base+(*S).stacksize;
        (*S).stacksize+=STACKINCREMENT;
    }
    *((*S).top)++=e;
    return OK;
}

Status Pop(SqStack *S, ElemType *e) { /* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
    if((*S).top==(*S).base)
        return ERROR;
    *e=*--(*S).top;
    return OK;
}

Status StackTraverse(SqStack S, Status (*visit)(ElemType)) { /* ��ջ�׵�ջ�����ζ�ջ��ÿ��Ԫ�ص��ú���visit()�� */
    /* һ��visit()ʧ�ܣ������ʧ�� */
    while(S.top>S.base)
        visit(*S.base++);
    printf("\n");
    return OK;
}

int StackLength(SqStack S) { /* ����S��Ԫ�ظ�������ջ�ĳ��� */
    return S.top-S.base;
}

Status ClearStack(SqStack *S) { /* ��S��Ϊ��ջ */
    (*S).top=(*S).base;
    return OK;
}

Status StackEmpty(SqStack S) { /* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
    if(S.top==S.base)
        return TRUE;
    else
        return FALSE;
}

Status DestroyStack(SqStack *S) { /* ����ջS��S���ٴ��� */
    free((*S).base);
    (*S).base=NULL;
    (*S).top=NULL;
    (*S).stacksize=0;
    return OK;
}

Status InitStack(SqStack *S) { /* ����һ����ջS */
    (*S).base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
    if(!(*S).base)
        exit(OVERFLOW); /* �洢����ʧ�� */
    (*S).top=(*S).base;
    (*S).stacksize=STACK_INIT_SIZE;
    return OK;
}
