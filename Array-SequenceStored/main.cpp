/* main.cpp ������, ���ú���, ���Ժ�������
   2016-11-7 19:42:42 in classroom

   2016-11-9 18:35:39 in classroom
   ����:���� <ǧ��>
   Ŀ��:ʵ�־����ת��, ���ǲ���������ʵ�ֵ�,��Ҫ����Ԫ��˳������洢, ������Ҫ�½���Ŀ, so I wanna go!

   2016-11-10 14:02:34 in lab
   ����: ���еĻ���
   Ŀ��: ���Ժ���
 */
#include "Array-SequenceStored.h"
int main()  
{  
    int i,j,k;
    Array A;
    ElemType e;
//    printf("����������ά��:");
//    scanf("%d", &A.dim);
    A.dim=3;
    InitArray(A,A.dim,2,2,2); //��Ϊ����ı䳤������֪���������, ���Ի��޷��Լ�ѡ������ά��
    printf("����һ�� %d ά������!\n",A.dim);
    printf("����ÿ��ά�ȵĴ�С:\n");
    for (i=0;i<A.dim;i++)
         printf("�� %d ��ά�ȴ�СΪ: %5d\n",i + 1, A.bounds[i]);
    printf("���������Ļ�ַ:\n");
    for (i=0;i<A.dim;i++)
         printf("�� %d ����ַ �� %5d\n",i + 1,A.constants[i]);
    printf("\n��������ֵ��������\n");
    getchar();
    printf("�������һ������:\n");
    srand(time(0));
    for (i=0;i<A.bounds[0];i++)
        for (j=0;j<A.bounds[1];j++)
          for(k=0;k<A.bounds[2];k++)
            Assign(A,rand()%100,i,j,k);
        printf("����A�ĳ�Ա��:\n");
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
    printf("��֮��Ч��һά������:\n");
    for (i=0; i<A.bounds[0]*A.bounds[1]*A.bounds[2]; i++)
         printf("%5d",A.base[i]);
    printf("\n");
    DestroyArray(A);
    getchar();
    return 0;
}