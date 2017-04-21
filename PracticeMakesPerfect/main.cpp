/*  指针在前向引用声明中的使用，动态内存分配，vector（被封装的动态数组）创建数组对象
 *  2017年4月12日15:09:17
 *  浅复制和深复制的区别：浅复制的两个对象共用同一块内存空间，要是释放空间时候，该空间被两次释放，导致运行错误
 * */

#include <vector>
#include <iostream>

using namespace std;

class first; // 前向引用声明
class second{
	//first x; //error: field 'x' has incomplete type 'first'
	// 这个错误是因为类的定义尚不完善
	first *x; // 这里second声明的是一个类first的指针（不是对象）
};

class first{
	second y;
};

int main()
{
	// 动态分配一个int类型数据的内存空间，并将3的值存入该空间中，然后将首地址赋给pInt
	int *pInt;
	pInt = new int(3);

	// 用完记得用delete释放这段空间 delete 指针名
	// 如果删除的是对象，那么该对象的析构函数会被调用
	delete pInt;

	// 动态创建一个数组
	int *p = new int[10] ();
	// （）中不能有任何参数，但加了（）后就给数组里的元素用0初始化了

	// 释放一个数组的空间
	delete []p;
	// 在指针前面要加[]

	unsigned int length = 10;
	vector <double> arr(length);

	std::cout << "Hello, World!" << std::endl;
	return 0;
}
