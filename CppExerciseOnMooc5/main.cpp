#include <iostream>

using namespace std;

/*
// ����ǵ�һ�⣬�ַ��������ã��ַ�����Ϊ��������
 void mystrrev(char str[]);

int main()
{
	char str[101];
	int i = 0;
	
	cin.get(str, 101);//�����ַ�������������ո�
	
	mystrrev(str);
	
	return 0;
}

void mystrrev(char str[])
{
 // �ú���ֻ����ԭ���������һ����ʱ������������ַ���������
 // ���������м以��
	int m = strlen(str);
	int mid;
	for (int i = 0; i < m / 2; i++)
	 {//���ַ�����ǰһ���ַ����һ���ַ���Ӧ���������ִֻ��m/2
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

// �ڶ��� �������е�������СԪ��

int imax(int array[], int count); // ��������������Ԫ��
int imin(int array[], int count); // ��~~~~~~~~~~~~С~~~~

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