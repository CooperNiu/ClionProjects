//
// Created by Cooper on 17/03/2017.
//

#ifndef EXPERIMENT3_4_STUDENT_H
#define EXPERIMENT3_4_STUDENT_H
#include <string>
#include <iostream>

using namespace std;

const int CLASS = 10;
const int STU_NUM = 10;

class Student
{
public:
	// ���캯��
//	Student();
	Student(); //int num, string name, float grade, string sex, int age
	// ��������
	~Student();
	//������еĳ�Ա
	void OutPut();

	float gradesum(Student stu);

	static float getTotal();
	static int getCount();
private:
	static int num ;

	static char name ;
//	static string name;
	float grade[CLASS];
	string sex;
	int age;

	static float total;
	static int count;
};
#endif //EXPERIMENT3_4_STUDENT_H