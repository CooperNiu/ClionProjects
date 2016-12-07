/* main.cpp 矩阵的转置
 * 2016-11-9 18:48:47
 * 歌曲: 山外小楼夜听雨
 * 地点: 南核1203 选修课教室
 * 目的: 实现矩阵的转置 明天周四上机任务
 *
 * 2016-11-10 16:26:00
 * 地点: 图书馆
 * 状态: 功能全部成功
 * */
#include <iostream>
#include "SparseMatrix.h"
using namespace std;
int main() {
    int n;
    TSMatrix M, N, Q;    //初始化M,并且输出
    while(1){
        printf("1.CreateSMatrix\n2.CopySMatrix\n3.AddSMatrix\n"
                "4.SubtSMatrix\n5.MultSMatrix\n6.TransposeSMatrix\n"
                "7.PrintSMatrix\n8.FastTransposeSMatrix\n"
                "9.DestroySMatrix\n10.MatrixEmpty\nPlease choose a function(input 0 to exit):");
        scanf("%d", &n);
        switch (n){
            case 1:CreateSMatrix(M);break;
            case 2:CopySMatrix(M, N);break;//复制M到N, 并输出
            case 3:AddSMatrix(M, N, Q);break;//M+N=Q
            case 4:SubtSMatrix(M, N, Q);break;//M-N=Q
            case 5:MultSMatrix(M, N, Q);break;//M*N=Q
            case 6:TransposeSMatrix(M, Q);break;//转置矩阵
            case 7:PrintSMatrix(Q);break;
            case 8:FastTransposeSMatrix(M, Q);break;//快速转置矩阵
            case 9:DestroySMatrix(M);break;//销毁M,并判断销毁是否成功
            case 10:MatrixEmpty(M);break;
            case 0:exit(0);
            default:printf("Input false, please input again! ");
        }
    }
    /*
     * //初始化M,并且输出
    CreateSMatrix(M);
    PrintSMatrix(M);
    //复制M到N, 并输出
    CopySMatrix(M, N);
    PrintSMatrix(N);
    //M+N=Q
    AddSMatrix(M, N, Q);
    PrintSMatrix(Q);
    //M-N=Q
    SubtSMatrix(M, N, Q);
    PrintSMatrix(Q);
    //M*N=Q
    MultSMatrix(M, N, Q);
    PrintSMatrix(Q);
    //转置矩阵
    TransposeSMatrix(M, Q);
    PrintSMatrix(Q);
    //快速转置矩阵
    FastTransposeSMatrix(M, Q);
    PrintSMatrix(Q);
    //销毁M,并判断销毁是否成功
    DestroySMatrix(M);
    MatrixEmpty(M);
    DestroySMatrix(N);
    MatrixEmpty(N);
    DestroySMatrix(Q);
    MatrixEmpty(Q);
     */
    return 0;
}