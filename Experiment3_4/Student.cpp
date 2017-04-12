//
// Created by Cooper on 17/03/2017.
//
#include "Student.h"

// 相关函数的实现

Student::Student()
{
// 通过手动赋值的构造函数
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

    // 设置变量的默认值
	cout<<"the constructor is called!"<<endl;
    num ++;// 每次调用构造函数就给学号加1

	name++; // 每次调用构造函数就给名字的字母往后加1

    for (int i = 0; i < CLASS; ++i) {
        grade[i]=90+i;
    }
    sex = "male";
    age = 18;

	count++; // 学生数+1
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

float Student::gradesum(Student stu)  // 相当于gettotal函数，求总分
{
	float gradesum = 0;

	for (int i = 0; i < CLASS; ++i)
	{
		gradesum += stu.grade[i];
	}
	return gradesum;
}

/// 静态数据成员的定义和初始化用类名限定！
/// 需要放到类定义的外面

char Student::name = 'a';
int Student::num = 1;
int Student::count = 0;

//Student::Student()
//{
//	// empty constructor
//}
