//
// Created by Cooper on 20/10/2016.
//

/* c2-1.h 线性表的动态分配顺序存储结构 */
#define LIST_INIT_SIZE 10 /* 线性表存储空间的初始分配量 */
#define LISTINCREMENT 2 /* 线性表存储空间的分配增量 */
typedef struct
{
    ElemType *elem; /* 存储空间基址 */
    int length; /* 当前长度 */
    int listsize; /* 当前分配的存储容量(以sizeof(ElemType)为单位) */
}SqList;
