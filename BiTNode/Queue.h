////Queue.h 包含循环队列的函数定义和实现, 本程序中的循环队列的判空方法是通过少用一个元素空间来实现的
//
// Created by Cooper on 01/11/2016.
//
//#include "constant.h"
#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#define LinkQueueFun

#ifdef LinkQueueFun
/* 单链队列－－队列的链式存储结构 */
typedef struct QNode
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct
{
    QueuePtr front, rear; /* 队头、队尾指针 */
}LinkQueue;

/* 链队列(存储结构由c3-2.h定义)的基本操作(9个) */
Status InitQueue(LinkQueue &Q)
{ /* 构造一个空队列Q */
    Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    if(!Q.front)
        exit(OVERFLOW);
    Q.front->next=NULL;
    return OK;
}

Status DestroyQueue(LinkQueue &Q)
{ /* 销毁队列Q(无论空否均可) */
    while(Q.front)
    {
        Q.rear=Q.front->next;
        free(Q.front);
        Q.front=Q.rear;
    }
    return OK;
}

Status ClearQueue(LinkQueue &Q)
{ /* 将Q清为空队列 */
    QueuePtr p,q;
    Q.rear=Q.front;
    p=Q.front->next;
    Q.front->next=NULL;
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

Status GetHead_Q(LinkQueue Q,QElemType &e) /* 避免与bo2-6.c重名 */
{ /* 若队列不空,则用e返回Q的队头元素,并返回OK,否则返回ERROR */
    QueuePtr p;
    if(Q.front==Q.rear)
        return ERROR;
    p=Q.front->next;
    e=p->data;
    return OK;
}

Status EnQueue(LinkQueue &Q,QElemType &e)
{ /* 插入元素e为Q的新的队尾元素 */
QueuePtr p=(QueuePtr)malloc(sizeof(QNode));
if(!p) /* 存储分配失败 */
exit(OVERFLOW);
p->data=e;
p->next=NULL;
Q.rear->next=p;
Q.rear=p;
return OK;
}

Status DeQueue(LinkQueue &Q,QElemType &e)
{ /* 若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR */
    QueuePtr p;
    if(Q.front==Q.rear)
        return ERROR;
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)
        Q.rear=Q.front;
    free(p);
    return OK;
}

Status QueueTraverse(LinkQueue Q,void(*vi)(QElemType))
{ /* 从队头到队尾依次对队列Q中每个元素调用函数vi()。一旦vi失败,则操作失败 */
    QueuePtr p;
    p=Q.front->next;
    while(p)
    {
        vi(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}
#endif
#ifdef SqQueueFun
#define MAXQUEUE 100 //最大队列长度,(对于循环队列，最大队列长度要减1)
typedef struct {
    QElemType *base; // 初始化的动态分配存储空间
    int front; // 头指针, 若队列不空, 指向队列头元素
    int rear; // 尾指针, 若对列不空, 指向队列尾元素的下一个位置
}SqQueue;

Status InitQueue(SqQueue &Q)
{// 构造一个空队列
    Q.base = (QElemType *)malloc(MAXQUEUE* sizeof(QElemType)); // 开辟空间
    if(!Q.base) exit(OVERFLOW); //若失败
    Q.front = Q.rear = 0; //赋初值
    return OK;
}

int QueueLength(SqQueue Q)
{// 返回Q的元素个数, 即队列的长度
    return (Q.rear - Q.front + MAXQUEUE) % MAXQUEUE;
}

Status EnQueue(SqQueue &Q, QElemType e)
{// 插入元素e为Q的新的对尾元素
    if((Q.rear + 1)%MAXQUEUE == Q.front) return ERROR;// 队列满, 判定条件尾指针+1后取余与头指针相等
    Q.base[Q.rear] = e; // = *(Q.base+Q.rear), 也就是将e赋给对尾元素.
    Q.rear=(Q.rear+1)%MAXQUEUE;
    return OK;
}

Status DeQueue(SqQueue &Q, QElemType &e)
{// 若队列不空, 则删除Q的对头元素, 用e 返回其值, 并返回OK
 // 否则返回ERROR
    if(Q.front == Q.rear) return ERROR;
    e = Q.base[Q.rear];//e返回被删元素的值
    Q.front = (Q.front+1)%MAXQUEUE;//对头删除
    return OK;
}

Status QueueEmpty(SqQueue Q)
{// 若队列为空, 则返回TRUE, 否则返回FALSE
    return (Q.front != Q.rear) ? FALSE : TRUE;
}

Status DestroyQueue(SqQueue &Q)
{// 销毁队列Q, Q便不再存在
    if(Q.base)
        free(Q.base);
    Q.base=NULL;
    Q.front=Q.rear=0;
/*  while (Q.front != Q.rear)//while queue is not empty
    {
        Q.front=(Q.front+1)%MAXQUEUE;//delete element
    }//while
 */
    return OK;
}

Status ClearQueue(SqQueue &Q)
{//将Q清空为空队列
    Q.front=Q.rear=0;
    return OK;
}

Status GetHead(SqQueue Q, QElemType &e)
{// if queue is not empty, return OK, if not, return ERROR
    //2016-11-3 20:11:49 This function went wrong, every time e returns 0, which means e cannot be modified.
    if(Q.front != Q.rear) {
        e=Q.base[Q.rear-1];//the wrong is here, previous version is Q.base[Q.rear], yet my queue type means
        //Q.rear points rear element's next location , so my error Q.base[Q.rear] is a junk value
        cout << e;
        return OK;
    }
    else
        return ERROR;
}

//void visit(QElemType e)
//{// visit queue and print the element
//    cout << e;
//}
//Status QueueTraverse(SqQueue Q, void (*visit)(QElemType))
Status QueueTraverse(SqQueue Q, QElemType &e)
{// traverse the queue from front to rear and use visit() to do something
// when I was tasting this function, it went wrong
//because the judgement of whether queue is empty is wrong as"Q.front==Q.rear
    while (Q.front!=Q.rear) //when Q is not empty
    {
        e = Q.base[Q.front];
        cout<<e<<endl;//replace the visit function
        Q.front = (Q.front+1)%MAXQUEUE;
    }//while
    cout << endl;
    return OK;
}
#endif
#endif //QUEUE_QUEUE_H