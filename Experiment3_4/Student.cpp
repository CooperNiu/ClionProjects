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
    num = 226;
    name = "Cooper";
    for (int i = 0; i < 3; ++i) {
        grade[i]=90+i;
    }
    sex = "male";
    age = 18;
}

//Student::~Student() {
 ////    the experiment proves that this empty function cannot make these arguments be null.
//    // now I don't know what to declare!
//}

void Student::OutPut() {
    cout<<num<<endl;
    cout<<name<<endl;
    for (int i = 0; i < 3; ++i) {
        cout<<grade[i]<<endl;
    }
    cout<<sex<<endl;
    cout<<age<<endl;
}