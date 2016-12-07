// SparseMatrix.h 存储稀疏矩阵的ADT
// Created by Cooper on 09/11/2016.
// 2016-11-9 18:55:29

#ifndef SPARSEMATRIX_SPARSEMATRIX_H
#define SPARSEMATRIX_SPARSEMATRIX_H

#include "stdio.h"
#include "stdlib.h"
//定义常数
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

#define MAXSIZE 1000 // 假设非零元个数最大值

typedef int Status;
typedef int ElemType;
typedef struct {
    int i, j; // 非零元行, 列下标
    ElemType e;
}Triple;
typedef struct {
    Triple data[MAXSIZE+1]; //非零元三元组表, data[0]未用, 所以 MAXSIZE+1
    int mu, nu, tu; //矩阵的行数, 列数和非零元个数
}TSMatrix;
/* 三元组稀疏矩阵的基本操作,包括算法5.1(9个) */
Status CreateSMatrix(TSMatrix &M)
{ /* 创建稀疏矩阵M */
    int i,m,n;
    ElemType e;
    Status k; //记录状态(输入的元素位置是否合法)
//    printf("请输入矩阵的行数,列数,非零元素数：");
    printf("Please input the RowLen, ColLen and NoneZeroEleNum");
    scanf("%d%d%d",&M.mu,&M.nu,&M.tu);
    M.data[0].i=0; /* 为以下比较顺序做准备 */
    for(i=1;i<=M.tu;i++)
    {
        do
        {//当输入的元素位置不合法时, 不会将元素值存入数组中, 而要求重新输入
//          printf("请按行序顺序输入第%d个非零元素所在的行(1～%d),列(1～%d),元素值：",i,M.mu,M.nu);
            printf("Input NO.%d Elem (based on row-major order, Row(1--%d), Column(1--%d)), ElemData:",i,M.mu,M.nu);
            scanf("%d%d%d",&m,&n,&e);
            k=0;
            if(m<1||m>M.mu||n<1||n>M.nu) /* 行或列超出范围 */
                k=1;
            if(m<M.data[i-1].i||m==M.data[i-1].i&&n<=M.data[i-1].j) /* 行或列的顺序有错 */
                k=1;
        }while(k);
        M.data[i].i=m;
        M.data[i].j=n;
        M.data[i].e=e;
    }
    return OK;
}
void DestroySMatrix(TSMatrix &M)
{ /* 销毁稀疏矩阵M */
    M.mu=0;
    M.nu=0;
    M.tu=0;
}
void MatrixEmpty(TSMatrix M)
{
    //判断矩阵是否为空
    if(!M.mu || !M.nu || !M.tu)//有一个是0 数组就为空
        printf("Empty\n");
    else
        printf("Not Empty\n");
}
void PrintSMatrix(TSMatrix M)
{ /* 输出稀疏矩阵M */
    int i;
    printf("%dRow(s) %dColumn(s) %d NoneZeroElem(s)\n",M.mu,M.nu,M.tu);
    printf("Row Column ElemData\n");
    for(i=1;i<=M.tu;i++)
        printf("%2d%4d%8d\n",M.data[i].i,M.data[i].j,M.data[i].e);
}
Status CopySMatrix(TSMatrix M,TSMatrix &T)
{ /* 由稀疏矩阵M复制得到T */
    T=M;
    return OK;
}
int comp(int c1,int c2) /* 另加 */
{ /* AddSMatrix函数要用到 */
    int i;
    if(c1<c2)
        i=1;
    else if(c1==c2)
        i=0;
    else
        i=-1;
    return i;
}
Status AddSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
{ /* 求稀疏矩阵的和Q=M+N */
    Triple *Mp,*Me,
            *Np,*Ne,
            *Qh,*Qe;
    if(M.mu!=N.mu)//输入不合法
        return ERROR;
    if(M.nu!=N.nu)
        return ERROR;
    Q.mu=M.mu;//将
    Q.nu=M.nu;
    Mp=&M.data[1]; /* Mp的初值指向矩阵M的非零元素首地址 */
    Np=&N.data[1]; /* Np的初值指向矩阵N的非零元素首地址 */
    Me=&M.data[M.tu]; /* Me指向矩阵M的非零元素尾地址 */
    Ne=&N.data[N.tu]; /* Ne指向矩阵N的非零元素尾地址 */
    Qh=Qe=Q.data; /* Qh、Qe的初值指向矩阵Q的非零元素首地址的前一地址 */
    while(Mp<=Me&&Np<=Ne)
    {
        Qe++;
        switch(comp(Mp->i,Np->i))
        {
            case  1: *Qe=*Mp;
                Mp++;
                break;
            case  0: switch(comp(Mp->j,Np->j)) /* M、N矩阵当前非零元素的行相等,继续比较列 */
                {
                    case  1: *Qe=*Mp;
                        Mp++;
                        break;
                    case  0: *Qe=*Mp;
                        Qe->e+=Np->e;
                        if(!Qe->e) /* 元素值为0，不存入压缩矩阵 */
                            Qe--;
                        Mp++;
                        Np++;
                        break;
                    case -1: *Qe=*Np;
                        Np++;
                }
                break;
            case -1: *Qe=*Np;
                Np++;
        }
    }
    if(Mp>Me) /* 矩阵M的元素全部处理完毕 */
        while(Np<=Ne)
        {
            Qe++;
            *Qe=*Np;
            Np++;
        }
    if(Np>Ne) /* 矩阵N的元素全部处理完毕 */
        while(Mp<=Me)
        {
            Qe++;
            *Qe=*Mp;
            Mp++;
        }
    Q.tu=Qe-Qh; /* 矩阵Q的非零元素个数 */
    return OK;
}
Status SubtSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
{ /* 求稀疏矩阵的差Q=M-N */
    int i;
    for(i=1;i<=N.tu;i++)
        N.data[i].e*=-1;
    AddSMatrix(M,N,Q);
    return OK;
}
Status MultSMatrix(TSMatrix M,TSMatrix N,TSMatrix &Q)
{ /* 求稀疏矩阵的乘积Q=M*N */
    int i,j,h=M.mu,l=N.nu,Qn=0;
    /* h,l分别为矩阵Q的行、列值,Qn为矩阵Q的非零元素个数，初值为0 */
    ElemType *Qe;
    if(M.nu!=N.mu)
        return ERROR;
    Q.mu=M.mu;
    Q.nu=N.nu;
    Qe=(ElemType *)malloc(h*l*sizeof(ElemType)); /* Qe为矩阵Q的临时数组 */
    /* 矩阵Q的第i行j列的元素值存于*(Qe+(i-1)*l+j-1)中，初值为0 */
    for(i=0;i<h*l;i++)
        *(Qe+i)=0; /* 赋初值0 */
    for(i=1;i<=M.tu;i++) /* 矩阵元素相乘，结果累加到Qe */
        for(j=1;j<=N.tu;j++)
            if(M.data[i].j==N.data[j].i)
                *(Qe+(M.data[i].i-1)*l+N.data[j].j-1)+=M.data[i].e*N.data[j].e;
    for(i=1;i<=M.mu;i++)
        for(j=1;j<=N.nu;j++)
            if(*(Qe+(i-1)*l+j-1)!=0)
            {
                Qn++;
                Q.data[Qn].e=*(Qe+(i-1)*l+j-1);
                Q.data[Qn].i=i;
                Q.data[Qn].j=j;
            }
    free(Qe);
    Q.tu=Qn;
    return OK;
}
Status TransposeSMatrix(TSMatrix M, TSMatrix &T)
{
    //采用三元组表存储表示, 求稀疏矩阵M的转置矩阵T
    T.mu=M.nu; T.nu=M.mu; T.tu = M.tu; //矩阵行, 列值交换, 非零元个数保存
    if(T.tu){
        int q=1;
        for (int col = 1; col <= M.nu; ++col) { //遍历列
            for (int p = 1; p <= M.tu; ++p) { // 遍历每个元素
                if(M.data[p].i == col){ //当遍历到了col行的元素, 就将元素存入新的矩阵
                    T.data[q].i=M.data[p].j;//交换行列下标
                    T.data[q].j=M.data[p].i;
                    T.data[q].e=M.data[p].e;//存入与元素数据
                    ++q;// 指向下一个数组元素
                }//if
            }//for
        }//for
    }//if
    return OK;
}// TransposeSMatrix
Status FastTransposeSMatrix(TSMatrix M, TSMatrix &T)
{
    // 采用三元组顺序表存储表示, 求稀疏矩阵M的转置矩阵T
    // 附设num和cpot两个向量
    // num[col]表示矩阵M中第col列中非零元个数, cpot[col]指示M中第col列的第一个非零元在b.data中的恰当位置
    T.mu=M.nu; T.nu=M.mu; T.tu = M.tu; //矩阵行, 列值交换, 非零元个数保存
    if(T.tu){
        int q=1, num[M.mu], cpot[M.nu];
        for (int col = 1; col <= M.nu; ++col) { //遍历列
            num[col]=0;// 遍历列, 初始化num数组
        }//for
        for (int t = 1; t <= M.nu; ++t) {
            ++num[M.data[t].j];// 求每一行中非零元的个数
        }//for
        cpot[1]=1; //求第col列中第一个非零元在b.data中的序号
        for (int col = 2; col <= M.nu; ++col) {// 公式求M的每一列的第一个非零元在b.data中应有的位置
            cpot[col]=cpot[col-1]+num[col-1];
        }//for
        for (int p = 1; p <= M.tu; ++p) {
            int col=M.data[p].j;
            q=cpot[col];
            T.data[q].i;
        }
    }//if
    return OK;
}// FastTransposeSMatrix
//Status TransposeSMatrix(TSMatrix M,TSMatrix &T)
//{ /* 求稀疏矩阵M的转置矩阵T。算法5.1 */
//    int p,q,col;
//    T.mu=M.nu;
//    T.nu=M.mu;
//    T.tu=M.tu;
//    if(T.tu)
//    {
//        q=1;
//        for(col=1;col<=M.nu;++col)
//            for(p=1;p<=M.tu;++p)
//                if(M.data[p].j==col)
//                {
//                    T.data[q].i=M.data[p].j;
//                    T.data[q].j=M.data[p].i;
//                    T.data[q].e=M.data[p].e;
//                    ++q;
//                }
//    }
//    return OK;
//}
#endif //SPARSEMATRIX_SPARSEMATRIX_H
