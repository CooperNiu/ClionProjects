//
// Created by Cooper on 17/03/2017.
//

#ifndef EXPERIMENT3_4_STUDENT_H
#define EXPERIMENT3_4_STUDENT_H
#include <string>
#include <iostream>

using namespace std;

const int CLASS = 10;

class Student
{
 public:
	int num;
    string name;
	float grade[CLASS];
    string sex;
    int age;

	// ���캯��
  	Student(); //int num, string name, float grade, string sex, int age
	// ��������
//	~Student();

	void OutPut();
};
#endif //EXPERIMENT3_4_STUDENT_H