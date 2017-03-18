//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//int main() {
//    char ch;
//    cin>>ch;
//
//    /// if('a'<ch<'z') 这里犯了一个太大的错误
//    if(ch>'a' && ch<'z')
//    {
//        printf("%c%c%c", ch-1,ch,ch+1);
//    }
//    else if(ch>'A' && ch<'Z')
//    {
//        printf("%c%c%c", ch-1,ch,ch+1);
//    }
//    else
//    {
//        switch (ch){
//            case 'a':
//                cout<<"zab";
//                break;
//            case 'A':
//                cout<<"ZAB";
//                break;
//            case 'z':
//                cout<<"yza";
//                break;
//            case 'Z':
//                cout<<"YZA";
//                break;
//            default:
//                break;
//        }
//    }
//
//    return 0;
//}

/// 计算平均成绩
/*
 * 2017年3月2日14:56:41 从昨天晚上就开始敲这个题目的代码，到现在才提交成功；
 * 效率低下的原因：
 * 1. 带着手机，不时地查看社交网络的消息（其实并没有什么重要的消息），反而浪费了好多时间，无法专注；
 * 2. 不自信，每次出错后不能耐心调试，反而是自暴自弃；
 * 3. 题目练习的太少，大一时候C语言程序设计基础的功底太薄，根本不能自由地把自己的思想转化为可运行的程序！
 *
 *  珍惜现在舒适的环境，一切都是为了更好的成长服务呢！
 */
//#include <iostream>
//
//using namespace std;
//
//int main(void)
//{
//    int score[11];
//    //一开始测试的时候就用直接在代码中嵌入数据，提交时候记得注释掉！
////    int score[11]={88 ,90, 97 ,89, 85 ,95, 77, 86, 92, 83};
//    int min=101;
//    int max=-1;
//    double sum = 0;
//
//    for (int i = 0; i < 10; ++i) {
//        cin>>score[i];
//    }
//
//    for (int i = 0; i < 10; ++i) {
//        if(score[i]>100){
//            cout<<"the score is invalid.";
//            return 0;
//        }
//    }
//
//    for (int i = 0; i < 10; ++i) {
//        if(score[i]<min){
//            min = score[i];
//        }
//    }
//
//    for (int i = 0; i < 10; ++i) {
//        if(score[i]>max){
//            max = score[i];
//        }
//    }
//
//    for (int j = 0; j < 10; ++j) {
//        sum += score[j];
//    }
//
//    sum = sum - max - min;
//    double average = sum / 8;
//
//    cout<<average;
//    return 0;
//}

/// 猴子吃桃问题用数学公式推导，然后直接代入计算很容易解答
//#include <iostream>
//
//using namespace std;
//
//int main(void)
//{
//    int n;
//    int sum = 1;
//    cin>>n;
//    for (int i = 0; i < n-1; ++i) {
//        sum = (sum + 1)*2;
//    }
//
//    cout<<sum;
//    return 0;
//}

/// 搬砖，鸡鸭同笼问题，穷举法！
//#include<iostream>
//using namespace std;
//
//int main(){
//    int i=0,j=0,k=0,n,women,children,flag=0;
//    cin>>n;
//    for(i=0;i<=n/4;i++){ //穷举法
//        women=n-4*i;
//        for(j=0;j<=women/3;j++){
//            children=women-3*j;
//            for(k=0;k<=children*10/5;k+=2){
//                if(i+j+k==n && 4*i+3*j+5*k/10==n){
//                    cout<<"men"<<i<<endl;
//                    cout<<"women"<<j<<endl;
//                    cout<<"children"<<k<<endl;
//                    flag=1; // 用作标记是否有合法值输出
//                }else{
//                    continue;
//                }
//            }
//        }
//    }
//    if(flag==0){
//        cout << "no result!"<<endl;
//    }
//    return 0;
//}

/// 美分换钱
#include<iostream>
using namespace std;

int main(){
    int n,sum=0,i,j,k,temp1,temp2,temp3;
    cin>>n;
    if(n>=0 && n<=99){ // 穷举法，以变量代不应变的量
        for(i=0;i<=n/25;i++){
            temp1=n-25*i;
            for(j=0;j<=temp1/10;j++){
                temp2=temp1-10*j;
                for(k=0;k<=temp2/5;k++){
                    temp3=temp2-5*k;
                    if(25*i+10*j+5*k+temp3==n){
                        sum++;
                    }
                }
            }
        }
        cout<<sum<<endl;
    } else{
        cout<<"the money is invalid!"<<endl;
    }
    return 0;
}
