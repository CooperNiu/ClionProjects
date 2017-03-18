//#include <iostream>
//#include <cstdio>
//#include <cstring>
//
//char x[10000];
//char y[10000];
////    char x[10000]={"abcfbc"};
////    char y[10000]={"abftest"};
//int C[10000][10000];
//int B[10000][10000];
////void LCSLength(int m, int n, char *x, char *y, int **c, int **b);
//
//int main() {
//    while (scanf("%s%s", x, y) != EOF) {
//        int m = strlen(x);
//        int n = strlen(y);
//
//        for (int i = 1; i <= m; ++i) { // 初始化数组
//            C[i][0] = 0;
//        }
//
//        for (int i = 1; i <= n; ++i) { // 初始化数组
//            C[0][i] = 0;
//        }
//
//        for (int i = 1; i <= m; ++i)
//        {
//            for (int j = 1; j <= n; ++j)
//            {
//                // if (x[i] == y[j]) /// 就这句和accepted的答案不一样，
//                {
//                    C[i][j] = C[i - 1][j - 1] + 1;
//                    B[i][j] = 1;
//                }
//                else if (C[j - 1][j] >= C[i][j - 1])
//                {
//                    C[i][j] = C[i - 1][j];
//                    B[i][j] = 2;
//                }
//                else
//                {
//                    C[i][j] = C[i][j - 1];
//                    B[i][j] = 3;
//                }
//            }
//        }
//
//        printf("%d\n", C[m][n]);
//    }
//
//    return 0;
//}
/// ac 代码
#include <stdio.h>
#include <string.h>
#define N 500
void LCSLength(int m, int n, char x[], char y[],int c[][N],int b[][N])
{
    int i, j;
    for(i = 1; i <= m; i++) c[i][0] = 0;
    for(i = 0; i <= n; i++) c[0][i] = 0;

    for(i = 1; i <= m; i++)
        for(j = 1; j<=n; j++)
        {
//            if(x[i]==y[j]) // 这样就错了，在没有相同子串时候仍为1
            if(x[i-1]==y[j-1]) // 关键的地方
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 1;
            }else if(c[i-1][j]>=c[i][j-1]){
                c[i][j] = c[i-1][j];
                b[i][j] = 2;
            }else{
                c[i][j] = c[i][j-1];
                b[i][j] = 3;
            }
        }
}

int main()
{
    char x[N];
    char y[N];
    int c[N][N], b[N][N];
    int m, n ;
    while(scanf("%s %s", x, y) !=EOF)
    {
        m = strlen(x);
        n = strlen(y);
        LCSLength(m,n, x, y, c, b);
        printf("%d\n", c[m][n]);

    }
    return 0;
}

/// poj上测试有问题，手动测试没问题
//#include <iostream>
//#include <cstring>
//using namespace std;
//char s1[1002],s2[1002];
//int res[1001][1001];
//int main()
//{
//    while(cin>>s1>>s2)
//    {
//        memset(res,0,sizeof(res));
//        for(int i=0;i<strlen(s1);++i)
//            for(int j=0;j<strlen(s2);++j)
//            {
//                if(s1[i]==s2[j])res[i][j]=res[i-1][j-1]+1;
//                else res[i][j]=max(res[i][j-1],res[i-1][j]);
//            }
//        cout<<res[strlen(s1)-1][strlen(s2)-1]<<endl;
//    }
//    return 0;
//}

//void LCSLength(int m, int n, char *x, char *y, int **c, int **b) {
//    // m, n 分别为两个字符串的长度，x,y 为两个字符串数组，c，b为连个数组存储x，y的最长公共子序列的长度。
//    for (int i = 1; i <= m; ++i) { // 初始化数组
//        c[i][0]=0;
//    }
//
//    for (int i = 1; i <= n; ++i) { // 初始化数组
//        c[0][i]=0;
//    }
//
//    for (int i = 1; i <= m; ++i)
//    {
//        for (int j = 1; j < n; ++j)
//        {
//            if(x[i] == y[j])
//            {
//                c[i][j]=c[i-1][j-1] + 1;
//                b[i][j]=1;
//            }
//            else if(c[j-1][j] >= c[i][j-1])
//            {
//                c[i][j] = c[i-1][j];
//                b[i][j]=2;
//            }
//            else
//            {
//                c[i][j]=c[i][j-1];
//                b[i][j]=3;
//            }
//        }
//    }
//}