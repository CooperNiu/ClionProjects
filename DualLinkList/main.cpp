#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef char ElemType;
typedef int Status;

typedef struct DualNode{
    ElemType data;
    struct DualNode *prior;
    struct DualNode *next;
}DualNode, *DualLinkList;

Status InitList(DualLinkList &L)
{
    DualLinkList p, q;
    int i;

    L=(DualLinkList)malloc(sizeof(DualNode));
    if(!L)
        return ERROR;

    L->next=L->prior=NULL;
    p=L;

    for (int i = 0; i < 26; ++i) {
        q=(DualNode *)malloc(sizeof(DualNode));
        if(!q)
            return ERROR;
        q->data='A'+i;
        q->prior=p;
        q->next=p->next;
        p->next=q;

        p=q;
    }
    p->next=L->next; //将尾节点指向首元结点
    L->next->prior=p;

    return OK;
}

void Order(DualLinkList &L, int i)
{
    if(i>0)
        do{
            L=L->next;
        }while(--i);
    if(i<0)
        do{
            L=L->next;
        }while(++i);
}
//int main() {
//    DualLinkList L;
//    int i, n;
//
//    for (;;) {
//        InitList(L);
//        printf("\n Input a int: ");
//        scanf("%d", &n);
//        if (!n)
//            return 0;
//        Order(L, n);
//
//        for (int j = 0; j < 26; ++j) {
//            L=L->next;
//            printf("%c", L->data);
//        }
//    }
//    return 0;
//}
///二进制转换为十进制就是利用栈的后进先出的特点

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct{
    ElemType *base;
    ElemType *top;
    int StackSize;
}SqStack;
Status InitStack(SqStack *s){
    s->base=(ElemType *)malloc(STACK_INIT_SIZE* sizeof(ElemType));
    if(!s->base)    exit(ERROR);
    s->top=s->base;
    s->StackSize=STACK_INIT_SIZE;
    return OK;
}
Status Push(SqStack &s, ElemType e)
{
    if(s.top-s.base>=s.StackSize)
    {
        s.base=(ElemType*)realloc(s.base, (s.StackSize+STACKINCREMENT)* sizeof(ElemType));
        if(!s.base) exit(ERROR);
        s.top=s.base+s.StackSize;
        s.StackSize=s.StackSize+STACKINCREMENT;
    }
    *(s.top)=e;
    s.top++;
    return OK;
}
Status Pop(SqStack &s, ElemType &e)
{
    if(s.top==s.base)
        return ERROR;
    e=*--(s.top);
    return OK;
}

Status DestroyStack(SqStack &s)
{
    for (int i = 0; i < s.StackSize; ++i) {
        free(s.base);
        s.base++;
    }
    s.base=s.top=NULL;
    s.StackSize=0;
}

int StackLen(SqStack s)
{
    return (s.top-s.base); //返回的就是元素数量
}

#include <math.h>

int main()
{
    ElemType c;
    SqStack s;
    int len, i, sum=0;

    printf("Please input a binary number(# to end)\n");
    scanf("%c", c);
    while (c!='#')
    {
        Push(s, c);
        scanf("%c", &c);
    }
    getchar(); //把‘\n’从缓冲区中过滤掉

    len=StackLen(s);
    printf("stack present size is: %d", len);

    for (int j = 0; j < len; ++j) {
        Pop(s, c);
        sum += (c-48)*pow(2, i); //pow(double, double)函数求n次方
    }

    printf("the decimal number is : %d\n", sum);
    return 0;
}