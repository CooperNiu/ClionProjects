// 更新2016-12-10 10:21:01
// Created by Cooper on 07/12/2016.
#ifndef GRAPH_STACKLINKSTORED_H
#define GRAPH_STACKLINKSTORED_H
/* c3-2.h 单链队列－－队列的链式存储结构 */
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr front,rear; /* 队头、队尾指针 */
}LinkQueue;
/* bo3-2.c 链队列(存储结构由c3-2.h定义)的基本操作(9个) */
Status InitQueue(LinkQueue *Q)
{ /* 构造一个空队列Q */
    (*Q).front=(*Q).rear=(QueuePtr)malloc(sizeof(QNode));
    if(!(*Q).front)
        exit(OVERFLOW);
    (*Q).front->next=NULL;
    return OK;
}

Status DestroyQueue(LinkQueue *Q)
{ /* 销毁队列Q(无论空否均可) */
    while((*Q).front)
    {
        (*Q).rear=(*Q).front->next;
        free((*Q).front);
        (*Q).front=(*Q).rear;
    }
    return OK;
}

Status ClearQueue(LinkQueue *Q)
{ /* 将Q清为空队列 */
    QueuePtr p,q;
    (*Q).rear=(*Q).front;
    p=(*Q).front->next;
    (*Q).front->next=NULL;
    while(p)
    {
        q=p;
        p=p->next;
        free(q);
    }
    return OK;
}

Status QueueEmpty(LinkQueue Q)
{ /* 若Q为空队列,则返回TRUE,否则返回FALSE */
    if(Q.front==Q.rear)
        return TRUE;
    else
        return FALSE;
}

int QueueLength(LinkQueue Q)
{ /* 求队列的长度 */
    int i=0;
    QueuePtr p;
    p=Q.front;
    while(Q.rear!=p)
    {
        i++;
        p=p->next;
    }
    return i;
}

#endif //GRAPH_STACKLINKSTORED_H
