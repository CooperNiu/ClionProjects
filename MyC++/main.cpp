#include <iostream>
#include "constant.h"
#include "sqlist.h"

using namespace std;

int main() {
    SqList a, b;
    int c;

    if(InitList(a))//初始化新的线性表
    {
        a.length=20;
        for(int i=0; i<a.length; i++){//往线性表中存储元素
            a.elem[i]=i;
        }
//        if(!ListEmpty(a)){
//            cout<<"存入成功！"<<endl;
//        }
//        else
//        {
//            cout<<"存入失败！"<<endl;
//        }
        if(ListOppose(a))//逆置线性表
        {
            for(int i=0; i<a.length; i++)
            {
                cout<<  a.elem[i] << endl;//输出元素
            }
        }

        ListTransver(a);
    }
    else
    {
        cout<<"初始化失败";
    }

    GetElem(a, 5, int &c);
    cout << c;
    ListEmpty(a);

    ListTransver(a);

    ClearList(a);

    ListTransver(a);

    return 0;
}