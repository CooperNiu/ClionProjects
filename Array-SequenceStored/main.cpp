/* main.cpp 主函数, 调用函数, 测试函数功能
   2016-11-7 19:42:42 in classroom

   2016-11-9 18:35:39 in classroom
   歌曲:许嵩 <千古>
   目标:实现矩阵的转置, 可是不是用数组实现的,需要用三元组顺序表来存储, 所以需要新建项目, so I wanna go!

   2016-11-10 14:02:34 in lab
   音乐: 梦中的婚礼
   目标: 测试函数
 */
#include "Array-SequenceStored.h"
int main()  
{  
    int i,j,k;
    Array A;
    ElemType e;
//    printf("请输入数组维数:");
//    scanf("%d", &A.dim);
    A.dim=3;
    InitArray(A,A.dim,2,2,2); //因为这里的变长参数不知道如何输入, 所以还无法自己选择数组维数
    printf("这是一个 %d 维的数组!\n",A.dim);
    printf("数组每个维度的大小:\n");
    for (i=0;i<A.dim;i++)
         printf("第 %d 个维度大小为: %5d\n",i + 1, A.bounds[i]);
    printf("函数常量的基址:\n");
    for (i=0;i<A.dim;i++)
         printf("第 %d 个基址 ： %5d\n",i + 1,A.constants[i]);
    printf("\n输入任意值继续程序！\n");
    getchar();
    printf("随机生成一组数据:\n");
    srand(time(0));
    for (i=0;i<A.bounds[0];i++)
        for (j=0;j<A.bounds[1];j++)
          for(k=0;k<A.bounds[2];k++)
            Assign(A,rand()%100,i,j,k);
        printf("数组A的成员是:\n");
    for (i=0;i<A.bounds[0];i++)
    {
     for (j=0;j<A.bounds[1];j++)
      {
            printf("(");
            for (k=0;k<A.bounds[2];k++)
            {
                     Value(A,e,i,j,k);
                    printf(" %5d ", e);
            }
             printf(")  ");
        }
            printf("\n");
    }
    printf("与之等效的一维数组是:\n");
    for (i=0; i<A.bounds[0]*A.bounds[1]*A.bounds[2]; i++)
         printf("%5d",A.base[i]);
    printf("\n");
    DestroyArray(A);
    getchar();
    return 0;
}