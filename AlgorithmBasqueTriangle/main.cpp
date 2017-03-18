// ��������Ҫ���Ű���㷨���ǲ������������Ϊ��ͬ�Ļ����������ǲ�һ����
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
            }// �Ű��趨����

            cout<<combi(n, r);
        }
        cout<<endl;
    }
}
int main() {
    paint();

    return 0;
}