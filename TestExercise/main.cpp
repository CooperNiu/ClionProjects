///// ���ź���Ҫ��Ҫ�Լ���д�����֣����ţ�������
//// ��������ʱ���ö��ļ��ķ�ʽ��ȡ����������
//// ���üӷ����ó˷�����߳���Ч��
//// ��������ķ��� int��x+0.5)�Ϳ�����
//
//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <cmath>
//
//using std::cout;
//using std::cin;
//using std::endl;
////
////int main()
////{
////    char ch, ch1;
////
////    cin>>ch;
////    ch1 = (char)(ch>=97 && ch<=122)? (ch-32): ch;
////    printf("%c", ch1);
////    return 0;
////}
///// ����Ǯ���㷨
///*
//int main() {
//    int n, fifty, twenty, ten, five, one;
//
//    cin >> n;
//
//    fifty = n / 50; //50Ԫ������
//    n=n-50* fifty;
//    twenty = n / 20; //20Ԫ������
//    n=n-20*  twenty;
//    ten = n / 10; //10Ԫ������
//    n=n-10*  ten;
//    five = n / 5;       //5Ԫ������
//    n=n-5*  five;
//    one = n;
//
//    cout << fifty <<' '<< twenty <<' '<< ten <<' '<< five <<' '<< one << endl;
//
//    return 0;
//}
//*/
//
//int Partition(int *x, int low, int high);
//
//void Qsort(int *x, int low, int high);
//
//int cmp(const void *a, const void *b);
//
//int RandSelect(int *, int low, int high, int middle);
//
//int Partition(int *x, int low, int high) {
//    x[0] = x[low];
//    int pivotkey = x[low];
//
//    while (low < high) {
//        while (low < high && x[high] >= pivotkey)
//            --high;
//        x[low] = x[high];
//
//        while (low < high && x[low] <= pivotkey)
//            ++low;
//        x[high] = x[low];
//    }
//
//    x[low] = pivotkey;
//
//    return low;
//}
//
//void Qsort(int *x, int low, int high) {
//    // ����
//    if (low < high) {
//    int pivotloc = Partition(x, low, high);
//    Qsort(x, low, pivotloc - 1);
//    Qsort(x, pivotloc + 1, high);
//}
//}
//
////Qsort
//
////int main(void)
////{   int n;
////    int x[10001];
////    int y[10001];
////    int z[10001];
////    int xkey, ykey;
////    int sum = 0;
////
////    cin>>n;
////    for (int k = 0; k < n; ++k){
////        scanf("%d %d", &x[k], &y[k]);
////    }
////
////    qsort(x, n, sizeof(int), cmp); //��x�ϵ����ݽ�������ѡ����iС����
////
////    for (int i = 1; i <= n; ++i) {
////        z[i]=x[i]-(i-1);
////    }
////    //Qsort(z, 1, n);
////    qsort(z, n, sizeof(int), cmp);
////    qsort(y, n, sizeof(int), cmp);
////
////    xkey = y[n/2];
////    ykey = z[n/2];
//// xkey = RandSelect(y, 1, n, n/2);
//// ykey = RandSelect(z, 1, n, n/2);
////
////    for (int j = 1; j <= n; ++j) {
////        sum += abs(y[j] - ykey);
////        sum += abs(z[j] - xkey);
////    }
////
////    printf("%d", sum);
////    return 0;
////}
////
////int RandSelect(int *Array, int low, int high, int middle) {
////    return Array[middle];
////}
//
//#include<stdio.h>
//#include <stdlib.h>
//#include <algorithm>

//using namespace std;
//
//int main()
//{
//    int n;
//    int x[10010],y[10010];
//    while(scanf("%d",&n)!=EOF)
//    {
//
//        for(int i=0;i<n;i++)
//        scanf("%d%d",&x[i],&y[i]);
//
//        sort(y,y+n);
//        int k=y[n/2];
//        int s=0;
//        for(int i=0;i<n;i++)
//            s+=fabs(k-y[i]);
//        sort(x,x+n);
//        for(int i=0;i<n;i++)
//            x[i]-=i;//���λ�ò���
//        sort(x,x+n);
//        k=x[n/2];
//        for(int i=0;i<n;i++)
//            s+=fabs(k-x[i]);
//
//        printf("%d\n",s);
//    }
//}

/// Accepted!
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int cmp(const void *a, const void *b)
{
    return *(int*)a-*(int*)b;
}
int main()
{
    int n,i,x_mid, y_mid,count=0;
    int *x, *y;
    scanf("%d", &n);
    x=(int *)malloc(sizeof(int)*n);
    y=(int *)malloc(sizeof(int)*n);
    for(i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);

    //����
    qsort(y, n, sizeof(int), cmp);
    qsort(x, n, sizeof(int), cmp);
    for(i=0; i<n; i++) x[i] -= i;
    qsort(x, n, sizeof(int), cmp);
    x_mid=x[n/2];
    y_mid=y[n/2];
    for(i=0; i<n; i++)
        count += abs(x[i]-x_mid) + abs(y[i]-y_mid);

    printf("%d\n", count);

    return 0;
}