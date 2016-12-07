//
// Created by Cooper on 29/11/2016.
//

#ifndef HUFFMANTREE_HUFFMANTREE_H
#define HUFFMANTREE_HUFFMANTREE_H
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;
typedef int ElemType;

typedef struct {
    unsigned int weight;  //1. 编码的权值, 在构造赫夫曼树的时候; 2. 标志域, 在求赫夫曼编码的时候
    unsigned int parent, lchild, rchild; // 存储的值是一维数组的存储位置, 起到了指针的作用, 类似于静态链表
}HTNode, *HuffmanTree; //动态分配数组存储赫夫曼树

typedef char **HuffmanCode; // 动态分配数组存储赫夫曼树编码表

int min1(HuffmanTree t,int i);
void select(HuffmanTree t,int i,int *s1,int *s2);
void HuffmanCoding(HuffmanTree *HT,HuffmanCode *HC,int *w,int n);
#endif //HUFFMANTREE_HUFFMANTREE_H
