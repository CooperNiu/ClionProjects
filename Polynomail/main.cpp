#include <stdio.h>
//#include <stdlib.h>
#include "functions.cpp"
int main() {
    polynomial Pa,Pb;
    int m,n,i;
    m=6;
    n=5;
//    printf("Function 1\n 函数CreatPolyn(polynomial *P,int m)测试...\n");
    printf("  请输入一元多项式Pa的元素...\n");
    CreatPolyn(&Pa,m);
    printf("\n");
    printf("  请输入一元多项式Pb的元素...\n");
    CreatPolyn(&Pb,n);
    printf("\n");
//    printf("Function 2\n 函数PrintPolyn(polynomial P)测试...\n");
    printf("  一元多项式Pa=");
    PrintPolyn(Pa);
    printf("\n");
    printf("  一元多项式Pb=");
    PrintPolyn(Pb);
    printf("\n\n");
//    printf("Function 3\n 函数PolyLength(polynomial P)测试...\n");
    n=PolyLength(Pa);
    printf("  一元多项式Pa的项数为：%d\n",n);
    n=PolyLength(Pb);
    printf("  一元多项式Pb的项数为：%d\n\n",n);
//    printf("Function 4\n 函数AddPolyn(polynomial *Pa,polynomial *Pb)测试...\n");
    printf("  Pa=Pa+Pb=");
    AddPolyn(&Pa,&Pb);
    PrintPolyn(Pa);
    printf("\n");
//    printf("Function 5\n 函数DestroyPolyn(polynomial *P)测试...\n");
    printf("  销毁Pa前：");
    (Pa.head&&Pa.tail&&Pa.len)?printf("Pa存  在！！！\n"):printf("Pa不存在！！！\n");
    DestroyPolyn(&Pa);
    printf("  销毁Pa后：");
    (Pa.head&&Pa.tail&&Pa.len)?printf("Pa存  在！！！\n\n"):printf("Pa不存在！！！\n\n");
    return 0;
}