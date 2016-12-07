//
// Created by Cooper on 27/09/2016.
//
#include "constant.h"

#ifndef MYC_SQLIST_H
#define MYC_SQLIST_H

#define LIST_INIT_SIZE 100  // 存储空间的创始分配量
#define LISTINCREMENT 10 //空间的分配增量

typedef struct{
    ElemType *elem; //存储空间基地址
    int length;//当前长度
    int listsize ;//当前分配的存储容量（以sizeof（ElemType）为单位
}SqList;

Status InitList(SqList &L);    //构造一个空的线性表
void DestroyList(SqList &L);    //销毁线性表
Status ClearList(SqList L); //清空线性表
int ListLength(SqList L);   //求线性表长度
ElemType GetElem(SqList L, int i, ElemType &e); //取元素
int LocateElem(SqList L, ElemType e, Status (*compare)(ElemType, ElemType));//定位元素
ElemType PriorElem(SqList L, ElemType cur_e, ElemType &pre_e);//求前驱元素
ElemType NextElem(SqList L, ElemType cur_e, ElemType &next_e);//求后继元素
Status ListInsert(SqList &L, int i, ElemType &e);//插入元素
Status ListDelete(SqList &L, int i, ElemType &e);//删除元素
Status equal(ElemType a, ElemType b);//判断元素是否相等
Status ListTransver(SqList &L);/*遍历输出顺序表中所有元素*/
Status ListOppose(SqList &L);//倒置元素
Status ListEmpty(SqList L);//清空线性表

#endif //MYC_SQLIST_H
