#include <iostream>
#include <cstring>
#include <cstdio>

const int N=100;

using namespace std;

void  encrypt(string &s)//����
{

    int i=s.length();
    for(int j=0;j<i;++j)
    {
        if('A'<=s[j]&&s[j]<='Z')
        {
            if('A'<=s[j]&&s[j]<='W')
              /// ����ֵ�ý���ĵط����á�A��ֱ�Ӳ���Ƚϣ������û���ASCII���ж�Ӧ�����֣�
              /// �����ȿ��Լ��ٳ���Ŀ��ܣ�Ҳ���Լ��ټ�����Ѷȣ������Ķ�������Ѷȣ�ʹ���˸��������
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