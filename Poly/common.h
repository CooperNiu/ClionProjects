//
// Created by Cooper on 22/10/2016.
//

#ifndef POLY_COMMON_H
#define POLY_COMMON_H
/* common.h 抽象数据类型Polynomial的实现
 * 本程序中的链表无头结点
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct /* 项的表示,多项式的项作为LinkList的数据元素 */
{
    float coef; /* 系数 */
    int expn; /* 指数 */
}term,ElemType;
/* 两个类型名:term用于本ADT,ElemType为LinkList的数据对象名 */

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

/* 带头结点的线性链表类型 */
typedef struct LNode /* 结点类型 */
{
    ElemType data;
    struct LNode *next;
}LNode,*Link,*Position;

typedef struct LinkList /* 链表类型 */
{
    Link head,tail; /* 分别指向线性链表中的头结点和最后一个结点 */
    int len; /* 指示线性链表中数据元素的个数 */
}LinkList;

typedef LinkList polynomial;
#define DestroyPolyn DestroyList /* 与bo2-6.cpp中的函数同义不同名 */
#define PolynLength ListLength /* 与bo2-6.cpp中的函数同义不同名 */

Status MakeNode(Link *p,ElemType e);
void FreeNode(Link *p);
Status InitList(LinkList *L);
Status ClearList(LinkList *L);
Status DestroyList(LinkList *L);

Status InsFirst(LinkList *L,Link h,Link s); /* 形参增加L,因为需修改L */
Status DelFirst(LinkList *L,Link h,Link *q); /* 形参增加L,因为需修改L */
Status Append(LinkList *L,Link s);
Position PriorPos(LinkList L,Link p);
Status Remove(LinkList *L,Link *q);
Status InsBefore(LinkList *L,Link *p,Link s);
Status InsAfter(LinkList *L,Link *p,Link s);
Status SetCurElem(Link p,ElemType e);
ElemType GetCurElem(Link p);
Status ListEmpty(LinkList L);
int ListLength(LinkList L);
Position GetHead(LinkList L);
Position GetLast(LinkList L);
Position NextPos(Link p);
Status LocatePos(LinkList L,int i,Link *p);
Position LocateElem(LinkList L,ElemType e,Status (*compare)(ElemType,ElemType));
Status ListTraverse(LinkList L,void(*visit)(ElemType));
Status OrderInsert(LinkList *L,ElemType e,int (*comp)(ElemType,ElemType));
Status LocateElemP(LinkList L,ElemType e,Position *q,int(*compare)(ElemType,ElemType));


/*  多项式相关的函数 */
Status OrderInsertMerge(LinkList *L,ElemType e,int(* compare)(term,term));
//int cmp(term a,term b) /* CreatPolyn()的实参 */;
int cmp(ElemType a, ElemType b);
void CreatPolyn(polynomial *P,int m); /* 算法2.22 */
void PrintPolyn(polynomial P);
void AddPolyn(polynomial *Pa,polynomial *Pb); /* 算法2.23 */
void AddPolyn1(polynomial *Pa,polynomial *Pb);
void Opposite(polynomial Pa);
void SubtractPolyn(polynomial *Pa,polynomial *Pb);
void MultiplyPolyn(polynomial *Pa,polynomial *Pb);

#endif //POLY_COMMON_H
