//
// Created by Cooper on 27/10/2016.
//
#include "StackHeader.h"

#define M 8 //M进制 //进制转换

void conversion(void)
{/* 对于输入的任意一个非负十进制整数, 打印输出与其等值的八进制数 */
    SqStack s;
    int N;//
    ElemType e;
    if(InitStack(&s))//构造空栈
    {
        printf("OK! Let's get going!\n");
    }
    else
        printf("No!\n");
    printf("Input a int:\n");
    scanf("%d", &N);
    while (N)
    {
        Push(&s, N%M);//余数进栈
        N=N/M;//整除
    }
    while(!StackEmpty(s))
    {
        Pop(&s, &e);//逆序输出栈中元素
        printf("%d", e);
    }
}