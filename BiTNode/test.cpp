//
// Created by Cooper on 24/12/2016.
//
#include <stdio.h>
#include <stdlib.h>
typedef char ElemType;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;


// ����һ�ö�����, Ĭ������
int CreateBiTree(BiTree *T)
{
    char c;
    scanf("%c", c);
    if(' ' == c){
        *T = (BiTNode *)malloc(sizeof(BiTNode));
        (*T)->data=c;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}