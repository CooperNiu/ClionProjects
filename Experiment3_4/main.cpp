//#include <iostream>
//#include "Student.h"
//#include <string>
//
//using namespace std;
//
//int main() {
//    string name = "Cooper";
//    float grade[CLASS];
////	Student stu1, stu2;
//    Student stu3;
//
////    stu1.Student();
////    stu2.Student();
////    stu3.Student();
//
////    stu1.OutPut();
////    stu2.OutPut();
//    stu3.OutPut();
//
//    stu3.~Student();
//
//    stu3.OutPut();
//
//    return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main ( )
//{
//	int i;
//	int f[20] = {1, 1};    //初始化第0、1个数
//	for ( int i = 2; i < 20; i ++ )
//	{ //求第2～19个数
//		f[i] = f[i - 2] + f[i - 1];
//	}
//	for ( int i = 0; i < 20; i ++ )
//	{    //输出，每行5个数
//		if ( i % 5 == 0 )
//		{ cout << endl; }
//		cout . width ( 12 );    //设置输出宽度为12，这个格式控制方式值得学习！
//		cout << f[i];
//	}
//	return 0;
//}

//#include <iostream>
//
//using namespace std;
//
//int main ( )
//{
//	const char KEY[] = {'a', 'c', 'b', 'a', 'd'};
//	const int NUM_QUES = 5;
//	char c;
//	int ques = 0, numCorrect = 0;
//	cout << "Enter the " << NUM_QUES <<
//	     " question tests:" << endl;
//	while ( cin . get ( c ) )
//	{
//		if ( c != '\n' )
//		{
//			if ( c == KEY[ques] )
//			{
//				numCorrect ++;
//				cout << " ";
//			}
//			else
//			{
//				cout << "*";
//			}
//			ques ++;
//		}
//		else
//		{
//			cout << " Score " << static_cast<float>
//			                     (numCorrect) / NUM_QUES * 100 << "%";
//			ques = 0;
//			numCorrect = 0;
//			cout << endl;
//		}
//	}
//	return 0;
//}

////6-3.cpp
//#include "Point.h"
//#include <iostream>
//
//using namespace std;
//
//int main ( )
//{
//	cout << "Entering main..." << endl;
//	Point a[4];
//	// 这句话隐含着构造4个Point类型的对象，所以就调用了4次构造函数
//	for ( int i = 0; i < 4; i ++ )
//	{
//		a[i] . move ( i + 10, i + 20 );
//	}
//	cout << "Exiting main..." << endl;
//	// 主函数退出，而程序并没有结束，还要调用析构函数来释放四个对象所占用的空间
//	return 0;
//}
//
//#include<iostream>
//
//using namespace std;
//
//int i = 1; // i 为全局变量，具有静态生存期。
//void other ( )
//{
//	static int a = 2;
//	static int b;
//	// a,b为静态局部变量，具有全局寿命，局部可见。
//	//只第一次进入函数时被初始化。
//	int c = 10; // C为局部变量，具有动态生存期，
//	//每次进入函数时都初始化。
//	a += 2;
//	i += 32;
//	c += 5;
//	cout << "---OTHER---\n";
//	cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
//	b = a;
//}
//
//int main ( )
//{
//	static int a;//静态局部变量，有全局寿命，局部可见。
//	int b = - 10; // b, c为局部变量，具有动态生存期。
//	int c = 0;
//	cout << "---MAIN---\n";
//	cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
//	c += 8;
//	other ( );
//	cout << "---MAIN---\n";
//	cout << " i: " << i << " a: " << a << " b: " << b << " c: " << c << endl;
//	i += 10;
//	other ( );
//	return 0;
//}

//5_4.cpp
#include <iostream>

using namespace std;

class Point
{    //Point类定义
public:    //外部接口
	Point ( int x = 0, int y = 0 ) : x ( x ), y ( y )
	{ //构造函数
		//在构造函数中对count累加，所有对象共同维护同一个count
		count ++;
	}
	
	Point ( Point &p )
	{    //复制构造函数
		x = p . x;
		y = p . y;
		count ++;
	}
	
	~Point ( )
	{ count --; }
	
	int getX ( )
	{ return x; }
	
	int getY ( )
	{
		return y;
	}
	
	void showCount ( )
	{        //输出静态数据成员
		cout << "  Object count = " << count << endl;
	}

private:    //私有数据成员
	int x, y;
	
	static int count;    //静态数据成员声明，用于记录点的个数
};

int Point::count = 0;//静态数据成员定义和初始化，使用类名限定
int main ( )
{    //主函数
	Point a ( 4, 5 );    //定义对象a，其构造函数回使count增1
	cout << "Point A: " << a . getX ( ) << ", " << a . getY ( );
	a . showCount ( );    //输出对象个数
	Point b ( a );    //定义对象b，其构造函数回使count增1
	cout << "Point B: " << b . getX ( ) << ", " << b . getY ( );
	b . showCount ( );    //输出对象个数
	return 0;
}

