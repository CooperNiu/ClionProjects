// 对于这种要求排版的算法还是不方便操作，因为不同的机器上运行是不一样的
#include <iostream>

using namespace std;

const int N = 20;

long combi(int n, int r)
{
    long p = 1;

    for (int i = 1; i <= r; ++i) {
        p=p*(n-i+1)/i;
    }

    return p;
}

void paint()
{
    for (int n = 0; n <= N; ++n) {
        for (int r = 0; r <= n; ++r) {
            if (r==0)
            {
                for (int i = 0; i <= (N - n); ++i) {
                    cout<<"    ";
                }
            }
            else
            {
                cout<<"    ";
            }// 排版设定结束

            cout<<combi(n, r);
        }
        cout<<endl;
    }
}
int main() {
    paint();

    return 0;
}