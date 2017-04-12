#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*
int main()
{
	int chars = 0;
	int spaces = 0;
	int digit = 0;
	int punct = 0;
	int others = 0;
	char ch;
	int tag = 0;
	cout << "Enter text for analysis,and type @ to terminate.\n";
	
	cin.get(ch); // 用这个函数读取字符串可以读入空格，直到行尾
	
	while (ch != '@')
	{
		if ( isalpha(ch))
		{
			chars++;
			tag = 1;
		}
		else if ( isspace(ch))
		{
			spaces++;
			tag = 2;
		}
		else if ( isdigit(ch))
		{
			digit++;
			tag = 3;
		}
		else if ( ispunct(ch))
		{
			punct++;
			tag = 4;
		}
		else
		{
			others++;
			tag = 5;
		}
		cin.get(ch);
	}
	cout << chars << "letters " << spaces << "whitespace " << digit << "digit " << punct << "punct "
	     << others << "others.\n";
	return 0;
}


int main()
{
	char *c=(char *)malloc(10000);
	gets(c);
	string str=c;
	int len=str.length();
	int loc = str.length()-len-1;
	
	while(len--)
	{
		if(c[loc]>='A'&&c[loc]<='Z')
		{
			;
//			c[loc]=c[loc]+'a'-'A';
		}
		else if(c[loc]>='a'&&c[loc]<='z')
		{   // 小写字母换成大写字母的方法
			c[loc]=c[loc]+'A'-'a';
		}
		else if(c[loc]==' ')
		{
			;
		}
		else
		{
			c[loc]='\0';
		}
	}
	cout<<c;
	
	free(c);
	return 0;
}


int isprime(int a); // 判断是否为素数

int main(void)
{
	int pInt[10000];
	int count = 0;
	int c = 0;
	
	while (scanf("%d", &pInt[count]) != EOF && pInt[count] != 0)
	{
		count++;
	}
	
	for (int i = 0; i < count; ++i)
	{
		if (isprime(pInt[i]) == 1)
		{
			c=i; // 一直更新c直到最后一次，保存最后一次的i值，然后就可以用来判断是否到了最后一个素数了！！！
			
		}
	}
	
	for (int i = 0; i < count; ++i)
	{
		if (isprime(pInt[i]) == 1)
		{
			printf(i == c ? "%d" : "%d ", pInt[i]);  /// 极好的控制方法，最后一个数字后面没有空格
//			cout<< " ";
//			cout << pInt[i];
		}
	}
	return 0;
}

int isprime(int a)
{/// 还是写函数的功底不够扎实，自己写的又有问题了，还没有改正
	int m = a - 1, i;//定义初始值m=a-1实现对的排除
	for (i = a - 1; i > 1 && m != 0; i--) //循环判断直至能够整除或者对全部正整数判断完毕
	{
		m = a % i;
	}
	return (m != 0 ? 1 : 0);
}
*/

/*
// 第二题 求数组中的最大和最小元素

int imax(int array[], int count); // 求整形数组的最大元素
int imin(int array[], int count); // 求~~~~~~~~~~~~小~~~~

int main(void)
{
	int n;
	int array[101];
	cin>>n;
	int m=n;
	while(n--)
	{
		cin>>array[n];
	}
	
	cout<<imax(array, m)<<endl;
	cout<<imin(array, m)<<endl;
	
	return 0;
}

int imax(int *array, int count)
{
	int max = -65535;
	for (int i = 0; i < count; ++i)
	{
		if(array[i] > max)
		{
			max = array[i];
		}
	}
	
	return max;
}
int imin(int *array, int count)
{
	int min = 65534;
	for (int i = 0; i < count; ++i)
	{
		if(array[i] < min)
		{
			min = array[i];
		}
	}
	
	return min;
}
*/

/*
// 这个是第一题，字符串的逆置，字符数作为参数传递
 void mystrrev(char str[]);

int main()
{
	char str[101];
	int i = 0;
	
	cin.get(str, 101);//输入字符串，允许输入空格
	
	mystrrev(str);
	
	return 0;
}

void mystrrev(char str[])
{
 // 该函数只用了原来的数组加一个临时变量就完成了字符串的逆置
 // 从两边向中间互换
	int m = strlen(str);
	int mid;
	for (int i = 0; i < m / 2; i++)
	 {//将字符串的前一半字符与后一半字符对应交换，因而只执行m/2
		mid = str[i];
		str[i] = str[m - i - 1];
		str[m - i - 1] = mid;
	}
	
	for (int j = 0; j < m; ++j)
	{
		cout<<str[j];
	}
}
*/