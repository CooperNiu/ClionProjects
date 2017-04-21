/*
 * 1.��C++ģ���ʹ��
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
// ���ء�+��
Point <T> operator +(const Point <T> & A, const Point <T> & B)
{
	return Point <T>(A.x + B.x, A.y + B.y);
}

template < typename T >
// ���ء�<<��
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

// ������
/*
int main()
{
	*/
/*
	// ��һ�δ���ʵ���˶�ȡһ���ɿո�ָ������֣����������Ĺ���
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
	 // ���ط��ŵ���ϰ
	double a[] = {1.1, 2.2, 3.3, 4.4};
	cout << sum(a, a + 4) << "\n";

	Point<int> b[] = {Point<int>(1,2), Point<int>(3,4), Point<int>(5,6),Point<int>(7,8)};

	cout<<sum(b, b+4)<<"\n";*//*



	*/
/*//*
/ ��һ��ͬʱʹ��int��double��point
	Point<int> a(1, 2), b(3,4);
	Point<double> c(1.1, 2.2), d(3.3, 4.4);

	cout<<a+b<<" "<<c+d<<endl;*//*


	return 0;
}*/
