//#include <iostream>
//#include <cstdio>
//
//using namespace std;
//
//int main() {
//    char ch;
//    cin>>ch;
//
//    /// if('a'<ch<'z') ���ﷸ��һ��̫��Ĵ���
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

/// ����ƽ���ɼ�
/*
 * 2017��3��2��14:56:41 ���������ϾͿ�ʼ�������Ŀ�Ĵ��룬�����ڲ��ύ�ɹ���
 * Ч�ʵ��µ�ԭ��
 * 1. �����ֻ�����ʱ�ز鿴�罻�������Ϣ����ʵ��û��ʲô��Ҫ����Ϣ���������˷��˺ö�ʱ�䣬�޷�רע��
 * 2. �����ţ�ÿ�γ���������ĵ��ԣ��������Ա�������
 * 3. ��Ŀ��ϰ��̫�٣���һʱ��C���Գ�����ƻ����Ĺ���̫���������������ɵذ��Լ���˼��ת��Ϊ�����еĳ���
 *
 *  ��ϧ�������ʵĻ�����һ�ж���Ϊ�˸��õĳɳ������أ�
 */
//#include <iostream>
//
//using namespace std;
//
//int main(void)
//{
//    int score[11];
//    //һ��ʼ���Ե�ʱ�����ֱ���ڴ�����Ƕ�����ݣ��ύʱ��ǵ�ע�͵���
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

/// ���ӳ�����������ѧ��ʽ�Ƶ���Ȼ��ֱ�Ӵ����������׽��
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

/// ��ש����Ѽͬ�����⣬��ٷ���
//#include<iostream>
//using namespace std;
//
//int main(){
//    int i=0,j=0,k=0,n,women,children,flag=0;
//    cin>>n;
//    for(i=0;i<=n/4;i++){ //��ٷ�
//        women=n-4*i;
//        for(j=0;j<=women/3;j++){
//            children=women-3*j;
//            for(k=0;k<=children*10/5;k+=2){
//                if(i+j+k==n && 4*i+3*j+5*k/10==n){
//                    cout<<"men"<<i<<endl;
//                    cout<<"women"<<j<<endl;
//                    cout<<"children"<<k<<endl;
//                    flag=1; // ��������Ƿ��кϷ�ֵ���
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

/// ���ֻ�Ǯ
#include<iostream>
using namespace std;

int main(){
    int n,sum=0,i,j,k,temp1,temp2,temp3;
    cin>>n;
    if(n>=0 && n<=99){ // ��ٷ����Ա�������Ӧ�����
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
