/*
 * 2016年11月3日14:15:35周四上机, 阳光明媚, 久违的阳光终于普照大地, 新手机, 新电脑, 新耳机, 听着最喜欢的旋律, 笨拙地
 * 敲着代码, 而流淌出的确实优美的旋律.哈哈!
 */

#include <iostream>
using namespace std;// Caution: almost every time cout and cin went wrong is due to forget put this statement in first
#include "Queue.h"
int main() {
    int n;
    ElemType e = 0;
    SqQueue Q;
    while (1)
    {// 实现多次测试
        cout << "Please input a number to choose:";
        cin >> n;
        switch (n)
        {
            case 1:
                if(Init(Q))
                    cout<<"Init queue successfully!\n";
                else
                    cout<<"Init fail!\n";
                break;
            case 2: cout<<"The length of queue is:"<<QueueLength(Q)<<endl;
                break;
            case 3: cout<<"Please insert an element into the queue:";
                    cin >> e;
                    if(EnQueue(Q, e))
                        cout<<"Insert element successfully!\n";
                    else
                        cout<<"Insert fail!\n";
                break;
            case 4:
                    if(QueueEmpty(Q))
                        cout<<"Empty!\n";
                    else
                        cout<<"Not empty!\n";
                break;
            case 5:
                    if(DeQueue(Q, e))
                        cout<<"Delete successfully!\n";
                    else
                        cout<<"Delete fail!\n";
                break;
            case 6: if(GetHead(Q,e))
                        cout<<"Head element is:" << e << endl;
                    else
                        cout<<"Get head fail!\n";
                break;
            case 7:
                    if(QueueTraverse(Q, e))
                        cout<<"Traverse successfully!\n";
                    else
                        cout<<"Traverse fail!\n";
                break;
            case 8:
                    if(ClearQueue(Q))
                        cout<<"Clear successfully!\n";
                    else
                        cout<<"Clear fail!\n";
                break;
            case 9:
                    if(DestroyQueue(Q))
                        cout<<"Destroy successfully!\n";
                    else
                        cout<<"Destroy fail!\n";
                break;
            case 0: exit(1);
            default: cout<<"ERROR, please input again!\n";
        }//switch
    }//while
    return 0;
}