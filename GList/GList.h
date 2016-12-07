//
// Created by Cooper on 15/11/2016.
//

#ifndef GLIST_GLIST_H
#define GLIST_GLIST_H

#include <ntsecapi.h>
#include "constant.h"
typedef enum{ATOM, LIST}; //ATOM == 0：原子，LIST == 1：子表
typedef int AtomType ; //
typedef struct GLNode{
    ElemType tag;// 公共部分，用于区分原子和子表
    union {
        AtomType atom; // atom 是原子结点的值域, AtomType由用户定义, 本项目中为int
        struct {struct GLNode *hp, *tp;}ptr;
        //ptr是表结点的指针域, ptr.hp, ptr.tp分别指向表头和表尾
    };//union
}*GList;
Status CreatGList(GList &L , char *S)
{
    char * emp;
    if(strcmp(S, emp)) L=NULL;
}
#endif //GLIST_GLIST_H
