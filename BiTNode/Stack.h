 /* 栈的顺序存储表示 */
 #define STACK_INIT_SIZE 10 /* 存储空间初始分配量 */
 #define STACKINCREMENT 2 /* 存储空间分配增量 */
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
 typedef int Status;
#define SqStackFun
#ifdef LinkStack
 #include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <stdio.h>
#include "Stack.h"

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
/* c2-2.h 线性表的单链表存储结构 */
 struct LNode
 {
   ElemType data;
   struct LNode *next;
 };
 typedef struct LNode *LinkList; /* 另一种定义LinkList的方法 */

 /* bo3-5.c 链栈(存储结构由c2-2.h定义)的基本操作(9个) */
 /* 大部分基本操作是由单链表线性操作及其扩展操作中的函数改名得来 */
 typedef LinkList LinkStack; /* LinkStack是指向栈结点的指针类型 */
 #define InitStack InitList /* InitStack()与InitList()作用相同，下同 */
 #define DestroyStack DestroyList
 #define ClearStack ClearList
 #define StackEmpty ListEmpty
 #define StackLength ListLength
 #define GetTop GetFirstElem
 #define Push HeadInsert
 #define Pop DeleteFirst
 /* 单链表线性表(存储结构由c2-2.h定义)的基本操作(12个) */
 Status InitList(LinkList *L)
 { /* 操作结果：构造一个空的线性表L */
   *L=(LinkList)malloc(sizeof(struct LNode)); /* 产生头结点,并使L指向此头结点 */
   if(!*L) /* 存储分配失败 */
     exit(OVERFLOW);
   (*L)->next=NULL; /* 指针域为空 */
   return OK;
 }

 Status DestroyList(LinkList *L)
 { /* 初始条件：线性表L已存在。操作结果：销毁线性表L */
   LinkList q;
   while(*L)
   {
     q=(*L)->next;
     free(*L);
     *L=q;
   }
   return OK;
 }

 Status ClearList(LinkList L) /* 不改变L */
 { /* 初始条件：线性表L已存在。操作结果：将L重置为空表 */
   LinkList p,q;
   p=L->next; /* p指向第一个结点 */
   while(p) /* 没到表尾 */
   {
     q=p->next;
     free(p);
     p=q;
   }
   L->next=NULL; /* 头结点指针域为空 */
   return OK;
 }

 Status ListEmpty(LinkList L)
 { /* 初始条件：线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
   if(L->next) /* 非空 */
     return FALSE;
   else
     return TRUE;
 }

 int ListLength(LinkList L)
 { /* 初始条件：线性表L已存在。操作结果：返回L中数据元素个数 */
   int i=0;
   LinkList p=L->next; /* p指向第一个结点 */
   while(p) /* 没到表尾 */
   {
     i++;
     p=p->next;
   }
   return i;
 }

 Status GetElem(LinkList L,int i,ElemType *e) /* 算法2.8 */
 { /* L为带头结点的单链表的头指针。当第i个元素存在时,其值赋给e并返回OK,否则返回ERROR */
   int j=1; /* j为计数器 */
   LinkList p=L->next; /* p指向第一个结点 */
   while(p&&j<i) /* 顺指针向后查找,直到p指向第i个元素或p为空 */
   {
     p=p->next;
     j++;
   }
   if(!p||j>i) /* 第i个元素不存在 */
     return ERROR;
   *e=p->data; /* 取第i个元素 */
   return OK;
 }

 int LocateElem(LinkList L,ElemType e,Status(*compare)(ElemType,ElemType))
 { /* 初始条件: 线性表L已存在,compare()是数据元素判定函数(满足为1,否则为0) */
   /* 操作结果: 返回L中第1个与e满足关系compare()的数据元素的位序。 */
   /*           若这样的数据元素不存在,则返回值为0 */
   int i=0;
   LinkList p=L->next;
   while(p)
   {
     i++;
     if(compare(p->data,e)) /* 找到这样的数据元素 */
       return i;
     p=p->next;
   }
   return 0;
 }

 Status PriorElem(LinkList L,ElemType cur_e,ElemType *pre_e)
 { /* 初始条件: 线性表L已存在 */
   /* 操作结果: 若cur_e是L的数据元素,且不是第一个,则用pre_e返回它的前驱, */
   /*           返回OK;否则操作失败,pre_e无定义,返回INFEASIBLE */
   LinkList q,p=L->next; /* p指向第一个结点 */
   while(p->next) /* p所指结点有后继 */
   {
     q=p->next; /* q为p的后继 */
     if(q->data==cur_e)
     {
       *pre_e=p->data;
       return OK;
     }
     p=q; /* p向后移 */
   }
   return INFEASIBLE;
 }

 Status NextElem(LinkList L,ElemType cur_e,ElemType *next_e)
 { /* 初始条件：线性表L已存在 */
   /* 操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继， */
   /*           返回OK;否则操作失败，next_e无定义，返回INFEASIBLE */
   LinkList p=L->next; /* p指向第一个结点 */
   while(p->next) /* p所指结点有后继 */
   {
     if(p->data==cur_e)
     {
       *next_e=p->next->data;
       return OK;
     }
     p=p->next;
   }
   return INFEASIBLE;
 }

 Status ListInsert(LinkList L,int i,ElemType e) /* 算法2.9。不改变L */
 { /* 在带头结点的单链线性表L中第i个位置之前插入元素e */
   int j=0;
   LinkList p=L,s;
   while(p&&j<i-1) /* 寻找第i-1个结点 */
   {
     p=p->next;
     j++;
   }
   if(!p||j>i-1) /* i小于1或者大于表长 */
     return ERROR;
   s=(LinkList)malloc(sizeof(struct LNode)); /* 生成新结点 */
   s->data=e; /* 插入L中 */
   s->next=p->next;
   p->next=s;
   return OK;
 }

 Status ListDelete(LinkList L,int i,ElemType *e) /* 算法2.10。不改变L */
 { /* 在带头结点的单链线性表L中，删除第i个元素,并由e返回其值 */
   int j=0;
   LinkList p=L,q;
   while(p->next&&j<i-1) /* 寻找第i个结点,并令p指向其前趋 */
   {
     p=p->next;
     j++;
   }
   if(!p->next||j>i-1) /* 删除位置不合理 */
     return ERROR;
   q=p->next; /* 删除并释放结点 */
   p->next=q->next;
   *e=q->data;
   free(q);
   return OK;
 }

 Status ListTraverse(LinkList L,void(*vi)(ElemType))
 /* vi的形参类型为ElemType，与bo2-1.c中相应函数的形参类型ElemType&不同 */
 { /* 初始条件：线性表L已存在 */
   /* 操作结果:依次对L的每个数据元素调用函数vi()。一旦vi()失败,则操作失败 */
   LinkList p=L->next;
   while(p)
   {
     vi(p->data);
     p=p->next;
   }
   printf("\n");
   return OK;
 }

 /* 单链表线性表(存储结构由c2-2.h定义)的扩展操作(11个) */
 void InsertAscend(LinkList L,ElemType e)
 { /* 初始条件：按非降序排列的线性表L已存在。操作结果：在L中按非降序插入新的数据元素e */
   LinkList q=L,p=L->next;
   while(p&&e>p->data)
   {
     q=p;
     p=p->next;
   }
   q->next=(LinkList)malloc(sizeof(struct LNode)); /* 插在q后 */
   q->next->data=e;
   q->next->next=p;
 }

 void InsertDescend(LinkList L,ElemType e)
 { /* 初始条件：按非升序排列的线性表L已存在。操作结果：在L中按非升序插入新的数据元素e */
   LinkList q=L,p=L->next;
   while(p&&e<p->data)
   {
     q=p;
     p=p->next;
   }
   q->next=(LinkList)malloc(sizeof(struct LNode)); /* 插在q后 */
   q->next->data=e;
   q->next->next=p;
 }

 Status HeadInsert(LinkList L,ElemType e)
 { /* 初始条件：线性表L已存在。操作结果：在L的头部插入新的数据元素e,作为链表的第一个元素 */
   LinkList s;
   s=(LinkList)malloc(sizeof(struct LNode)); /* 生成新结点 */
   s->data=e; /* 给结点赋值 */
   s->next=L->next; /* 插在表头 */
   L->next=s;
   return OK;
 }

 Status EndInsert(LinkList L,ElemType e)
 { /* 初始条件：线性表L已存在。操作结果：在L的尾部插入新的数据元素e,作为链表的最后一个元素 */
   LinkList p=L;
   while(p->next) /* 使p指向表尾元素 */
     p=p->next;
   p->next=(LinkList)malloc(sizeof(struct LNode)); /* 在表尾生成新结点 */
   p->next->data=e; /* 给新结点赋值 */
   p->next->next=NULL; /* 表尾 */
   return OK;
 }

 Status DeleteFirst(LinkList L,ElemType *e)
 { /* 初始条件：线性表L已存在，且有不少于1个元素 */
   /* 操作结果：删除L的第一个数据元素，并由e返回其值 */
   LinkList p=L->next;
   if(p)
   {
     *e=p->data;
     L->next=p->next;
     free(p);
     return OK;
   }
   else
     return ERROR;
 }

 Status DeleteTail(LinkList L,ElemType *e)
 { /* 初始条件：线性表L已存在，且有不少于1个元素 */
   /* 操作结果：删除L的最后一个数据元素，并用e返回其值 */
   LinkList p=L,q;
   if(!p->next) /* 链表为空 */
     return ERROR;
   while(p->next)
   {
     q=p;
     p=p->next;
   }
   q->next=NULL; /* 新尾结点的next域设为NULL */
   *e=p->data;
   free(p);
   return OK;
 }

 Status DeleteElem(LinkList L,ElemType e)
 { /* 删除表中值为e的元素，并返回TRUE；如无此元素，则返回FALSE */
   LinkList p=L,q;
   while(p)
   {
     q=p->next;
     if(q&&q->data==e)
     {
       p->next=q->next;
       free(q);
       return TRUE;
     }
     p=q;
   }
   return FALSE;
 }

 Status ReplaceElem(LinkList L,int i,ElemType e)
 { /* 用e取代表L中第i个元素的值 */
   LinkList p=L;
   int j=0;
   while(p->next&&j<i)
   {
     j++;
     p=p->next;
   }
   if(j==i)
   {
     p->data=e;
     return OK;
   }
   else /* 表中不存在第i个元素 */
     return ERROR;
 }

 Status CreatAscend(LinkList *L,int n)
 { /* 按非降序建立n个元素的线性表 */
   int j;
   LinkList p,q,s;
   if(n<=0)
     return ERROR;
   InitList(L);
   printf("请输入%d个元素:\n",n);
   s=(LinkList)malloc(sizeof(struct LNode)); /* 第一个结点 */
   scanf("%d",&s->data);
   s->next=NULL;
   (*L)->next=s;
   for(j=1;j<n;j++)
   {
     s=(LinkList)malloc(sizeof(struct LNode)); /* 其余结点 */
     scanf("%d",&s->data);
     q=*L;
     p=(*L)->next;
     while(p&&p->data<s->data) /* p没到表尾，且所指元素值小于新值 */
     {
       q=p;
       p=p->next; /* 指针后移 */
     }
     s->next=q->next; /* 元素插在q的后面 */
     q->next=s;
   }
   return OK;
 }

 Status CreatDescend(LinkList *L,int n)
 { /* 按非升序建立n个元素的线性表 */
   int j;
   LinkList p,q,s;
   if(n<=0)
     return ERROR;
   InitList(L);
   printf("请输入%d个元素:\n",n);
   s=(LinkList)malloc(sizeof(struct LNode)); /* 第一个结点 */
   scanf("%d",&s->data);
   s->next=NULL;
   (*L)->next=s;
   for(j=1;j<n;j++)
   {
     s=(LinkList)malloc(sizeof(struct LNode)); /* 其余结点 */
     scanf("%d",&s->data);
     q=*L;
     p=(*L)->next;
     while(p&&p->data>s->data) /* p没到表尾，且所指元素值大于新值 */
     {
       q=p;
       p=p->next; /* 指针后移 */
     }
     s->next=q->next; /* 元素插在q的后面 */
     q->next=s;
   }
   return OK;
 }

 Status GetFirstElem(LinkList L,ElemType *e)
 { /* 返回表头元素的值 */
   LinkList p=L->next;
   if(!p) /* 空表 */
     return ERROR;
   else /* 非空表 */
     *e=p->data;
   return OK;
 }


 Status StackTraverse(LinkStack S,void(*visit)(SElemType))
 { /* 从栈底到栈顶依次对栈中每个元素调用函数visit()。 */
   SElemType e;
   LinkStack temp,p=S;
   InitStack(&temp); /* 初始化temp栈 */
   while(p->next)
   {
     GetTop(p,&e);
     Push(temp,e);
     p=p->next;
   }
   ListTraverse(temp,visit);
   return OK;
 }

#endif
#ifdef SqStackFun
 /// 在二叉树的调用其他数据结构(栈, 队列...)时候, 需要在
 typedef BiTree SElemType ; /* 设栈元素为二叉树的指针类型 */
// typedef  int ElemType, SElemType ;
//typedef ElemType SElemType; /* 栈结点类型和链表结点类型一致 */
typedef struct  SqStack{
   SElemType *base; /* 在栈构造之前和销毁之后，base的值为NULL */
   SElemType *top; /* 栈顶指针 */
   int stacksize; /* 当前已分配的存储空间，以元素为单位 */
 }SqStack; /* 顺序栈 */
 
/* 顺序栈（存储结构由c3-1.h定义）的基本操作（9个） */
 Status InitStack(SqStack &S)
 { /* 构造一个空栈S */
   S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
   if(!S.base)
     exit(OVERFLOW); /* 存储分配失败 */
   S.top=S.base;
   S.stacksize=STACK_INIT_SIZE;
   return OK;
 }

 Status DestroyStack(SqStack &S)
 { /* 销毁栈S，S不再存在 */
   free(S.base);
   S.base=NULL;
   S.top=NULL;
   S.stacksize=0;
   return OK;
 }

 Status ClearStack(SqStack &S)
 { /* 把S置为空栈 */
   S.top=S.base;
   return OK;
 }

 Status StackEmpty(SqStack S)
 { /* 若栈S为空栈，则返回TRUE，否则返回FALSE */
   if(S.top==S.base)
     return TRUE;
   else
     return FALSE;
 }

 int StackLength(SqStack S)
 { /* 返回S的元素个数，即栈的长度 */
   return S.top-S.base;
 }

 Status GetTop(SqStack S,SElemType &e)
 { /* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
   if(S.top>S.base)
   {
     e=*(S.top-1);
     return OK;
   }
   else
     return ERROR;
 }

 Status Push(SqStack &S,SElemType e)
 { /* 插入元素e为新的栈顶元素 */
   if(S.top-S.base>=S.stacksize) /* 栈满，追加存储空间 */
   {
     S.base=(SElemType *)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
     if(!S.base)
       exit(OVERFLOW); /* 存储分配失败 */
     S.top=S.base+S.stacksize;
     S.stacksize+=STACKINCREMENT;
   }
   *(S.top)++=e;
//     (S.top++)=e;
     return OK;
 }

 Status Pop(SqStack &S,SElemType &e)
 { /* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
   if(S.top==S.base)
     return ERROR;
   e=*--S.top;
   return OK;
 }

 Status StackTraverse(SqStack S,Status(*visit)(SElemType*))
 { /* 从栈底到栈顶依次对栈中每个元素调用函数visit()。 */
   /* 一旦visit()失败，则操作失败 */
   while(S.top>S.base)
     visit(S.base++);
   printf("\n");
   return OK;
 }

 Status visit(SElemType s)
 {
     printf("%d ", s);
     return OK;
 }
#endif