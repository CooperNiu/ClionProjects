//
// Created by Cooper on 16/11/2016.
// 2016年11月23日20:17:37 调试bug
/// bug: 在调用stack.h的函数时候, BiTree类型无法转换成SqElemType
/// 解决办法: 把typedef BiTree SElemType ; /* 设栈元素为二叉树的指针类型 */ 放到stack.h头文件中
#ifndef BITNODE_BITNODE_H
#define BITNODE_BITNODE_H
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
/* 这里有一种很好的定义两种数据类型的方法，可以由程序员自己选择
 */
#define CHAR /* 字符型 */
/* #define INT /* 整型（二者选一） */
#ifdef CHAR
typedef char TElemType;
TElemType Nil=' '; /* 字符型以空格符为空 */
#endif
#ifdef INT
typedef int TElemType;
   TElemType Nil=0; /* 整型以0为空 */
#endif
typedef int Status;
//二叉树的顺序存储表示
//#define MAX_TREE_SIZE 100 //二叉树的最大节点数
//typedef TElemType SqBiTree[MAX_TREE_SIZE+1];//0号单元空闲，1号单元存储根节点
//SqBiTree bt;

//二叉树的二叉链表存储表示
typedef struct BiTNode{
    TElemType data;
    struct BiTNode *lchild, *rchild;//左右孩子指针
}BiTNode, *BiTree;
Status Visit(TElemType e)
{
    #ifdef CHAR
        printf("%c ",e);
    #endif
    #ifdef INT
        printf("%d ",e);
    #endif
        return OK;
}
//// 最简单的Visit函数是
//Status PrintElem(TElemType e){
//    printf("%d", e); //这里可以是其他的访问元素的函数
//    return OK;
//}
Status InitBiTree(BiTree &T)
{// 构造空二叉树T
    T=NULL;
    return OK;
}
Status CreateBiTree(BiTree &T)
{/* 算法6.4 按先序次序输入二叉树中结点的值（一个字符）， 空格字符表示空树
 * 构造二叉树表表示的二叉树T
  */
    TElemType ch; //二叉树的结点类型由宏定义声明, 之后的类型定义时候直接用TElemType
#ifdef CHAR
    scanf("%c",&ch);
#endif
#ifdef INT
    scanf("%d",&ch);
#endif
    if(ch==Nil) T=NULL; //空表
    else{
        T=(BiTree)malloc(sizeof(BiTree));
        if(!T)  exit(OVERFLOW);
        T->data=ch; //生成根结点
        CreateBiTree(T->lchild); /* 构造左子树 */
        CreateBiTree(T->rchild); /* 构造右子树 */
    }//else
}
Status DestroyBiTree(BiTree &T)
{/* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
    if(T) /* 非空树 */
    {
        if(T->lchild) /* 有左孩子 */
            DestroyBiTree(T->lchild); /* 销毁左孩子子树 */
        if(T->rchild) /* 有右孩子 */
            DestroyBiTree(T->rchild); /* 销毁右孩子子树 */
        free(T); /* 释放根结点 */
        T=NULL; /* 空指针赋0 */
    }
}
Status BiTreeEmpty(BiTree T)
{ /* 初始条件: 二叉树T存在 */
  /* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
    if(T)
        return FALSE;
    else
        return TRUE;
}

#define ClearBiTree DestroyBiTree

int BiTreeDepth(BiTree T)
{ /* 初始条件: 二叉树T存在。操作结果: 返回T的深度
 * 感想 : 递归算法博大精深, 用了二十分钟终于弄明白了, 看着语句简短, 实则内容丰富 , 有趣
 */
    int i,j;
    if(!T)
        return 0;
    if(T->lchild)
        i=BiTreeDepth(T->lchild);
    else
        i=0;
    if(T->rchild)
        j=BiTreeDepth(T->rchild);
    else
        j=0;
    return i>j?i+1:j+1; //返回左右树中的较大的深度值
}
TElemType Root(BiTree T)
{ /* 初始条件: 二叉树T存在。操作结果: 返回T的根 */
    if(BiTreeEmpty(T))
        return Nil;
    else
        return T->data;
}
TElemType Value(BiTree p)
{ /* 初始条件: 二叉树T存在，p指向T中某个结点 */
    /* 操作结果: 返回p所指结点的值 */
    return p->data;
}
void Assign(BiTree p,TElemType value)
{ /* 给p所指结点赋值为value */
    p->data=value;
}

typedef BiTree QElemType;/* 设队列元素为二叉树的指针类型 */
#include "Queue.h" //用的是自己的队列头文件

TElemType Parent(BiTree T, TElemType e)
{/* 初始条件: 二叉树T存在,e是T中某个结点 */
    /* 操作结果: 若e是T的非根结点,则返回它的双亲,否则返回＂空＂ */
    LinkQueue q;
    QElemType a;
    if(T){
        /* 非空树 */
        InitQueue(q); //初始化对列 用队列来存储每次读取的元素
        EnQueue(q, T); //树根入队
        while(!QueueEmpty(q)) /* 队不空 */
        {
            DeQueue(q, a); /* 出队,队列元素赋给a */
            if(a->lchild&&a->lchild->data==e||a->rchild&&a->rchild->data==e)
                /* 找到e(是其左或右孩子) */
                return a->data; /* 返回e的双亲的值 */
            else /* 没找到e,则入队其左右孩子指针(如果非空) */
            {
                if(a->lchild)
                    EnQueue(q,a->lchild);
                if(a->rchild)
                    EnQueue(q,a->rchild);
            }//else
        }//while
    }//if
    return Nil; //树空或没找到e
}
BiTree Point(BiTree T,TElemType s)
{ /* 返回二叉树T中指向元素值为s的结点的指针。另加 */
    LinkQueue q;
    QElemType a;
    if(T) /* 非空树 */
    {
        InitQueue(q); /* 初始化队列 */
        EnQueue(q,T); /* 根结点入队 */
        while(!QueueEmpty(q)) /* 队不空 */
        {
            DeQueue(q,a); /* 出队,队列元素赋给a */
            if(a->data==s)
                return a;
            if(a->lchild) /* 有左孩子 */
                EnQueue(q,a->lchild); /* 入队左孩子 */
            if(a->rchild) /* 有右孩子 */
                EnQueue(q,a->rchild); /* 入队右孩子 */
        }
    }
    return NULL;
}
TElemType LeftChild(BiTree T,TElemType e)
{ /* 初始条件: 二叉树T存在,e是T中某个结点 */
    /* 操作结果: 返回e的左孩子。若e无左孩子,则返回＂空＂ */
    BiTree a;
    if(T) /* 非空树 */
    {
        a=Point(T,e); /* a是结点e的指针 */
        if(a&&a->lchild) /* T中存在结点e且e存在左孩子 */
            return a->lchild->data; /* 返回e的左孩子的值 */
    }
    return Nil; /* 其余情况返回空 */
}

TElemType RightChild(BiTree T,TElemType e)
{ /* 初始条件: 二叉树T存在,e是T中某个结点 */
    /* 操作结果: 返回e的右孩子。若e无右孩子,则返回＂空＂ */
    BiTree a;
    if(T) /* 非空树 */
    {
        a=Point(T,e); /* a是结点e的指针 */
        if(a&&a->rchild) /* T中存在结点e且e存在右孩子 */
            return a->rchild->data; /* 返回e的右孩子的值 */
    }
    return Nil; /* 其余情况返回空 */
}
TElemType LeftSibling(BiTree T,TElemType e)
{ /* 初始条件: 二叉树T存在,e是T中某个结点 */
    /* 操作结果: 返回e的左兄弟。若e是T的左孩子或无左兄弟,则返回＂空＂ */
    TElemType a;
    BiTree p;
    if(T) /* 非空树 */
    {
        a=Parent(T,e); /* a为e的双亲 */
        p= Point(T,a); /* p为指向结点a的指针 */
        if(p->lchild&&p->rchild&&p->rchild->data==e) /* p存在左右孩子且右孩子是e */
            return p->lchild->data; /* 返回p的左孩子(e的左兄弟) */
    }
    return Nil; /* 树空或没找到e的左兄弟 */
}

TElemType RightSibling(BiTree T,TElemType e)
{ /* 初始条件: 二叉树T存在,e是T中某个结点 */
  /* 操作结果: 返回e的右兄弟。若e是T的右孩子或无右兄弟,则返回＂空＂ */
    TElemType a;
    BiTree p;
    if(T) /* 非空树 */
    {
        a=Parent(T,e); /* a为e的双亲 */
        p=Point(T,a); /* p为指向结点a的指针 */
        if(p->lchild&&p->rchild&&p->lchild->data==e) /* p存在左右孩子且左孩子是e */
            return p->rchild->data; /* 返回p的右孩子(e的右兄弟) */
    }
    return Nil; /* 树空或没找到e的右兄弟 */
}
Status InsertChild(BiTree p,int LR,BiTree c) /* 形参T无用 */
{ /* 初始条件: 二叉树T存在,p指向T中某个结点,LR为0或1,非空二叉树c与T
   *           不相交且右子树为空 */
    /* 操作结果: 根据LR为0或1,插入c为T中p所指结点的左或右子树。p所指结点的 */
    /*           原有左或右子树则成为c的右子树 */
    if(p) /* p不空 */
    {
        if(LR==0)
        {
            c->rchild=p->lchild;
            p->lchild=c;
        }
        else /* LR==1 */
        {
            c->rchild=p->rchild;
            p->rchild=c;
        }
        return OK;
    }
    return ERROR; /* p空 */
}

///这里是2016-11-16 22:30:37晚上未修改和熟悉的代码
/// 2016-11-17 15:04:59开始修改  2016-11-17 16:54:34暂停修改
Status DeleteChild(BiTree &p,int LR) /* 形参T无用 */
{ /* 初始条件: 二叉树T存在,p指向T中某个结点,LR为0或1 */
    /* 操作结果: 根据LR为0或1,删除T中p所指结点的左或右子树 */
    if(p) /* p不空 */
    {
        if(LR==0) /* 删除左子树 */
            ClearBiTree(p->lchild);
        else /* 删除右子树 */
            ClearBiTree(p->rchild);
        return OK;
    }
    return ERROR; /* p空 */
}
Status PreOrderTraverse(BiTree &T, Status (* Visit)(TElemType e))
{// 采用二叉链表存储结构， Visit是对元素操作的应用函数
    // 先序遍历二叉树T的递归函数，对每个数据元素调用函数Visit
    /* 初始条件: 二叉树T存在,Visit是对结点操作的应用函数。算法6.1，有改动 */
    /* 操作结果: 先序递归遍历T,对每个结点调用函数Visit一次且仅一次 */
    if(T){
        if(Visit(T->data)) // 先访问根结点
            if(PreOrderTraverse(T->lchild, Visit)) // 先序遍历左子树
                if(PreOrderTraverse(T->rchild, Visit)) return OK; //先序遍历右子树
        return ERROR;
    }  else return OK;
}//PreOrderTraverse
Status InOrderTraverse(BiTree T, Status(*Visit)(TElemType))
{ /* 初始条件: 二叉树T存在,Visit是对结点操作的应用函数 */
    /* 操作结果: 中序递归遍历T,对每个结点调用函数Visit一次且仅一次 */
    if(T)
    {
        if(InOrderTraverse(T->lchild,Visit)) /* 先中序遍历左子树 */
            if(Visit(T->data)) /* 再访问根结点 */
            	if(InOrderTraverse(T->rchild,Visit)) 			return OK; /* 最后中序遍历右子树 */
        return ERROR;
    }
	else return OK;
}
Status LastOrderTraverse(BiTree T, Status(*Visit)(TElemType))
{ /* 初始条件: 二叉树T存在,Visit是对结点操作的应用函数 */
    /* 操作结果: 后序递归遍历T,对每个结点调用函数Visit一次且仅一次 */
    if(T)
    {
        if(LastOrderTraverse(T->lchild,Visit)) /* 后序遍历左子树 */
            if(InOrderTraverse(T->rchild,Visit)) 			return OK; /* 后序遍历右子树 */
                if(Visit(T->data)) /* 再访问根结点 */
        return ERROR;
    }
    else return OK;
}
#include "Stack.h"
Status InOrderTraverse1(BiTree &T,Status(*Visit)(TElemType))
{ /* 采用二叉链表存储结构，Visit是对数据元素操作的应用函数。算法6.3 */
    /* 中序遍历二叉树T的非递归算法(利用栈)，对每个数据元素调用函数Visit */
    SqStack S;
    InitStack(S);
    while(T||!StackEmpty(S))
    {
        if(T)
        { /* 根指针进栈,遍历左子树 */
            Push(S, T);
            T=T->lchild;
        }
        else
        { /* 根指针退栈,访问根结点,遍历右子树 */
            Pop(S, T);
            if(!Visit(T->data))
                return ERROR;
            T=T->rchild;
        }
    }
    printf("\n");
    return OK;
}
Status InOrderTraverse2(BiTree T,Status(*Visit)(TElemType))
{ /* 采用二叉链表存储结构，Visit是对数据元素操作的应用函数。算法6.2 */
    /* 中序遍历二叉树T的非递归算法(利用栈)，对每个数据元素调用函数Visit */
    SqStack S;
    BiTree p;
    InitStack(S);
    Push(S,T); /* 根指针进栈 */
    while(!StackEmpty(S))
    {
        while(GetTop(S,p)&&p)
            Push(S,p->lchild); /* 向左走到尽头 */
        Pop(S,p); /* 空指针退栈 */
        if(!StackEmpty(S))
        { /* 访问结点,向右一步 */
            Pop(S,p);
            if(!Visit(p->data))
                return ERROR;
            Push(S,p->rchild);
        }
    }
    printf("\n");
    return OK;
}
//Status InOrderTraverse2(BiTree T, Status (*Visit)(TElemType))
//{/* 中序遍历的非递归算法, 对每个元素调用Visit函数 算法6.3
// *  采用二叉链表存储结构, Visit是对数据元素操作的应用函数
// */
//    SqStack S;
//    InitStack(S);
//    BiTree p=T;// 临时变量存储T, 便于判断二叉树是否为空
//    while (p||!StackEmpty(S))
//    {
//        if(p){ //多了判断指针是否为空的语句, 避免了空指针进栈
//            Push(S, p); //root pointer gets in stack
//            p=p->lchild; // traverse left subtree
//        }//if
//        else{// root pointer pops, visit root element, traverse right subtree
//            Pop(S, p);
//            if(!Visit(p->data)) return ERROR;
//            p=p->rchild;
//        }//else
//    }//while
//    printf("\n");
//    return OK;
//}// InOrderTraverse
////void InorderTraverse(BiTree &T)
////{
////    SqStack S;
////    BiTree p=T;  // 临时变量存储T, 便于判断二叉树是否为空
////    InitStack(S); Push(S,T);
////    while(!StackEmpty(S))
////    {  while(GetTop(S,p)&&p)    Push(S,p->lchild);
////        Pop(S,p); // 弹出最后压入的空指针
////        if(!StackEmpty(S))
////        {
////            Pop(S,p);
////            visit(p->data);///\\bug 在其他函数中调用时候, 没有定义临时变量就可以成功传参
////            Push(S,p->rchild);
////        }
////    }
////} //InOrderTraverse
void LevelOrderTraverse(BiTree T,Status(*Visit)(TElemType))
{ /* 初始条件：二叉树T存在,Visit是对结点操作的应用函数 */
    /* 操作结果：层序递归遍历T(利用队列),对每个结点调用函数Visit一次且仅一次 */
    LinkQueue q;
    QElemType a;
    if(T)
    {
        InitQueue(q);
        EnQueue(q,T);
        while(!QueueEmpty(q))
        {
            DeQueue(q, a);
            Visit(a->data);
            if(a->lchild!=NULL)
                EnQueue(q, a->lchild);
            if(a->rchild!=NULL)
                EnQueue(q, a->rchild);
        }
        printf("\n");
    }
}
//利用遍历判断两棵二叉树是否相等。
Status Equal(BiTree T1,BiTree T2)
{	if(T1==NULL && T2==NULL) return TRUE; //当两棵树都是空, 一定相等
    else if(T1==NULL||T2==NULL) return FALSE; // 当两棵树一棵空, 一棵不空, 一定不相等
    else // 两棵树都不空
    {   if(T1->data==T2->data) //先序遍历
            if(Equal(T1->lchild,T2->lchild)) // 递归遍历两棵左子树
                if(Equal(T1->rchild,T2->rchild)) // 递归遍历两棵右子树
                    /// 三个里有一个不真就 return False, 有return语句的就是递归的出口函数
                    return TRUE;
        return FALSE;
    }
}
BiTree count_k(BiTree T, int &k)
{/*
 * 求第k个结点的值
 */
    BiTree p;
    if(!T || k<=0) return NULL;
    k--;
    if (k==0) return T;
    if (p=count_k(T->lchild, k)) return p;
    else return count_k(T->rchild, k);
}// count_k
Status Loc_k(BiTree T, int k, TElemType &e)
{ /*
 * 定位第k个结点, 成功返回OK, 否则ERROR
 */
    BiTree  p=count_k(T,k);
    if(p)
    {
        e=p->data;
        return OK;
    }
    else return ERROR;
}// Loc_k
//删除二叉树中所有以值为x的结点为根的子树并释放相应空间。
void delsubtree(BiTree T)
{
    if(T){
        delsubtree(T->lchild);
        delsubtree(T->rchild);
        free(T);
    }//if
}//delsubtree
void DelTree(BiTree &T,TElemType x)
{
    if(T)
    {
        if (T->data==x) // 比较
        {
            delsubtree(T); // 删以T为根的子树
            T=NULL; // 手动将T变为空指针
        }
        else
        {
            DelTree(T->lchild,x);
            DelTree(T->rchild,x);
        }
    }//if
}//DelTree

#endif //BITNODE_BITNODE_H