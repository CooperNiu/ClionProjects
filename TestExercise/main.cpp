
// @�ҵ��㷨�ʼǡ���
/* ö�ٷ�Ҳ���м��ɵģ�
 * 1. �������ö�ٷ�Χ
 * 2. ������ֵ����ôֵ�ʹӴ�С�ԣ�����С����С������
 *
 * */
//5��д��������ƽ��ֵ��ͨ�ú�����20�֣�
//��Ŀ���ݣ�
//��д����ѧ��������ƽ��ֵ��ͨ�ú��������Լ������ָ�������ں�����ƽ��ֵ(ȡ������)��
//��������ƽ��ֵ������������ԭ��Ϊ��
//int  func1(int x);
//int  func2(int x)
//ֻ���ǲ���Ϊ������������ɡ�
//func1����ѧ���ʽΪ��y = a*x ^ 2 + b*x + c��a, b, c���û����룻
//func2����ѧ���ʽΪ��y = x^m��m���û����룻
//ͨ�ú����Ĳ���Ϊ��������ƽ��ֵ������ָ�룬�Լ������������½����Ͻ硣
//���� func1 = 3 * x ^ 2 + 2 * x + 1, �����½����Ͻ�ֱ�Ϊ0��3����
//func1(0) = 1
//func1(1) = 6
//func1(2) = 17
//func1(3) = 34
//��ƽ��ֵΪ����1 + 6 + 17 + 34�� / 4 = 14 ��ֱ��ȡ������������)
//��ʾ����1�����ں���ԭ�͵����ƣ�a, b, c��m��������ʹ��ȫ�ֱ������ݡ�
//��2��ͨ�ú���ԭ�Ϳ���Ϊ��int avg(int(*f)(int), int x1, int x2);
//
//
//�����ʽ:
//�û��������룺
//func1�Ĳ��� a, b, c
//func2�Ĳ��� m
//�����������½����Ͻ�
//
//�����ʽ��
//func1��������ƽ��ֵ
//func2��������ƽ��ֵ
//
//����������
//3 2 1
//1
//0 3
//
//���������
//14
//1
#include<iostream>
using namespace std;
int a, b, c, m;
#include<math.h>
#include <cstdlib>
int func1(int x)
{
	return( a*x*x + b*x + c);
}

int func2(int x)
{
	return(int(pow(x,m)));
}

int avg(int(*f)(int x), int x1, int x2)
{
	int sum = 0;
	for (int i = x1; i <= x2; i++)
	{
		sum = (*f)(i)+sum;
	}
	return int(sum / (x2 - x1 + 1));
}
int main()
{
	int up=0 , down=0;
	cin >> a >> b >> c;
	cin >> m;
	cin >> down >> up;
	cout << avg(func1, down, up) << endl;
	cout << avg(func2, down, up);
	system("pause");
	return 0;
}
/*
ʹ�ú���ָ���л����ܷ�����20�֣�
��Ŀ���ݣ�
��д�������ܺ�������һ������ʹ�ÿ������ܷ���������ԭ����Сд��ĸ����ĸ���������ĵ�3����ĸ�Ĵ�д��ʽ���滻����д��ĸ��ͬ��������Сд��ĸ�滻���ɽ���ĸ��������ĩ�νӵġ�����"AMDxyzXYZ" ����Ϊ "dpgABCabc"���ڶ�������ʹ�õ�˫�ż��ܷ��������ַ���"abcde",���ݵ�˫������Ϊ�����ַ���"ace"��"bd"����������һ���Ϊ����"acebd"��
�û�����һ���ַ�����Ϊ���ģ�����������1��2������1ʹ�õ�һ���������ܲ�������ģ�����2ʹ�õڶ����������ܲ�������ġ�Ҫ��ʹ�ú���ָ�����л����ܺ�����

��ʾ������������ԭ�Ϳ���Ϊ��
void caesar(char str[]);
void oddeven(char str[]);
void cipher(void (*f)(char str[]),char str[]);//�β�Ϊָ������ָ�룬��Ӧʵ�ο�Ϊ��Ӧ��ʽ�ĺ�������


�����ʽ:
һ���ַ�����Ϊ���ģ�����������1��2������1ʹ�õ�һ���������ܲ�������ģ�����2ʹ�õڶ����������ܲ�������ġ�

�����ʽ��
���ܺ������

����������
jacky
2

���������
jcyak
ʱ�����ƣ�500ms�ڴ����ƣ�32000kb

 */
/*
#include<iostream>
using namespace std;
void caesar(char s[])
{
	for(int i=0;s[i]!='\0';i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
			if((s[i]+3)<='Z')
				s[i]=s[i]+35;
			else
				s[i]=s[i]+9;
		else if((s[i]+3)<='z')
			s[i]=s[i]-29;
		else
			s[i]=s[i]-55;
	}
}

void oddeven(char s[])
{
	char a[20];
	int i,k;
	for(i=0;s[i]!='\0';i++)
	{
		if(i%2==0)
			s[i/2]=s[i];
		else
			a[i/2]=s[i];
	}
	for(k=0;k<=i/2;k++)
		if(i%2==0)
			s[i/2+k]=a[k];
		else
			s[i/2+k+1]=a[k];
	s[i]='\0';

}

void cipher(void (*f)(char s[]),char s[])
{
	(*f)(s);
}

int main()
{
	char a[100];
	int n;
	cin.getline(a,99);
	cin>>n;
	switch(n)
	{
		case 1:
			cipher(caesar,a);
			break;
		case 2:
			cipher(oddeven,a);
			break;
	}
	cout<<a<<endl;
	return 0;
}
*/
/* // �Լ�д�ģ��ڶ��������������⣬�������
void caesar(char * str);
void oddeven(char * str);
void cipher(void (* f)(char * str), char * str);
//�β�Ϊָ������ָ�룬��Ӧʵ�ο�Ϊ��Ӧ��ʽ�ĺ�������

int main()
{
	int n = 0;
	char * str = new char[101];
	cin >> str;
	cin >> n;

	if (n == 1) {
		cipher(caesar, str);
	}
	else if (n == 2) {
		cipher(oddeven, str);
	}
	return 0;
}

void caesar(char * str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			if ((str[i] + 3) <= 'Z')
				str[i] = str[i] + 35;
			else
				str[i] = str[i] + 9;
		else if ((str[i] + 3) <= 'z')
			str[i] = str[i] - 29;
		else
			str[i] = str[i] - 55;
	}

	cout << str;
}
void oddeven(char * str)
{
	char temp[1000];
	for (int i = 0; i < temp[i] != '\0'; i++) {
		if (i % 2 == 0)
			str[i / 2] = str[i];
		else
			temp[i / 2] = str[i];
	}

	for (int i = 0; i <= i / 2; i++) {
		if (i % 2 == 0)
			str[i / 2 + i] = temp[i];
		else
			str[i / 2 + i + 1] = temp[i];
		str[i]='\0';
	}
//	for (int j = 0; str[j]!='\0'; ++j) {
	cout << temp;
//	}
//
}
void cipher(void (* f)(char *), char * str)
{
	f(str);
}*/
/*
5��д��������ƽ��ֵ��ͨ�ú�����20�֣�
��Ŀ���ݣ�
��д����ѧ��������ƽ��ֵ��ͨ�ú��������Լ������ָ�������ں�����ƽ��ֵ(ȡ������)��
��������ƽ��ֵ������������ԭ��Ϊ��
int  func1(int x);
int  func2(int x)
ֻ���ǲ���Ϊ������������ɡ�
func1����ѧ���ʽΪ��y=temp*x^2+b*x+c��temp,b,c���û����룻
func2����ѧ���ʽΪ��y=x^m��m���û����룻
ͨ�ú����Ĳ���Ϊ��������ƽ��ֵ������ָ�룬�Լ������������½����Ͻ硣
���� func1 = 3*x^2+2*x+1, �����½����Ͻ�ֱ�Ϊ0��3����
func1(0)=1
func1(1)=6
func1(2)=17
func1(3)=34
��ƽ��ֵΪ����1+6+17+34��/4=14 ��ֱ��ȡ������������)
��ʾ����1�����ں���ԭ�͵����ƣ�temp,b,c��m��������ʹ��ȫ�ֱ������ݡ�
��2��ͨ�ú���ԭ�Ϳ���Ϊ��int avg( int (*f)(int),int x1,int x2);


�����ʽ:
�û��������룺
func1�Ĳ��� temp,b,c
func2�Ĳ��� m
�����������½����Ͻ�

�����ʽ��
func1��������ƽ��ֵ
func2��������ƽ��ֵ

����������
3 2 1
1
0 3

���������
14
1

ʱ�����ƣ�500ms�ڴ����ƣ�32000kb
 */
/*
 * �������㣨20�֣�
��Ŀ���ݣ�
��дһ�����������ڽ�һ��int���͵��������㣨����ָ��ǰn��Ԫ��ȫ����Ϊ0��������-1��β����-1�������ڴ������С�Ҫ������ʹ�õ�ַ���ݣ���ָ�룩��

��ʾ������ֻҪ���β���ʹ������ָ�룬��Ӧ��ʵ��������������Ϊ��������������׵�ַ������������ʹ���±��������Ԫ�ء�
���� int temp[100],*p=temp;   //a������a���׵�ַ��
��p[i]�൱��a[i]��

�����ʽ:
��һ����������Ԫ�أ��ڶ��е������������Ԫ�ظ���n

�����ʽ��
����������Ԫ��,ע�����һ��Ԫ�غ�Ҫ���ո�

����������
503 87 512 61 908 170 897 275 653 426 154 509 612 677 765 703 -1
5

���������
0 0 0 0 0 170 897 275 653 426 154 509 612 677 765 703

ʱ�����ƣ�500ms�ڴ����ƣ�32000kb

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cchar>

using namespace std;

void mani_array(int * temp, int n);

int length=0;

int main(void)
{
	// ���붯̬����
	int * pInt= new int[101];// str ����ռ�ĵ�ַ
	int n = 0;

	for (int i = 0; ; i++) {
		cin >> pInt[i];
		if(pInt[i] == -1){
			break;
		}
		length++;
	}

	cin>>n;

	mani_array(pInt, n);


	delete[]pInt;
	return 0;
}

void mani_array(int * temp, int n)
{
	for (int j = 0; j < n; ++j) {
		temp[j] = 0;
	}
	for (int i = 0; i < length; ++i) {
		cout<<temp[i];
		if(i<length-1){
			cout<<' ';
		}
	}
}
*/
/*
int main(void)
{
	char temp[101], str[101];
	int i, len, mid, next, top;

	gets(temp);
	len = strlen(temp);
	mid = len / 2 - 1;

	top = 0;
	for (i = 0; i <= mid; i++) {
		str[++top] = temp[i];
	}

	if (len % 2 == 0) {
		next = mid + 1;
	}
	else {
		next = mid + 2;
	}

	for (i = next; i <= len - 1; ++i) {
		if (temp[i] != str[top])
			break;
		top--;
	}

	if (top == 0)
		printf("YES");
	else
		printf("NO");

	getchar();
	getchar();

	return 0;
}*/
/*
 * // 2017��4��10��16:59:09�������⣬��������0
 * // 2017��4��12��23:46:56��������ˣ������õ����ô���
 * //  ���������ʱ��ֱ����-1����Ϊ�ж������Ϳ�����
 * // ��д����������������
void add_array(int * temp, int &sum);

int main(void)
{
	// ���붯̬����
	int * pInt= new int[101];// str ����ռ�ĵ�ַ
	int sum = 0;

	for (int i = 0; ; i++) {
		cin >> pInt[i];
		if(pInt[i] == -1){
			break;
		}
	}

	add_array(pInt, sum);


	delete[]pInt;
	return 0;
}

void add_array(int * temp, int &sum)
{
	for (int i = 0; ; i++) {

		if(temp[i] == -1){
			break;
		}
		sum += temp[i];
	}
	cout << sum;
}
 */
/*
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cchar>

using namespace std;


// �����±��ѵ�� 0�⣬��д������������������ֵ
void reset(int & temp, int & b);

int main()
{
	int temp, b;

	cin >> temp >> b;
	reset(temp, b);
	return 0;
}

void reset(int & temp, int & b)
{
	int temp = (temp + b + 1) / 2;
	temp = b = temp;
	cout << temp << " " << b;
}
 */

/*int main()
{
	// ���뵥������
	int *pInt = new int; // ����һ������������
	*pInt=100; // ������ֵ��Ϊ100
	// ���� int *pInt = new int(100);

	// ���붯̬����
	char *str;
	str = new char[80]; // str ����ռ�ĵ�ַ

	int n , *p;
	cout<<"input n:";
	cin >> n;
	p = new int[n];
	if(NULL == p){
		cout<<"�ռ�����ʧ�ܣ�"<<endl;
	}
	// �м������룬����deleteɾ���������Է��ڴ�й©
	delete pInt;
	delete[](str);
	delete[]p;

*/
/* ���ַ����ڱ�׼C++���ǲ������
	int n;
	cin >> n;
	int temp[n];
 */
/*
	return 0;
}*/
/*  // ��Ӳ��
char Left[3][7];

char Rigth[3][7];

char ressult[3][7];

bool IsFake(char c, bool light);
// Light Ϊ���ʾ����ٱ�Ϊ��

int main()
{
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 3; ++i) {
			cin>>Left[i]>>Rigth[i]>>ressult[i];
		}

		for(char c='A'; c<='L'; c++){
			if(IsFake(c, true)){
				cout<<c<<" is the counterfeit coin and it is light.\n";
				break;
			}
			else if(IsFake(c, false)){
				cout<<c<<" is the counterfeit coin and it is heavy.\n";
				break;
			}
		}
	}
	return 0;
}

bool IsFake(char c, bool light)
{
	for (int i = 0; i < 3; ++i) {
		char *pleft, *pright;
		if(light){
			pleft=Left[i];
			pright=Rigth[i];
		}
		else{
			pleft=Rigth[i];
			pright=Left[i];
		}
		switch (ressult[i][0]){
			case 'u':
				if(strchr(pright, c)==NULL)
					return false;
				break;
			case 'e':
				if(strchr(pleft, c)==NULL || strchr(pright, c))
					return false;
				break;
			case 'd':
				if(strchr(pright, c)==NULL)
					return false;
				break;
		}
	}
}*/

/* // ����swap���������������������кö������أ����Կ���
 * // ������ֲ�ͬ���������ͣ��������ܷ��㣬�����Լ�д��Ч�ĺ�����
 * int main()
{
	char temp = 'temp', b = 'b';
	swap(temp, b);

	cout << temp << b << endl;
	return 0;
}*/

/* // C++��ϰ��
//5��д�ݹ麯����ʹ�ַ�������20�֣�
//��Ŀ���ݣ�
//��д������ʹһ���ַ������������Ҫ������õݹ麯����
//
//�����ʽ :
//һ���ַ��������ᳬ��100���ַ������м���ܰ����ո�
//
//�����ʽ��
//���ַ���������
//
//����������
//Hello, everyone
//
//���������
//enoyreve, olleH
#include<iostream>
#include<char.h>
using namespace std;
void rev(char str[], int n);
void allrev(char str[]);
int main()
{
	char str[100];
	cin.getline(str, 100); // ��ȡ�ַ���
	allrev(str); // ���ú��������ַ���
	cout << str;
//	system("pause");
	return 0;
}
void rev(char &temp, char &b)
{
	char temp = temp;
	temp = b;
	b = temp;
}

void allrev(char str[])
{
	int length = strlen(str);
	for (int i = 0; i < length/2; i++)
	{ // ����i����length-i-1��Ԫ�ػ���
      // �Ҽǵ���һ���⺯��
		rev(str[i], str[length - 1 - i]);
	}
}*/

/*
void sort(int data[], int n);
void sort(int &temp, int &b, int &c, int &d);
void sort(int & temp, int & b, int & c);
void sort(int &temp, int &b);
void sort(int &temp, int &b, int &c);
void print(int data[], int n);

//���������أ�20�֣�
//��Ŀ���ݣ�
//��дһ�����ص������������Զ����������������������ĸ���������������Ӵ�С����,������Ϊsort,������������Ӧʹ�õݹ�ķ���������print��������һ����ʾ����������Ԫ�ء�
//���������£�
int main()
{
	int temp,b,c,d;
	int data[100];
	int i,n,i;
	cin>>i;
	switch(i)
	{
		case 1:
			cin>>temp>>b;
			sort(temp,b);
			cout<<temp<<" "<<b<<endl;
			break;
		case 2:
			cin>>temp>>b>>c;
			sort(temp,b,c);
			cout<<temp<<" "<<b<<" "<<c<<endl;
			break;
		case 3:
			cin>>temp>>b>>c>>d;
			sort(temp,b,c,d);
			cout<<temp<<" "<<b<<" "<<c<<" "<<d<<endl;
			break;
		case 4:
			cin>>n;
			for(i=0;i<n;i++)
			{
				cin>>data[i];
			}
			sort(data,n);
			print(data,n);
			break;
	}
	return 0;
}
//�����ʽ:
//	������������Լ�������
//
//�����ʽ��
//���������ݣ�һ�У��Ӵ�С��ĩβû�пո�
//
//����������
//4
//10
//22 15 20 16 3 27 14 64 108 10
//
//���������
//108 64 27 22 20 16 15 14 10 3
//
//���ύ�������򣬰���������main()
//
//ʱ�����ƣ�500ms�ڴ����ƣ�32000kb

void sort(int & temp, int & b)
{
	if (temp<b)
	{
		int temp = temp;
		temp = b;
		b = temp;
	}
}

void sort(int & temp, int & b, int & c)
{
	sort(temp, b);
	sort(temp, c);
	sort(b, c);
}
void print(int * data, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << data[i];
		if (i != n-1)
		{
			cout << " ";
		}
	}
}
void sort(int & temp, int & b, int & c, int & d)
{
	sort(temp, b, c);
	sort(temp, d);
	sort(b, c, d);
}
void sort(int * data, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1 - i; j++)
		{
			sort(data[j], data[j + 1]);
		}
	}
}
*/

// �����ַ��������ַ�֮��ӿո�ԭ������char���͵�
// ����Ҳ����ָ�룬�򵥵Ĵ����ֱ���Լ�д��Ҫ�Ǹ��ӾͿ����ÿ⺯��
//void print_spaced(char * ch);
//void print_spaced(char str);
//int main()
//{
//	char ch[202];
//	char str;
//	cin.getline(ch, 101);
//	cin >> str;
//
//	print_spaced(ch);
//	print_spaced(str);
//	return 0;
//}
//
//void print_spaced(char str[])
//{
//	int length = strlen(str);
//	char temp[100];
//	for (int i = 0; i < length; i++) {
//		temp[i] = str[i];
//	}
//
//	int j = 0;
//	for (int i = 0; i < length; i++) {
//		str[j] = temp[i];
//		j++;
//		if (i != length - 1) {
//			str[j] = 32;
//			j++;
//		}
//	}
//	str[j] = 0;
//	cout<<str<<endl;
//}
////void print_spaced(char * ch)
////{
////	char newch[202];
////
////	for (int j = 1; j < 202; j = j + 2) {
////		newch[j] = ' ';
////	}
////	//i < sizeof(ch)/ sizeof(int)
////	for (int i = 0; ch[i] != '\0'; i = i + 2) {
////		newch[i] = ch[i];
////	}
////
////	for (int k = 0; newch[k] != '\0'; ++k) {
////		printf("%c", newch[k]);
////	}
////}
//
//void print_spaced(char str)
//{
//	int length = str.length();
//	char temp;
//	for (int i = 0; i < length; ++i) {
//		temp = temp + str[i];
//		if (i != length - 1) {
//			temp = temp + ' ';
//		}
//	}
//	str = temp;
//	cout << str;
//}



//// ����������������������ܳ�
//inline int rectangle(int m, int n);
//
//int main()
//{
//	int m, n;
//	scanf("%d%d", &m, &n);
//
//	rectangle(m, n);
//	return 0;
//}
//int rectangle(int m, int n)
//{
//	printf("%d", m*n);
//	printf(" %d", m+m+n+n);
//
//	return 0;
//}


//// �õݹ麯������������Сֵ
//int m;
//
//int sortmax(int * arr, int n);
//int sortmin(int * arr, int n);
//
//int main(void)
//{
//	scanf("%d", & m);
//	int temp[m];
//	for (int i = 0; i < m; ++i) {
//		scanf("%d", & temp[i]);
//	}
//
//	printf("%d\n", sortmax(temp, m));
//	printf("%d\n", sortmin(temp, m));
//
//	return 0;
//}
//
//int sortmax(int * arr, int n)
//{
//	int max;
//	if (n == 0) {
//		return arr[0];
//	}
//	else {
//		max = sortmax(arr, n - 1);
//		if (max < arr[n - 1]) {
//			max = arr[n - 1];
//
//		}
//	}
//	return max;
//}
//int sortmin(int * arr, int n)
//{
//	int min;
//	if (n == 0) { // �ݹ麯�����˳�����
//		return arr[0];
//	}
//	else {
//		min = sortmin(arr, n - 1);
//		if (min > arr[n - 1])
//			min = arr[n - 1];
//	}
//
//	return min;
//}
//int main()
//{
//	int temp[100], i, j, temp, n;
//	scanf("%d", &n);
//
//	for (int i = 1; i <= n; ++i) {
//		scanf("%d", & n);
//	}
//
//	for (int i = 1; i <= n - 1; ++i) {
//		for (int j = 1; j <= n - i; ++j) {
//			// from the first elem to the last not-sorted elem
//			if (temp[j] < temp[j - 1]) {
//				temp=temp[j];
//				temp[j]=temp[j+1];
//				temp[j+1]=temp;
//			}
//		}
//	}
//
//	for (int i = 1; i <= n ; ++i) {
//		printf("%d  ", temp[i]);
//	}
//
//	getchar();getchar();
//
//	return 0;
//}

////  Dijkstra �㷨 �۽ܿ�˹�� ���·��
//int main(void)
//{
//	int e[10][10]; // store edges
//	int dis[10]; // store minus distance
//	int book[10]; // tell if the element has been visited
//	int inf = 99999999; // store temp infinity intager
//	int n, m; // n stores point number, m stores edge number
//
//	scanf("%d %d", &n, &m);
//
//	//initialize the array
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			if (i == j)
//				e[i][j] = 0;
//			else
//				e[i][j] = inf;
//		}
//	}
//
//	// read the edge
//	for (int i = 1; i <= m; ++i) {
//		int t3, t2, t1;
//		scanf("%d %d %d", &t1, &t2, &t3);
//		e[t1][t2] = t3;
//	}
//
//	// initialize the book array
//	for (int l = 1; l <= n; ++l) {
//		book[l] = 0;
//	}
//	book[1] = 1;
//
//	// Dijkstra algorithm
//	for (int i = 1; i <= n - 1; ++i) {
//		// find the nearest point to 1
//		int min = inf;
//		int u;
//		for (int j = 1; j <= n; ++j) {
//			if (book[j] == 0 && dis[j] < min) {
//				min = dis[j];
//				u = j;
//			}
//		}
//		book[u] = 1;
//		for (int v = 1; v <= n; ++v) {
//			if (e[u][v] < inf) {
//				if(dis[v]>dis[u]+e[u][v]){
//					dis[v]=dis[u]+e[u][v];
//				}
//			}
//		}
//	}
//
//	// output
//	for (int i = 1; i <= n; ++i) {
//		printf("%d ", dis[i]);
//	}
//
//	getchar();
//	getchar();
//	return 0;
//}

// Floyd_Warshall algorithom ���������㷨����ʵ�ֺͲ���
//int main(void)
//{
//	int e[10][10];
//	int inf = 99999999; // �����
//	int m;
//	int n;
//	scanf("%d %d", &n, &m);
//
//	//initialize the array
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			if (i == j)
//				e[i][j] = 0;
//			else
//				e[i][j] = inf;
//		}
//	}
//
//	// read the edge
//	for (int i = 1; i <= m; ++i) {
//		int t3, t2, t1;
//		scanf("%d %d %d", &t1, &t2, &t3);
//		e[t1][t2] = t3;
//	}
//
//	// Floyd_Warshall algorithom
//	for (int i = 1; i <= n; ++i) {
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= n; ++j) {
//				if (e[i][j] > e[i][i] + e[i][j]) {
//					e[i][j] = e[i][i] + e[i][j];
//				}
//			}
//		}
//	}
//
//	// output the outcome
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= n; ++j) {
//			printf("%10d", e[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}

///// ���ź���Ҫ��Ҫ�Լ���д�����֣����ţ�������
//// ��������ʱ���ö��ļ��ķ�ʽ��ȡ����������
//// ���üӷ����ó˷�����߳���Ч��
//// ��������ķ��� int��x+0.5)�Ϳ�����
//
//#include <iostream>
//#include <cstdio>
//#include <cstdlib>
//#include <cmath>
//
//using std::cout;
//using std::cin;
//using std::endl;
////
////int main()
////{
////    char ch, ch1;
////
////    cin>>ch;
////    ch1 = (char)(ch>=97 && ch<=122)? (ch-32): ch;
////    printf("%c", ch1);
////    return 0;
////}
///// ����Ǯ���㷨
///*
//int main() {
//    int n, fifty, twenty, ten, five, one;
//
//    cin >> n;
//
//    fifty = n / 50; //50Ԫ������
//    n=n-50* fifty;
//    twenty = n / 20; //20Ԫ������
//    n=n-20*  twenty;
//    ten = n / 10; //10Ԫ������
//    n=n-10*  ten;
//    five = n / 5;       //5Ԫ������
//    n=n-5*  five;
//    one = n;
//
//    cout << fifty <<' '<< twenty <<' '<< ten <<' '<< five <<' '<< one << endl;
//
//    return 0;
//}
//*/
//
//int Partition(int *x, int low, int high);
//
//void Qsort(int *x, int low, int high);
//
//int cmp(const void *temp, const void *b);
//
//int RandSelect(int *, int low, int high, int middle);
//
//int Partition(int *x, int low, int high) {
//    x[0] = x[low];
//    int pivotkey = x[low];
//
//    while (low < high) {
//        while (low < high && x[high] >= pivotkey)
//            --high;
//        x[low] = x[high];
//
//        while (low < high && x[low] <= pivotkey)
//            ++low;
//        x[high] = x[low];
//    }
//
//    x[low] = pivotkey;
//
//    return low;
//}
//
//void Qsort(int *x, int low, int high) {
//    // ����
//    if (low < high) {
//    int pivotloc = Partition(x, low, high);
//    Qsort(x, low, pivotloc - 1);
//    Qsort(x, pivotloc + 1, high);
//}
//}
//
////Qsort
//
////int main(void)
////{   int n;
////    int x[10001];
////    int y[10001];
////    int z[10001];
////    int xkey, ykey;
////    int sum = 0;
////
////    cin>>n;
////    for (int k = 0; k < n; ++k){
////        scanf("%d %d", &x[k], &y[k]);
////    }
////
////    qsort(x, n, sizeof(int), cmp); //��x�ϵ����ݽ�������ѡ����iС����
////
////    for (int i = 1; i <= n; ++i) {
////        z[i]=x[i]-(i-1);
////    }
////    //Qsort(z, 1, n);
////    qsort(z, n, sizeof(int), cmp);
////    qsort(y, n, sizeof(int), cmp);
////
////    xkey = y[n/2];
////    ykey = z[n/2];
//// xkey = RandSelect(y, 1, n, n/2);
//// ykey = RandSelect(z, 1, n, n/2);
////
////    for (int j = 1; j <= n; ++j) {
////        sum += abs(y[j] - ykey);
////        sum += abs(z[j] - xkey);
////    }
////
////    printf("%d", sum);
////    return 0;
////}
////
////int RandSelect(int *Array, int low, int high, int middle) {
////    return Array[middle];
////}
//
//#include<stdio.h>
//#include <stdlib.h>
//#include <algorithm>

//using namespace std;
//
//int main()
//{
//    int n;
//    int x[10010],y[10010];
//    while(scanf("%d",&n)!=EOF)
//    {
//
//        for(int i=0;i<n;i++)
//        scanf("%d%d",&x[i],&y[i]);
//
//        sortmax(y,y+n);
//        int i=y[n/2];
//        int str=0;
//        for(int i=0;i<n;i++)
//            str+=fabs(i-y[i]);
//        sortmax(x,x+n);
//        for(int i=0;i<n;i++)
//            x[i]-=i;//���λ�ò���
//        sortmax(x,x+n);
//        i=x[n/2];
//        for(int i=0;i<n;i++)
//            str+=fabs(i-x[i]);
//
//        printf("%d\n",str);
//    }
//}

///// Accepted!
//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#include <algorithm>
//
//using namespace std;
//
//int cmp(const void *temp, const void *b)
//{
//    return *(int*)temp-*(int*)b;
//}
//int main()
//{
//    int n,i,x_mid, y_mid,count=0;
//    int *x, *y;
//    scanf("%d", &n);
//    x=(int *)malloc(sizeof(int)*n);
//    y=(int *)malloc(sizeof(int)*n);
//    for(i=0; i<n; i++) scanf("%d %d", &x[i], &y[i]);
//
//    //����
//    qsort(y, n, sizeof(int), cmp);
//    qsort(x, n, sizeof(int), cmp);
//    for(i=0; i<n; i++) x[i] -= i;
//    qsort(x, n, sizeof(int), cmp);
//    x_mid=x[n/2];
//    y_mid=y[n/2];
//    for(i=0; i<n; i++)
//        count += abs(x[i]-x_mid) + abs(y[i]-y_mid);
//
//    printf("%d\n", count);
//
//    return 0;
//}

//#include<iostream>
//#include<cstdio>
//using namespace std;
//
//const int lmax = 301;
//
//const int Lmax = 3000000;
//
//int cost[lmax][lmax], min_sum[lmax][lmax];
//
//int d[lmax];
//
//int main()
//{
//	int v, postoffice, i, j, i, middle;
//	scanf("%d%d", &v, &postoffice);
//	for (i = 1; i <= v; i++)
//		scanf("%d", &d[i]);
//	for (i = 1; i < v; i++) {
//		for (j = i; j <= v; j++) {
//			cost[i][j] = 0;
//			if (i == j)continue;
//			middle = (i + j) / 2;
//			for (i = i; i <= j; i++) {
//				cost[i][j] += (d[i] - d[middle]) > 0 ? d[i] - d[middle] : d[middle] - d[i];
//			}
//		}
//	}
//	for (i = 1; i <= postoffice; i++) {
//		for (j = 1; j <= v; j++) {
//			min_sum[i][j] = Lmax;
//		}
//	}
//	for (i = 1; i <= v; i++) {
//		min_sum[1][i] = cost[1][i];
//	}
//	for (i = 2; i <= postoffice; i++) {
//		for (j = 1; j <= v; j++) {
//			for (i = 1; i < j; i++) {
//				if (min_sum[i][j] > min_sum[i - 1][i] + cost[i + 1][j]) {
//					min_sum[i][j] = min_sum[i - 1][i] + cost[i + 1][j];
//				}
//			}
//		}
//	}
//	printf("%d\n", min_sum[postoffice][v]);
//	return 0;
//}
