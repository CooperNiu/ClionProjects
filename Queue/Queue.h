////Queue.h 包含循环队列的函数定义和实现, 本程序中的循环队列的判空方法是通过少用一个元素空间来实现的
//
// Created by Cooper on 01/11/2016.
//
#include "constant.h"

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H
#define MAXQUEUE 100 //最大队列长度,(对于循环队列，最大队列长度要减1)
typedef struct {
    ElemType *base; // 初始化的动态分配存储空间
    int front; // 头指针, 若队列不空, 指向队列头元素
    int rear; // 尾指针, 若对列不空, 指向队列尾元素的下一个位置
}SqQueue;

Status Init(SqQueue &Q)
{// 构造一个空队列
    Q.base = (ElemType *)malloc(MAXQUEUE* sizeof(ElemType)); // 开辟空间
    if(!Q.base) exit(OVERFLOW); //若失败
    Q.front = Q.rear = 0; //赋初值
    return OK;
}

int QueueLength(SqQueue Q)
{// 返回Q的元素个数, 即队列的长度
    return (Q.rear - Q.front + MAXQUEUE) % MAXQUEUE;
}

Status EnQueue(SqQueue &Q, ElemType e)
{// 插入元素e为Q的新的对尾元素
    if((Q.rear + 1)%MAXQUEUE == Q.front) return ERROR;// 队列满, 判定条件尾指针+1后取余与头指针相等
    Q.base[Q.rear] = e; // = *(Q.base+Q.rear), 也就是将e赋给对尾元素.
    Q.rear=(Q.rear+1)%MAXQUEUE;
    return OK;
}

Status DeQueue(SqQueue &Q, ElemType &e)
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

Status GetHead(SqQueue Q, ElemType &e)
{// if queue is not empty, return OK, if not, return ERROR
    //2016-11-3 20:11:49 This function went wrong, every time e returns 0, which means e cannot be modified.
    /// 2016-11-19 14:59:58 This function passes the test
    if(Q.front != Q.rear) {
        e=Q.base[Q.rear-1];//the wrong is here, previous version is Q.base[Q.rear], yet my queue type means
        //Q.rear points rear element's next location , so my error Q.base[Q.rear] is a junk value
        cout << e;
        return OK;
    }
    else
        return ERROR;
}

//void visit(ElemType e)
//{// visit queue and print the element
//    cout << e;
//}
//Status QueueTraverse(SqQueue Q, void (*visit)(ElemType))
Status QueueTraverse(SqQueue Q, ElemType &e)
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
#endif //QUEUE_QUEUE_H