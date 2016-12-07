/* main.cpp 调用函数 实现相关的功能 */

#include "header.h" // 该头文件中包含constant.h
#define N 20

Status visit(ElemType c)
{
    printf("%d ", c);
    return  OK;
}

int  main(void )
{
    int j;
    SqStack s;
    ElemType e;
    if(InitStack(&s))
    {
        for(j=1; j<=N; j++)
        {
            Push(&s, j);
        }
    }
    printf("Output stack elements:");
    StackTraverse(s,visit);
    Pop(&s,&e);
    printf("Pop element e=%d\n",e);
    printf("Is stack empty:%d(1:Y 0:N)\n",StackEmpty(s));
    GetTop(s,&e);
    printf("Top element:e=%d Stack length:%d\n",e,StackLength(s));
    ClearStack(&s);
    printf("After destroying stack, is stack empty:%d(1:Y 0:N )\n",StackEmpty(s));
    DestroyStack(&s);
    printf("After destroying stack, s.top=%u s.base=%u s.stacksize=%d\n",s.top,s.base, s.stacksize);
}