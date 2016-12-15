//
// Created by Cooper on 15/12/2016.
//

#include "LQueue.h"

Status InitQueue(LQueue &q)
{
    QNode *p;
    p = (QNode * )malloc(sizeof(QNode));
    if(!p)
        return ERROR;
    p->next=NULL;
    q.front = q.rear = p;
    return OK;
}
Status Push(LQueue &q, ElemType x)
{
    QNode *p;
    p= (QNode * )malloc(sizeof(QNode));
    if(!p)
        return INFEASIBLE;
    p->data=x;
    p->next=NULL;
    q.rear->next=p;
    q.rear=p;
    return OK;
}
Status IsEmpty(LQueue q)
{
    if(q.rear == q.front) return OK;
    else return ERROR;
}
Status Pop(LQueue &q, ElemType &x)
{
    QNode *p;
    p = (QNode *)malloc(sizeof(QNode));
    if(IsEmpty(q))
    {
        printf("���п�");
        return ERROR;
    }
    else
    {
        p=q.front->next;
        q.front->next=p->next;
        x=p->data;
        free(p);
        if(q.front->next == NULL){
            q.rear=q.front;
            // ֻ��һ��Ԫ��ʱ��, ���Ӻ�ӿ�, ��ʱҪ�޸Ķ�βָ��
        }
        return OK;
    }
}