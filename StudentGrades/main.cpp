/*
* Copyright (c) 2001,上海贝尔有限公司网络应用事业部
* All rights reserved.
*
* 文件名称：filename.h
* 文件标识：见配置管理计划书
* 摘 要：简要描述本文件的内容
*
* 当前版本：1.1
* 作 者：输入作者（或修改者）名字
* 完成日期：2001年7月20日
*
* 取代版本：1.0
* 原作者 ：输入原作者（或修改者）名字
* 完成日期：2001年5月10日
*/


/*
 * 在校大学生一枚，搬运工，资源控，视觉系，资深电影及音乐发烧友，善发现，喜分享，以感恩先行者的名义为后继者分享，
 * 这个世界美好的东西太多，关键在于有一颗发现的心，一份分享的情怀，互联无极限，探索无止境！
 */

#include "CommonUsageHeader.h"
// I made a commonly use header so that I can use it any time I program!
// No repetition is better

int main()
{
    // ask for and read the student's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // ask for and read the homework grades
    cout << "Enter all your homework grades, "
            "followed by end-of-file: ";

    // define a vector named "homework"
    vector<double> homework;
    double x;
    // invariant: homework contains all the homework grades read so far
    while (cin >> x)
        homework.push_back(x);

    // check that the student entered some homework grades
    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();
    if (size == 0) {
        cout << endl << "You must enter your grades.  "
                "Please try again." << endl;
        return 1;
    }

    // sort the grades
    sort(homework.begin(), homework.end());

    // compute the median homework grade
    vec_sz mid = size/2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2
                           : homework[mid];

    // compute and write the final grade
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec) << endl;

    return 0;
}
