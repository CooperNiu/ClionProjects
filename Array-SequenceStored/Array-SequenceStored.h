// Array-SequenceStored.h 顺序存储的数组
// 2016-11-7 16:16:23 于图书馆 陈奕迅 爱情转移
// Created by Cooper on 07/11/2016.
//

#ifndef ARRAY_SEQUENCESTORED_ARRAY_SEQUENCESTORED_H
#define ARRAY_SEQUENCESTORED_ARRAY_SEQUENCESTORED_H
//定义常数
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define UNDERFLOW 2 //总觉得得注释些什么

typedef int Status;
typedef int ElemType;
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "stdarg.h" // 标准头文件 提供va_start, va_arg. and va_end
                    // 用于存储变长参数表
#define MAX_ARRAY_DIM 8 // 假设数组维数最大值为8
typedef struct {
    ElemType *base; // 数组元素基址
    int dim; // 数组维数
    int *bounds; // 数组维界基址, 由InitArray分配
    int *constants; // 数组映像函数常量基址, 由InitArray分配
}Array;

Status InitArray(Array &A, int dim, ...)
{
    //if the dim and the latter arguments are legal, then initialize the array A, and return OK;
    /*
     * 1. 判断维度是否合法
     * 2. 为存放维界的数组开辟空间, 判断是否成功 *每次开辟空间都要判断是否成功*
     * 3. 读取可变长参数
     * 4. 为数组分配空间
     * 5. 求映像函数的常数, 并存入A.constants[i-1]
     */
    if(dim<1 || dim > MAX_ARRAY_DIM) return ERROR;
    A.dim=dim;
    A.bounds=(int *)malloc(dim* sizeof(int));
    if(!A.bounds) exit(OVERFLOW);
    // if every dim length is legal then store them in the A.bounds, then calculate the total
    // number of elements: elemtotal
    int eletotal=1;
    va_list ap;// must declare this argument before va_start(ap, l)

    va_start(ap, dim);// 读取可变长参数
    for(int i = 0; i<dim; ++i)
    {
        A.bounds[i]=va_arg(ap, int);
        if(A.bounds[i]<0) return UNDERFLOW;
        eletotal *= A.bounds[i];
    }
    va_end(ap);// 结束读取, 并让指针复位
    A.base=(ElemType*)malloc(eletotal* sizeof(ElemType));
    if(!A.base) exit(OVERFLOW);
    //求映像函数的常数c, 并存入A.constants[i-1], i=1,...dim
    A.constants=(int *)malloc(dim*sizeof(int));
    if(!A.constants) exit(OVERFLOW);
    A.constants[dim-1]=1;// L=1, 指针的增减以元素的大小为单位
    for(int i=dim-2; i>=0; --i)
    {
        A.constants[i]=A.bounds[i+1]*A.bounds[i+1];
    }
    return OK;
}

Status DestroyArray(Array &A)
{
    //销毁数组
    if(!A.base) return ERROR;
    free(A.base);   A.base = NULL;
    if(!A.bounds) return ERROR;
    free(A.bounds);   A.bounds = NULL;
    if(!A.constants) return ERROR;
    free(A.constants);   A.constants = NULL;
    return OK;
}

Status Locate(Array A, va_list ap, int &off)
{
    //若ap指示的各个下标值合法, 则求出该元素在A中的相对地址off
    off=0;
    for (int i = 0; i < A.dim; ++i) {
        int ind=va_arg(ap, int);
        if(ind<0 || ind>=A.bounds[i]) return OVERFLOW;
        off += A.constants[i]*ind;
    }
    return OK;
}

Status Value(Array A, ElemType &e, ...)
{
    //A是n维数组, e为元素变量, 随后是n个下标值
    //若各下标不超界, 则e赋值为所指定的A的元素值, 并返回OK;
    va_list ap;
    va_start(ap, e);
    int off;// 此变量的值从哪里来呢?
    int result=Locate(A, ap, off);
    if(result<=0) return result;
    e=*(A.base+off);
    va_end(ap);
    return OK;
}

Status Assign(Array &A, ElemType e, ...)
{
    //A是n维数组, e为元素变量, 随后是n个下标值
    //若下标不超界, 则将e 的值赋给所指定的A的元素, 并返回OK;
    va_list ap;
    va_start(ap, e);
    int off; //此变量的值从哪里来呢?
    int result=Locate(A, ap, off);
    if(result<=0) return result;
    *(A.base+off)=e;
    return OK;
}
#endif //ARRAY_SEQUENCESTORED_ARRAY_SEQUENCESTORED_H
