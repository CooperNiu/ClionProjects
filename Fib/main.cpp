#include <iostream>
#include <cstdio>

using namespace std;
int count = 0;
int chess[8][8];

int main() {
//    int fib(int);
//    int print();
    int notDangerous(int row, int j, int (*chess)[8]);
    void EightQueen(int, int, int(*chess)[8]);
    int chess[8][8];
    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            chess[i][j]=0;
        }
    }
//    cout<< fib(6);
//    print();
    EightQueen(0, 8, chess);

    printf("һ����%d�ֽⷨ\n\n", count);
    return 0;
}
// �˻ʺ�����
int notDangerous(int row, int j, int (*chess)[8])
{
    int flag1=0, flag2 = 0, flag3=0, flag4=0, flag5=0;
    //�ж��з���
    for (int i = 0; i < 8; ++i) {
        if(*(*(chess+i)+j) != 0)
        {
            flag1 = 1;
            break;
        }
    }
    //�ж����Ϸ�
    for (int k = j, i=row; i>=0 && k>=0; i--, j--) {
        if(*(*(chess+i)+j) != 0)
        {
            flag2 = 1;
            break;
        }
    }
    //�ж����·�
    for (int k = j, i=row; i < 8 && k>=0; i++, j--) {
        if(*(*(chess+i)+j) != 0)
        {
            flag5 = 1;
            break;
        }
    }
    //�ж����·�
    for (int k = j, i=row; i < 8 && k < 8; i++, j++) {
        if(*(*(chess+i)+j) != 0)
        {
            flag3 = 1;
            break;
        }
    }
    //�ж����Ϸ�
    for (int k = j, i=row; i>=0 && k < 8; i--, j++) {
        if(*(*(chess+i)+j) != 0)
        {
            flag4 = 1;
            break;
        }
    }
    if(flag1||flag2||flag3 ||flag4 || flag5){
        return 0;
    }
    else{
        return 1;
    }
}
// ����row��ʾ��ʼ��
// ����n ��ʾ����
// ����(*chess)[8] ��ʾָ������ÿһ�е�ָ��
void EightQueen(int row, int n, int (*chess)[8])
{
    int chess_temp[8][8];
    for (int i = 0; i < 8; ++i) {//�����̴�����ʱ������
        for (int j = 0; j < 8; ++j) {
            chess_temp[i][j] = chess[i][j];
        }
    }

    if(8 == row)
    {
        printf("��%d��", count+1);
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                printf("%d ", *(*(chess_temp+i)+j));
            }
            printf("\n");
        }
        printf("\n");
        count++;
    }
    else{
        //�ж����λ���ж�Σ��
        //��û��Σ��, ��������
        for (int j = 0; j < n; ++j) {
            if(notDangerous(row, j, chess)) // �ж��Ƿ�Σ��
            {
                for (int i = 0; i < 8; ++i) {
                    *(*(chess+row)+i)=0;
                }
                *(*(chess_temp+row)+j)=1;

                EightQueen(row, n, chess_temp);
            }
        }
    }
}
//쳲���������
int fib(int i)
{
    if(i<2){
        return i==0?0:1;
    }
    return fib(i-1)+fib(i-2);
}
//
int print(){
    char a;
    scanf("%c", &a);
    if(a != '#') print();
    if(a != '#') printf("%c", a);
    return 0;
}