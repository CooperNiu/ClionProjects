//
// Created by Cooper on 27/09/2016.
//
#include <cstdio>
#include <cstdlib>
#include "sqlist.h"
/*初始化线性表*/
Status InitList(SqList &L)
{
    L.elem=(ElemType *) malloc(LIST_INIT_SIZE* sizeof(ElemType));
    if(!L.elem) exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}
/*销毁线性表*/
void DestroyList(SqList &L)
{
    if(L.elem) free(L.elem);
    L.elem=NULL;
}
/*求线性表长度*/
int ListLength(SqList L)
{
    return L.length;
}
/*清空线性表*/
Status ClearList(SqList L)
{//清空线性表
    L.length=0;
}
/*读取元素*/
Status GetElem(SqList L, int i, ElemType &e)
{
    if(i<1 || i>L.length) return ERROR;
    e=L.elem[i-1];
    return OK;
}
/*判断元素是否相等*/
Status equal(ElemType a, ElemType b)
{
    if(a==b)
        return TRUE;
    else
        return FALSE;
}
/*插入元素*/
Status ListInsert(SqList &L, int i, ElemType &e)
{
    ElemType  *p, *q;
    ElemType *newbase;

    if(i<1 || L.length+1)
        return ERROR;
    if(L.length>=L.listsize){
        newbase = (ElemType *)realloc(L.elem, (L.listsize+LISTINCREMENT)* sizeof(ElemType));
        if(!newbase)
            exit(OVERFLOW);
        L.elem=newbase;
        L.listsize+=LISTINCREMENT;
    }
}
/*确定元素位序*/
int LocateElem(SqList L, ElemType e, Status (*compare) (ElemType, ElemType))
{
    int i = 1;
    ElemType *p=L.elem;
    while(i<=L.length && (*compare)((*p)++, e))
//    while(i<=L.length && (*compare(*(p++), e)))
        i++;
    if(i<=L.length)
        return i;
    else
        return 0;
}
/*求前驱元素*/
ElemType PriorElem(SqList L, ElemType cur_e, ElemType &pre_e)
{
    int i = 2;              //从第二个元素开始  
    while(i <= L.length)
    {
        if(L.elem[i-1] == cur_e)
        {
            pre_e = L.elem[i-2];
            return OK;
        }
        i++;
    }
    return ERROR;
}
/*求后继元素*/
ElemType  NextElem(SqList L, ElemType cur_e, ElemType &next_e)
{
    int i;
    while(i<L.length-1)//判断是否超出线性表的长度
    {//遍历线性表，通过判断是否与当前的元素是否相同来定位；
        if(L.elem[i-1]==cur_e)//定位成功，保存下一位的值，返回寻找成功
        {
            next_e=L.elem[i];
            return OK;
        }
        i++;
    }
    return ERROR;
}
/*删除线性表的第i个元素*/
Status ListDelete(SqList &L, int i, ElemType &e) {
    if(i < 1 || i > L.length)
    {
        printf("需要删除的位置不存在！\n");
        return ERROR;
    }
    ElemType *p = &(L.elem[i-1]);      //p为被删除元素的位置
    e = *p;                             //被删除的元素的值赋给e
    ElemType *q = L.elem + L.length - 1;  //表尾元素的位置
    for(p = p+1; p <= q; p++)
        *(p-1) = *p;                    //被删除元素之后的元素左移
    L.length --;
    return OK;
}

/*遍历输出顺序表中所有元素*/
Status ListTransver(SqList &L)
{
    int i;
    if(L.length == 0)
    {
        printf("\t该表为空！\n\n");
        return ERROR;
    }
    else
    {
        printf("\t该线性表为：");
        for(i = 1; i <= L.length ; i++)
            printf("%d ", L.elem[i-1]);
        printf("\n\n");
    }
    return OK;
}
/*逆置线性表*/
Status ListOppose(SqList &L)
{
    int i;
    ElemType x;
    for(i=0; i<L.length/2; i++)
    {
        x=L.elem[i];
        L.elem[i]=L.elem[L.length-1-i];
        L.elem[L.length-1-i]=x;
    }
    return OK;
}
/*判断线性表是否为空*/
Status ListEmpty(SqList L)
{
    if(L.length==0)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}
