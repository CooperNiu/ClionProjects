//
// Created by Cooper on 22/10/2016.
//

#ifndef POLY_COMMON_H
#define POLY_COMMON_H
/* common.h ������������Polynomial��ʵ��
 * �������е�������ͷ���
 * */

#include <stdio.h>
#include <stdlib.h>

typedef struct /* ��ı�ʾ,����ʽ������ΪLinkList������Ԫ�� */
{
    float coef; /* ϵ�� */
    int expn; /* ָ�� */
}term,ElemType;
/* ����������:term���ڱ�ADT,ElemTypeΪLinkList�����ݶ����� */

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;

/* ��ͷ���������������� */
typedef struct LNode /* ������� */
{
    ElemType data;
    struct LNode *next;
}LNode,*Link,*Position;

typedef struct LinkList /* �������� */
{
    Link head,tail; /* �ֱ�ָ�����������е�ͷ�������һ����� */
    int len; /* ָʾ��������������Ԫ�صĸ��� */
}LinkList;

typedef LinkList polynomial;
#define DestroyPolyn DestroyList /* ��bo2-6.cpp�еĺ���ͬ�岻ͬ�� */
#define PolynLength ListLength /* ��bo2-6.cpp�еĺ���ͬ�岻ͬ�� */

Status MakeNode(Link *p,ElemType e);
void FreeNode(Link *p);
Status InitList(LinkList *L);
Status ClearList(LinkList *L);
Status DestroyList(LinkList *L);

Status InsFirst(LinkList *L,Link h,Link s); /* �β�����L,��Ϊ���޸�L */
Status DelFirst(LinkList *L,Link h,Link *q); /* �β�����L,��Ϊ���޸�L */
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


/*  ����ʽ��صĺ��� */
Status OrderInsertMerge(LinkList *L,ElemType e,int(* compare)(term,term));
//int cmp(term a,term b) /* CreatPolyn()��ʵ�� */;
int cmp(ElemType a, ElemType b);
void CreatPolyn(polynomial *P,int m); /* �㷨2.22 */
void PrintPolyn(polynomial P);
void AddPolyn(polynomial *Pa,polynomial *Pb); /* �㷨2.23 */
void AddPolyn1(polynomial *Pa,polynomial *Pb);
void Opposite(polynomial Pa);
void SubtractPolyn(polynomial *Pa,polynomial *Pb);
void MultiplyPolyn(polynomial *Pa,polynomial *Pb);

#endif //POLY_COMMON_H
