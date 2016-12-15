//
// Created by Cooper on 28/10/2016.
//

#ifndef MAZE_LIST_H
#define MAZE_LIST_H
/* list.h ���е�˳��洢�ṹ(������ѭ�����кͷ�ѭ������) */
#define MAXQSIZE 5 /* �����г���(����ѭ�����У������г���Ҫ��1) */
typedef struct SqQueue{
    ElemType *base; /* ��ʼ���Ķ�̬����洢�ռ� */
    int front; /* ͷָ��,�����в���,ָ�����ͷԪ�� */
    int rear; /* βָ��,�����в���,ָ�����βԪ�ص���һ��λ�� */
}SqQueue;

Status InitQueue(SqQueue *Q);

Status DestroyQueue(SqQueue *Q);

Status ClearQueue(SqQueue *Q);

Status QueueEmpty(SqQueue Q);

int QueueLength(SqQueue Q);

Status GetHead(SqQueue Q,ElemType *e);

Status EnQueue(SqQueue *Q,ElemType e);

Status DeQueue(SqQueue *Q,ElemType *e);

Status QueueTraverse(SqQueue Q,void(*vi)(ElemType));

#endif //MAZE_LIST_H
