/* 2017年4月17日14:17:33
 * 复习一下昨天写的程序
 * 输出菱形图案，动态创建、使用、销毁二维数组、去除字符串首尾的空格，erase函数的使用
 */
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

//这个程序是输出菱形图案
/*int main()
{
	int i, j, k;
	for (i = 0; i <= 3; i++) {
		for (j = 0; j <= 2 - i; j++)
			printf(" ");
		for (k = 0; k <= 2 * i; k++)
			printf("*");
		printf("\n");
	}
	for (i = 0; i <= 2; i++) {
		for (j = 0; j <= i; j++)
			printf(" ");
		for (k = 0; k <= 4 - 2 * i; k++)
			printf("*");
		printf("\n");
	}
}*/

//这个程序是动态创建、使用、销毁二维数组的
/*
//动态申请二维数组
#include <iostream>
using namespace std;
int main()
{
	int **a;  //指向指针的指针
	int n,m;//n行 m列
	int i,j;
	cin>>n>>m; //输入行数和列数
	int sum=0;

	//申请空间
	a= new int * [n];  //n个 int 指针 数组
	for(i=0;i<n;i++)    //n个大小为m的一维数组
	{
		a[i]=new int[m]; //1个大小为m的一维数组，a[i]是int指针
	}

	//输入数据
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			//cin>>a[i][j];//输入
			cin>> *(*(a+i)+j);//同上a相当于行指针

		}
	}

	//输出数据
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			//cout<<a[i][j]<<"\t";//输出
//			cout<< *(*(a+i)+j)<<"\t";
			sum += *(*(a+i)+j);
		}
//		cout<<endl;
	}

	cout<<sum;
	//释放申请的空间！！！
	for(i=0;i<n;i++) //释放n个大小为m的一维数组
	{
		delete []a[i];
	}
	delete []a;//释放int指针数组
	return 0;
}
*/

//这个程序是用于去除字符串首尾的空格
/*
string& trim(string &);

string string1;

int main()
{
	string s ;
	cin>>s;
	cout << trim(s) ;

	return 0;
}

string& trim(string &s)
{
	if (s.empty())
	{
		return s;
	}
	s.erase(0,s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	string1=s+"#";
	return string1;
}*/
// 自己写的去空格的程序，还没有完全符合mooc上的要求，但是可以做到去字符串前面的空格
/*int main()
{
	bool flag = true; // 是否是第一次遇到非空格
	string str;
	unsigned int spacenum = 0; // 空格数目
	unsigned int temp = 0;

	cin >> str;
	for (int i = 0; i < str.length(); ++i) {
		if (isspace(str[i]) && flag) {
		// isspace函数用于判断该字符是否为空格
			str.erase(i); // 调用去空格函数
			// 去空格函数有三种形式
			// erase（字符个数）
			// erase（起始位置，终止位置）
			// erase（起始位置，字符个数）
		}
		else {
			i++;
			continue;
		}
		flag=false;
		if (isspace(str[i]) && isspace(str[i + 1])) {
			str.erase(str.begin() + i, str.end() - 1);
			break;
		}
	}

	cout << str;
	return 0;
}*/

// 输出1-12阿拉伯数字对应的英文单词
/*int main()
{
	char *str[13] = {" ","one", "two", "three","four","five","six","seven","eight","nine","ten",
	                  "eleven","twelve"};

	int i;
	cin>>i;
	cout<<str[i];
	return 0;
}*/

//利用指针输出数组中的元素
/*
题目内容：
编写程序，把从1到n的n个整数赋予某个int型数组，然后用int型指针输出该数组元素的值。,

输入格式:
输入参数n

输出格式：
输出是1到n n个数组元素,注意最后一个元素之后没有空格。

输入样例：
9

输出样例：
1 2 3 4 5 6 7 8 9
时间限制：500ms内存限制：32000kb

int main()
{
	int n;
	int a[1000];
	cin>>n;
	for (int i = 0; i < n; ++i) {
		a[i]=i+1;
	}
	int *pInt=a;
	for (int i = 0; i < n; ++i) {
		cout<<*(pInt++);
		if (i<n-1){
			cout<<' ';
		}
	}
	return 0;
}
  */