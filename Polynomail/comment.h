//
// Created by Cooper on 19/10/2016.
//
#include<stdio.h>
#include<stdlib.h>


#ifndef POLYNOMAIL_COMMENT_H
#define POLYNOMAIL_COMMENT_H

#define   TRUE           1
#define   FALSE          0
#define   OK             1
#define   ERROR          0
#define   INFEASIBLE    -1
#define   OVERFLOW      -2
typedef   int Status;
typedef struct
{
    float coef;//系数
    int   expn;//指数
}term,ElemType;

typedef struct LNode//结点类型
{
    ElemType data;
    struct LNode *next;
}LNode,*Link,*Position;

typedef struct//链表类型
{
    Link head,tail;
    int len;
}LinkList;
typedef LinkList polynomial;

Status MakeNode_E(Link &p,ElemType e);
void FreeNode_E(Link &p);
Status InitList_E(LinkList &L);
Status DestroyList_E(LinkList &L);
Status InsFirst_E(LinkList &L,Link h,Link s);
Status DelFirst_E(LinkList &L,Link h,Link &q);
Status Append_E(LinkList &L,Link s);
Status SetCurElem_E(Link &p,ElemType e);
ElemType GetCurElem_E(Link p);
int ListLength_E(LinkList L);
Position GetHead_E(LinkList L);
Position NextPos_E(LinkList L,Link p);
void CreatPolyn(polynomial *p, int m);
void DestroyPolyn(polynomial *p);
void PrintPolyn(polynomial p);
int PolyLength(polynomial p);
int cmp(term a, term b);
void AddPolyn(polynomial *Pa, polynomial *Pb);
Status ListEmpty(LinkList L);

#endif //POLYNOMAIL_COMMENT_H