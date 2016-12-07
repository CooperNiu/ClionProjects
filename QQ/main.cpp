// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
// 测试前请把QQ主面板打开。别问为什么。
//
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

HWND win;
int temp = 10;	//每次移动像素
int x = 1900;
int y = 1080;

void moveqqzy(int n)
{
    Sleep(10);
    if (x == n)
    {
        return;
    }
    else {
        SetWindowPos(win, NULL, n, 0, 281, 765, 0);
        n += temp;
        moveqqzy(n);
    }
}

void moveqqyz(int n)
{
    Sleep(10);
    if (0 == n)
    {
        return;
    }
    else {
        SetWindowPos(win, NULL, n, 0, 281, 765, 0);
        n -= temp;
        moveqqyz(n);
    }
}

void moveqqsx(int n)
{
    Sleep(10);
    if (y == n)
    {
        return;
    }
    else {
        SetWindowPos(win, NULL, 0, n, 281, 765, 0);
        n += temp;
        moveqqsx(n);
    }
}

void moveqqxs(int n)
{
    Sleep(50);
    if (0 == n)
    {
        return;
    }
    else {
        SetWindowPos(win, NULL, 0, n, 281, 765, 0);
        n -= temp;
        moveqqxs(n);
    }
}

void playqq()
{
    win = FindWindowA("TXGuiFoundation", "QQ");
//    win = FindWindowA("TXGuiFoundation", "Sticky Notes");
    if (win == NULL)
    {
        printf("\nCannot Find It!\n");

    }
    //SetWindowTextA(win, "请叫我哥");
    while (1)
    {
        moveqqzy(0);
        moveqqyz(x);
        moveqqsx(0);
        moveqqxs(y);
        getchar();
    }
}

int main()
{
    playqq();

    system("pause");
    return 0;
}