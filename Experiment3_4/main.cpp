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
//	int f[20] = {1, 1};    //��ʼ����0��1����
//	for ( int i = 2; i < 20; i ++ )
//	{ //���2��19����
//		f[i] = f[i - 2] + f[i - 1];
//	}
//	for ( int i = 0; i < 20; i ++ )
//	{    //�����ÿ��5����
//		if ( i % 5 == 0 )
//		{ cout << endl; }
//		cout . width ( 12 );    //����������Ϊ12�������ʽ���Ʒ�ʽֵ��ѧϰ��
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
//	// ��仰�����Ź���4��Point���͵Ķ������Ծ͵�����4�ι��캯��
//	for ( int i = 0; i < 4; i ++ )
//	{
//		a[i] . move ( i + 10, i + 20 );
//	}
//	cout << "Exiting main..." << endl;
//	// �������˳���������û�н�������Ҫ���������������ͷ��ĸ�������ռ�õĿռ�
//	return 0;
//}
//
//#include<iostream>
//
//using namespace std;
//
//int i = 1; // i Ϊȫ�ֱ��������о�̬�����ڡ�
//void other ( )
//{
//	static int a = 2;
//	static int b;
//	// a,bΪ��̬�ֲ�����������ȫ���������ֲ��ɼ���
//	//ֻ��һ�ν��뺯��ʱ����ʼ����
//	int c = 10; // CΪ�ֲ����������ж�̬�����ڣ�
//	//ÿ�ν��뺯��ʱ����ʼ����
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
//	static int a;//��̬�ֲ���������ȫ���������ֲ��ɼ���
//	int b = - 10; // b, cΪ�ֲ����������ж�̬�����ڡ�
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
{    //Point�ඨ��
public:    //�ⲿ�ӿ�
	Point ( int x = 0, int y = 0 ) : x ( x ), y ( y )
	{ //���캯��
		//�ڹ��캯���ж�count�ۼӣ����ж���ͬά��ͬһ��count
		count ++;
	}
	
	Point ( Point &p )
	{    //���ƹ��캯��
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
	{        //�����̬���ݳ�Ա
		cout << "  Object count = " << count << endl;
	}

private:    //˽�����ݳ�Ա
	int x, y;
	
	static int count;    //��̬���ݳ�Ա���������ڼ�¼��ĸ���
};

int Point::count = 0;//��̬���ݳ�Ա����ͳ�ʼ����ʹ�������޶�
int main ( )
{    //������
	Point a ( 4, 5 );    //�������a���乹�캯����ʹcount��1
	cout << "Point A: " << a . getX ( ) << ", " << a . getY ( );
	a . showCount ( );    //����������
	Point b ( a );    //�������b���乹�캯����ʹcount��1
	cout << "Point B: " << b . getX ( ) << ", " << b . getY ( );
	b . showCount ( );    //����������
	return 0;
}

