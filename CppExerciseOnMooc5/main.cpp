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
	
	cin.get(ch); // �����������ȡ�ַ������Զ���ո�ֱ����β
	
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
		{   // Сд��ĸ���ɴ�д��ĸ�ķ���
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


int isprime(int a); // �ж��Ƿ�Ϊ����

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
			c=i; // һֱ����cֱ�����һ�Σ��������һ�ε�iֵ��Ȼ��Ϳ��������ж��Ƿ������һ�������ˣ�����
			
		}
	}
	
	for (int i = 0; i < count; ++i)
	{
		if (isprime(pInt[i]) == 1)
		{
			printf(i == c ? "%d" : "%d ", pInt[i]);  /// ���õĿ��Ʒ��������һ�����ֺ���û�пո�
//			cout<< " ";
//			cout << pInt[i];
		}
	}
	return 0;
}

int isprime(int a)
{/// ����д�����Ĺ��ײ�����ʵ���Լ�д�����������ˣ���û�и���
	int m = a - 1, i;//�����ʼֵm=a-1ʵ�ֶԵ��ų�
	for (i = a - 1; i > 1 && m != 0; i--) //ѭ���ж�ֱ���ܹ��������߶�ȫ���������ж����
	{
		m = a % i;
	}
	return (m != 0 ? 1 : 0);
}
*/

/*
// �ڶ��� �������е�������СԪ��

int imax(int array[], int count); // ��������������Ԫ��
int imin(int array[], int count); // ��~~~~~~~~~~~~С~~~~

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