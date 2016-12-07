/* main.cpp 检验基本操作Functions.cpp的主函数 */
#include"MacroDef.h"  /* 要将程序中所有#include命令所包含的文件拷贝到当前目录下 */
/* 以下2行可根据需要选用一个（且只能选用一个），而不需改变基本操作Functions.cpp */
#include"ElemType.h" /* 在此命令之前要定义ElemType的类型 */
/* 抽象数据类型Triplet和ElemType的基本操作(8个) */
int main()
{
    Triplet T;//自定义数据类型
    ElemType m;
    Status i;
    i=InitTriplet(&T,5,7,9);
    /* i=InitTriplet(&T,5.0,7.1,9.3); /* 当ElemType为双精度型时,可取代上句 */
    /* 调用函数, 将返回值存在i中, 通过后面的printf语句来判断是否成功! */

    printf("调用初始化函数后，i=%d(1:成功) T的三个值为：%d %d %d\n",i,T[0],T[1],T[2]);
    /* 当ElemType的类型变化时，要相应改变printf()的格式符。 */
    /* 这种测试函数的方法值得借鉴 */

    i=Get(T,2,&m);
    if(i==OK)
        printf("T的第2个值为：%d\n",m);
    i=Put(T,2,6);
    if(i==OK)
        printf("将T的第2个值改为6后，T的三个值为：%d %d %d\n",T[0],T[1],T[2]);
    i=IsAscending(T); /* 此类函数实参与ElemType的类型无关,当ElemType的类型变化时,实参不需改变 */
    printf("调用测试升序的函数后，i=%d(0:否 1:是)\n",i);
    i=IsDescending(T);
    printf("调用测试降序的函数后，i=%d(0:否 1:是)\n",i);
    if((i=Max(T,&m))==OK) /* 先赋值再比较 */
        printf("T中的最大值为：%d\n",m);
    if((i=Min(T,&m))==OK)
        printf("T中的最小值为：%d\n",m);
    DestroyTriplet(&T); /* 函数也可以不带回返回值 */
    printf("销毁T后，T=%u(NULL)\n",T);
}