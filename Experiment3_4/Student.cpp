//
// Created by Cooper on 17/03/2017.
//
#include "Student.h"

// ��غ�����ʵ��

Student::Student()
{
// ͨ���ֶ���ֵ�Ĺ��캯��
//    cout<<"Please input the student number:"<<endl;
//    cin>>num;
//    cout<<"Please input the student name:"<<endl;
//    cin>>name;
//    cout<<"Please input the student grades(3 classes) :"<<endl;
//    for (int i = 0; i < 3; ++i) {
//        cin>>grade[i];
//    }
//    cout<<"Please input the student sex:"<<endl;
//    cin>>sex;
//    cout<<"Please input the student age:"<<endl;
//    cin>>age;

    // ���ñ�����Ĭ��ֵ
	cout<<"the constructor is called!"<<endl;
    num ++;// ÿ�ε��ù��캯���͸�ѧ�ż�1

	name++; // ÿ�ε��ù��캯���͸����ֵ���ĸ�����1

    for (int i = 0; i < CLASS; ++i) {
        grade[i]=90+i;
    }
    sex = "male";
    age = 18;

	count++; // ѧ����+1
}

Student::~Student() {
 //    the experiment proves that this empty function cannot make these arguments be null.
    // now I don't know what to declare!
	cout<< "the destructor function called!"<< endl;
}

void Student::OutPut() {
    cout<<num<<endl;
    cout<<name<<endl;
    for (int i = 0; i < 3; ++i) {
        cout<<grade[i]<<endl;
    }
    cout<<sex<<endl;
    cout<<age<<endl;
}
int Student::getCount()
{
	return count;
}

float Student::gradesum(Student stu)  // �൱��gettotal���������ܷ�
{
	float gradesum = 0;

	for (int i = 0; i < CLASS; ++i)
	{
		gradesum += stu.grade[i];
	}
	return gradesum;
}

/// ��̬���ݳ�Ա�Ķ���ͳ�ʼ���������޶���
/// ��Ҫ�ŵ��ඨ�������

char Student::name = 'a';
int Student::num = 1;
int Student::count = 0;

//Student::Student()
//{
//	// empty constructor
//}
