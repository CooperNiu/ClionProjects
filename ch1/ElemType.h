//
// Created by Cooper on 21/10/2016.
//
/* ElementType.h 定义ElementType和函数声明  */
#ifndef CH1_ELEMTYPE_H
#define CH1_ELEMTYPE_H
/* 采用动态分配的顺序存储结构 */
typedef ElemType *Triplet; /* 由InitTriplet分配三个元素存储空间 */
/* Triplet类型是ElemType类型的指针，存放ElemType类型的地址 */
Status InitTriplet(Triplet *T,ElemType v1,ElemType v2,ElemType v3);//初始化三元组
Status DestroyTriplet(Triplet *T);//销毁
Status Get(Triplet T,int i, ElemType *e);//
Status Put(Triplet T,int i,ElemType e);
Status IsAscending(Triplet T);
Status IsDescending(Triplet T);
Status Max(Triplet T,ElemType *e);
Status Min(Triplet T,ElemType *e);

#endif //CH1_ELEMTYPE_H
