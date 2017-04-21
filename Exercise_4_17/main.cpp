/*
 * 1.对C++模板的使用
 */
#include <iostream>
#include <sstream>
using namespace std;

template < typename T >
struct Point
{
	T x, y;
	Point(T x = 0, T y = 0)
		: x(x), y(y)
	{}
};

template < typename T >
// 重载“+”
Point <T> operator +(const Point <T> & A, const Point <T> & B)
{
	return Point <T>(A.x + B.x, A.y + B.y);
}

template < typename T >
// 重载“<<”
ostream & operator <<(ostream & out, const Point <T> & p)
{
	out<<"("<<p.x<<","<<p.y<<")";
	return out;
}

template < typename T >
T sum(T * begin, T * end)
{
	T * pInt = begin;
	T ans = 0;
	for (T * pInt = begin; pInt != end; ++pInt) {
		ans = ans + * pInt;
	}
	return ans;
}

// 主函数
/*
int main()
{
	*/
/*
	// 这一段代码实现了读取一串由空格分隔的数字，并求和输出的功能
	string line;
	while (getline(cin, line)){
		int sum=0, x;
		stringstream ss(line);
		while(ss>>x){
			sum+=x;
		}
		cout<<sum<<"\n";
	}*//*

	*/
/*
	 // 重载符号的练习
	double a[] = {1.1, 2.2, 3.3, 4.4};
	cout << sum(a, a + 4) << "\n";

	Point<int> b[] = {Point<int>(1,2), Point<int>(3,4), Point<int>(5,6),Point<int>(7,8)};

	cout<<sum(b, b+4)<<"\n";*//*



	*/
/*//*
/ 这一段同时使用int和double型point
	Point<int> a(1, 2), b(3,4);
	Point<double> c(1.1, 2.2), d(3.3, 4.4);

	cout<<a+b<<" "<<c+d<<endl;*//*


	return 0;
}*/
