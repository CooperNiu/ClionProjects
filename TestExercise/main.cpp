
// @我的算法笔记——
/* 枚举法也是有技巧的：
 * 1. 合理设计枚举范围
 * 2. 求最大的值，那么值就从大到小试，求最小，从小到大试
 *
 * */

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int main(void)
{
	char a[101], s[101];
	int i, len, mid, next, top;

	gets(a);
	len = strlen(a);
	mid = len / 2 - 1;

	top = 0;
	for (i = 0; i <= mid; i++) {
		s[++top] = a[i];
	}

	if (len % 2 == 0) {
		next = mid + 1;
	}
	else {
		next = mid + 2;
	}

	for (i = next; i <= len - 1; ++i) {
		if (a[i] != s[top])
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
}

/*
 * // 2017年4月10日16:59:09还有问题，运算结果是0
 * //编写函数对数组进行求和
void add_array(int * a, int * sum);

int length = 5; // 数组长度

int main(void)
{
	// 申请动态数组
	int * pInt;
	int sum = 0;

	pInt = new int[101]; // str 保存空间的地址

	for (int i = 0; i < length; i++) {
		cin >> pInt[i];
	}

	add_array(pInt, & sum);
	cout << "The sum is " << sum;

	delete[]pInt;
	return 0;
}

void add_array(int * a, int * sum)
{
	for (int i = 0; i < length; i++) {
		sum += a[i];
	}
}*/
/*
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;


// 第七章编程训练 0题，编写函数重置两个变量的值
void reset(int & a, int & b);

int main()
{
	int a, b;

	cin >> a >> b;
	reset(a, b);
	return 0;
}

void reset(int & a, int & b)
{
	int temp = (a + b + 1) / 2;
	a = b = temp;
	cout << a << " " << b;
}
 */

/*int main()
{
	// 申请单个变量
	int *pInt = new int; // 申请一个无名变量，
	*pInt=100; // 并将其值赋为100
	// 或者 int *pInt = new int(100);

	// 申请动态数组
	char *str;
	str = new char[80]; // str 保存空间的地址

	int n , *p;
	cout<<"input n:";
	cin >> n;
	p = new int[n];
	if(NULL == p){
		cout<<"空间申请失败！"<<endl;
	}
	// 有几个申请，就用delete删除几个，以防内存泄漏
	delete pInt;
	delete[](str);
	delete[]p;

*//* 这种方法在标准C++中是不允许的
	int n;
	cin >> n;
	int a[n];*//*
	return 0;
}*/
/*  // 称硬币
char Left[3][7];

char Rigth[3][7];

char ressult[3][7];

bool IsFake(char c, bool light);
// Light 为真表示假设假币为轻

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

/* // 测试swap这个交换函数，这个函数有好多种重载，所以可以
 * // 处理各种不同的数据类型，用起来很方便，不用自己写低效的函数了
 * int main()
{
	char a = 'a', b = 'b';
	swap(a, b);

	cout << a << b << endl;
	return 0;
}*/

/* // C++练习题
//5编写递归函数来使字符串逆序（20分）
//题目内容：
//编写函数来使一个字符串逆序输出，要求必须用递归函数。
//
//输入格式 :
//一个字符串，不会超过100个字符长，中间可能包含空格
//
//输出格式：
//该字符串的逆序
//
//输入样例：
//Hello, everyone
//
//输出样例：
//enoyreve, olleH
#include<iostream>
#include<string.h>
using namespace std;
void rev(char str[], int n);
void allrev(char str[]);
int main()
{
	char str[100];
	cin.getline(str, 100); // 读取字符串
	allrev(str); // 调用函数逆置字符串
	cout << str;
//	system("pause");
	return 0;
}
void rev(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}

void allrev(char str[])
{
	int length = strlen(str);
	for (int i = 0; i < length/2; i++)
	{ // 将第i个和length-i-1个元素互换
      // 我记得有一个库函数
		rev(str[i], str[length - 1 - i]);
	}
}*/


/*
void sort(int data[], int n);
void sort(int &a, int &b, int &c, int &d);
void sort(int & a, int & b, int & c);
void sort(int &a, int &b);
void sort(int &a, int &b, int &c);
void print(int data[], int n);

//排序函数重载（20分）
//题目内容：
//编写一组重载的排序函数，可以对两个整数、三个整数、四个整数、整数数组从大到小排序,函数名为sort,其中数组排序应使用递归的方法，另补充print函数，在一行显示排序后的数组元素。
//主函数如下：
int main()
{
	int a,b,c,d;
	int data[100];
	int k,n,i;
	cin>>k;
	switch(k)
	{
		case 1:
			cin>>a>>b;
			sort(a,b);
			cout<<a<<" "<<b<<endl;
			break;
		case 2:
			cin>>a>>b>>c;
			sort(a,b,c);
			cout<<a<<" "<<b<<" "<<c<<endl;
			break;
		case 3:
			cin>>a>>b>>c>>d;
			sort(a,b,c,d);
			cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
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
//输入格式:
//	请根据主程序自己分析。
//
//输出格式：
//排序后的数据，一行，从大到小，末尾没有空格。
//
//输入样例：
//4
//10
//22 15 20 16 3 27 14 64 108 10
//
//输出样例：
//108 64 27 22 20 16 15 14 10 3
//
//请提交完整程序，包括给出的main()
//
//时间限制：500ms内存限制：32000kb

void sort(int & a, int & b)
{
	if (a<b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
}

void sort(int & a, int & b, int & c)
{
	sort(a, b);
	sort(a, c);
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
void sort(int & a, int & b, int & c, int & d)
{
	sort(a, b, c);
	sort(a, d);
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


// 处理字符串，在字符之间加空格，原来对于string类型的
// 处理也是用指针，简单的处理就直接自己写，要是复杂就考虑用库函数
//void print_spaced(char * ch);
//void print_spaced(string str);
//int main()
//{
//	char ch[202];
//	string str;
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
//void print_spaced(string str)
//{
//	int length = str.length();
//	string temp;
//	for (int i = 0; i < length; ++i) {
//		temp = temp + str[i];
//		if (i != length - 1) {
//			temp = temp + ' ';
//		}
//	}
//	str = temp;
//	cout << str;
//}



//// 用内联函数求矩阵的面积和周长
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


//// 用递归函数求数组的最大，小值
//int m;
//
//int sortmax(int * arr, int n);
//int sortmin(int * arr, int n);
//
//int main(void)
//{
//	scanf("%d", & m);
//	int a[m];
//	for (int i = 0; i < m; ++i) {
//		scanf("%d", & a[i]);
//	}
//
//	printf("%d\n", sortmax(a, m));
//	printf("%d\n", sortmin(a, m));
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
//	if (n == 0) { // 递归函数的退出条件
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
//	int a[100], i, j, temp, n;
//	scanf("%d", &n);
//
//	for (int k = 1; k <= n; ++k) {
//		scanf("%d", & n);
//	}
//
//	for (int i = 1; i <= n - 1; ++i) {
//		for (int j = 1; j <= n - i; ++j) {
//			// from the first elem to the last not-sorted elem
//			if (a[j] < a[j - 1]) {
//				temp=a[j];
//				a[j]=a[j+1];
//				a[j+1]=temp;
//			}
//		}
//	}
//
//	for (int i = 1; i <= n ; ++i) {
//		printf("%d  ", a[i]);
//	}
//
//	getchar();getchar();
//
//	return 0;
//}

////  Dijkstra 算法 帝杰克斯拉 最短路径
//int main(void)
//{
//	int e[10][10]; // store edges
//	int dis[10]; // store minus distance
//	int book[10]; // tell if the element has been visited
//	int inf = 99999999; // store a infinity intager
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
//	for (int k = 1; k <= m; ++k) {
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

// Floyd_Warshall algorithom 弗洛伊德算法的是实现和测试
//int main(void)
//{
//	int e[10][10];
//	int inf = 99999999; // 无穷大
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
//	for (int k = 1; k <= m; ++k) {
//		int t3, t2, t1;
//		scanf("%d %d %d", &t1, &t2, &t3);
//		e[t1][t2] = t3;
//	}
//
//	// Floyd_Warshall algorithom
//	for (int k = 1; k <= n; ++k) {
//		for (int i = 1; i <= n; ++i) {
//			for (int j = 1; j <= n; ++j) {
//				if (e[i][j] > e[i][k] + e[k][j]) {
//					e[i][j] = e[i][k] + e[k][j];
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

///// 快排很重要，要自己会写，划分，快排，主程序
//// 测试数据时候用读文件的方式来取代键盘输入
//// 能用加法不用乘法，提高程序效率
//// 四舍五入的方法 int（x+0.5)就可以了
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
///// 换零钱的算法
///*
//int main() {
//    int n, fifty, twenty, ten, five, one;
//
//    cin >> n;
//
//    fifty = n / 50; //50元的张数
//    n=n-50* fifty;
//    twenty = n / 20; //20元的张数
//    n=n-20*  twenty;
//    ten = n / 10; //10元的张数
//    n=n-10*  ten;
//    five = n / 5;       //5元的张数
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
//int cmp(const void *a, const void *b);
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
//    // 快排
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
////    qsort(x, n, sizeof(int), cmp); //对x上的数据进行排序，选出第i小的数
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
//        int k=y[n/2];
//        int s=0;
//        for(int i=0;i<n;i++)
//            s+=fabs(k-y[i]);
//        sortmax(x,x+n);
//        for(int i=0;i<n;i++)
//            x[i]-=i;//相对位置不变
//        sortmax(x,x+n);
//        k=x[n/2];
//        for(int i=0;i<n;i++)
//            s+=fabs(k-x[i]);
//
//        printf("%d\n",s);
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
//int cmp(const void *a, const void *b)
//{
//    return *(int*)a-*(int*)b;
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
//    //排序
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
//	int v, postoffice, i, j, k, middle;
//	scanf("%d%d", &v, &postoffice);
//	for (i = 1; i <= v; i++)
//		scanf("%d", &d[i]);
//	for (i = 1; i < v; i++) {
//		for (j = i; j <= v; j++) {
//			cost[i][j] = 0;
//			if (i == j)continue;
//			middle = (i + j) / 2;
//			for (k = i; k <= j; k++) {
//				cost[i][j] += (d[k] - d[middle]) > 0 ? d[k] - d[middle] : d[middle] - d[k];
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
//			for (k = 1; k < j; k++) {
//				if (min_sum[i][j] > min_sum[i - 1][k] + cost[k + 1][j]) {
//					min_sum[i][j] = min_sum[i - 1][k] + cost[k + 1][j];
//				}
//			}
//		}
//	}
//	printf("%d\n", min_sum[postoffice][v]);
//	return 0;
//}
