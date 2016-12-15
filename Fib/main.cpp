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

    printf("一共有%d种解法\n\n", count);
    return 0;
}
// 八皇后问题
int notDangerous(int row, int j, int (*chess)[8])
{
    int flag1=0, flag2 = 0, flag3=0, flag4=0, flag5=0;
    //判断列方向
    for (int i = 0; i < 8; ++i) {
        if(*(*(chess+i)+j) != 0)
        {
            flag1 = 1;
            break;
        }
    }
    //判断左上方
    for (int k = j, i=row; i>=0 && k>=0; i--, j--) {
        if(*(*(chess+i)+j) != 0)
        {
            flag2 = 1;
            break;
        }
    }
    //判断左下方
    for (int k = j, i=row; i < 8 && k>=0; i++, j--) {
        if(*(*(chess+i)+j) != 0)
        {
            flag5 = 1;
            break;
        }
    }
    //判断右下方
    for (int k = j, i=row; i < 8 && k < 8; i++, j++) {
        if(*(*(chess+i)+j) != 0)
        {
            flag3 = 1;
            break;
        }
    }
    //判断右上方
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
// 参数row表示起始行
// 参数n 表示列数
// 参数(*chess)[8] 表示指向棋盘每一行的指针
void EightQueen(int row, int n, int (*chess)[8])
{
    int chess_temp[8][8];
    for (int i = 0; i < 8; ++i) {//将棋盘存在临时的数组
        for (int j = 0; j < 8; ++j) {
            chess_temp[i][j] = chess[i][j];
        }
    }

    if(8 == row)
    {
        printf("第%d种", count+1);
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
        //判断这个位置有多危险
        //若没有危险, 继续往下
        for (int j = 0; j < n; ++j) {
            if(notDangerous(row, j, chess)) // 判断是否危险
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
//斐波那契数列
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