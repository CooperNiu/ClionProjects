#include <iostream>

using namespace std;

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

// 第二题 求数组中的最大和最小元素

int imax(int array[], int count); // 求整形数组的最大元素
int imin(int array[], int count); // 求~~~~~~~~~~~~小~~~~

int main(void)
{
	int n;
	int array[101];
	cin>>n;
	
	while(n--)
	{
		cin>>array[n];
	}
	
	cout<<imax(array, n)<<endl;
	cout<<imin(array, n)<<endl;
	
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