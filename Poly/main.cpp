/* main.cpp ����bo2-7.cpp�������� */
#include "common.h"
//#include "PolyFunctions.cpp"
// 2016-12-15 16:57:51 change file encoding from UTF-8 into GBK
// success!
int main()
{
    polynomial p,q;
    int m;
    printf("�������һ��һԪ����ʽ�ķ�����ĸ�����");
    scanf("%d",&m);
    CreatPolyn(&p,m);
    printf("������ڶ���һԪ����ʽ�ķ�����ĸ�����");
    scanf("%d",&m);
    CreatPolyn(&q,m);
    AddPolyn(&p,&q);
    printf("����һԪ����ʽ��ӵĽ����\n");
    PrintPolyn(p);
    printf("�����������һԪ����ʽ�ķ�����ĸ�����");
    scanf("%d",&m);
    CreatPolyn(&q,m);
    AddPolyn1(&p,&q);
    printf("����һԪ����ʽ��ӵĽ��(��һ�ַ���)��\n");
    PrintPolyn(p);
    printf("��������ĸ�һԪ����ʽ�ķ�����ĸ�����");
    scanf("%d",&m);
    CreatPolyn(&q,m);
    SubtractPolyn(&p,&q);
    printf("����һԪ����ʽ����Ľ����\n");
    PrintPolyn(p);
    printf("����������һԪ����ʽ�ķ�����ĸ�����");
    scanf("%d",&m);
    CreatPolyn(&q,m);
    MultiplyPolyn(&p,&q);
    printf("����һԪ����ʽ��˵Ľ����\n");
    PrintPolyn(p);
    DestroyPolyn(&p);

    return 0;
}
