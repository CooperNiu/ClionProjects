/* main.cpp 检验bo2-7.cpp的主程序 */
#include "common.h"
//#include "PolyFunctions.cpp"
// 2016-12-15 16:57:51 change file encoding from UTF-8 into GBK
// success!
int main()
{
    polynomial p,q;
    int m;
    printf("请输入第一个一元多项式的非零项的个数：");
    scanf("%d",&m);
    CreatPolyn(&p,m);
    printf("请输入第二个一元多项式的非零项的个数：");
    scanf("%d",&m);
    CreatPolyn(&q,m);
    AddPolyn(&p,&q);
    printf("两个一元多项式相加的结果：\n");
    PrintPolyn(p);
    printf("请输入第三个一元多项式的非零项的个数：");
    scanf("%d",&m);
    CreatPolyn(&q,m);
    AddPolyn1(&p,&q);
    printf("两个一元多项式相加的结果(另一种方法)：\n");
    PrintPolyn(p);
    printf("请输入第四个一元多项式的非零项的个数：");
    scanf("%d",&m);
    CreatPolyn(&q,m);
    SubtractPolyn(&p,&q);
    printf("两个一元多项式相减的结果：\n");
    PrintPolyn(p);
    printf("请输入第五个一元多项式的非零项的个数：");
    scanf("%d",&m);
    CreatPolyn(&q,m);
    MultiplyPolyn(&p,&q);
    printf("两个一元多项式相乘的结果：\n");
    PrintPolyn(p);
    DestroyPolyn(&p);

    return 0;
}
