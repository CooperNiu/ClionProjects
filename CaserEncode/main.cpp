#include <iostream>
#include <cstring>
#include <cstdio>

const int N=100;

using namespace std;

void  encrypt(string &s)//加密
{

    int i=s.length();
    for(int j=0;j<i;++j)
    {
        if('A'<=s[j]&&s[j]<='Z')
        {
            if('A'<=s[j]&&s[j]<='W')
              /// 这里值得借鉴的地方是用‘A’直接参与比较，而不用换成ASCII表中对应的数字，
              /// 这样既可以减少出错的可能，也可以减少记忆的难度，降低阅读代码的难度，使他人更容易理解
                s[j]+=3;
            else
                s[j]-=23;
//            cout<<s[j]; // this sentence is comment
            s[j]+=32;
//            cout<<s[j]<<endl;// this sentence is comment
        }
        else if('a'<=s[j]&&s[j]<='z')
        {
            if('a'<=s[j]&&s[j]<='w')
                s[j]+=3;
            else
                s[j]-=23;
//            cout<<s[j];// this sentence is comment
            s[j]-=32;
//            cout<<s[j]<<endl;// this sentence is comment

        }

    }
}

int main() {
    string str;
    cin>>str;

    encrypt(str);
    cout<<str<<endl;

    return 0;
}