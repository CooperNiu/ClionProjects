//
// Created by Cooper on 20/10/2016.
//

#ifndef POLYNOMAIL_NEW_C2_6_H
#define POLYNOMAIL_NEW_C2_6_H
/* c2-6.h 抽象数据类型Polynomial的实现 */
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


#endif //POLYNOMAIL_NEW_C2_6_H
