/*  ָ����ǰ�����������е�ʹ�ã���̬�ڴ���䣬vector������װ�Ķ�̬���飩�����������
 *  2017��4��12��15:09:17
 *  ǳ���ƺ���Ƶ�����ǳ���Ƶ�����������ͬһ���ڴ�ռ䣬Ҫ���ͷſռ�ʱ�򣬸ÿռ䱻�����ͷţ��������д���
 * */

#include <vector>
#include <iostream>

using namespace std;

class first; // ǰ����������
class second{
	//first x; //error: field 'x' has incomplete type 'first'
	// �����������Ϊ��Ķ����в�����
	first *x; // ����second��������һ����first��ָ�루���Ƕ���
};

class first{
	second y;
};

int main()
{
	// ��̬����һ��int�������ݵ��ڴ�ռ䣬����3��ֵ����ÿռ��У�Ȼ���׵�ַ����pInt
	int *pInt;
	pInt = new int(3);

	// ����ǵ���delete�ͷ���οռ� delete ָ����
	// ���ɾ�����Ƕ�����ô�ö�������������ᱻ����
	delete pInt;

	// ��̬����һ������
	int *p = new int[10] ();
	// �����в������κβ����������ˣ�����͸��������Ԫ����0��ʼ����

	// �ͷ�һ������Ŀռ�
	delete []p;
	// ��ָ��ǰ��Ҫ��[]

	unsigned int length = 10;
	vector <double> arr(length);

	std::cout << "Hello, World!" << std::endl;
	return 0;
}
