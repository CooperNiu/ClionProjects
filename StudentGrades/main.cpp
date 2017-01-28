//#include <algorithm>
//#include<iostream>
//#include <string>
//#include <iomanip>
//#include <ios>
//#include <vector>
//#include <cstdlib>
//
//using namespace std;
//
//int main()
//{
//    //ask for and read the student's name
//    cout<<"Please enter your midterm and final exam grades: ";
//    double midterm, final;
//    cin>>midterm>>final;
//
//    //ask for the homework grades
//    cout<<"Enter all your homework grades,"
//        "followed by end-of-file: ";
//
//    //the number and sum of grades read so far
//    int count = 0;
//    double sum = 0;
//
//    //a viriable into which to read
//    double x;
//
//    //invariant
//    //we have read count grades so far, and
//    //sum is the sum of the first count grades
//    while(cin>>x)
//    {
//        ++count;
//        sum+=x;
//    }
//    /*There are several ways in which trying to read from a stream can be unsuccessful:
//        We might have reached the end of the input file.
//        We might have encountered input that is incompatible with the type of the variable that we are trying to read, such as might happen if we try to read an int and find something that isn't a number.
//        The system might have detected a hardware failure on the input device.
//     */
//
//    // write the result
//    streamsize prec = cout.precision(); //precision means “精度”
//    cout << "Your final grade is " << setprecision(3)
//    <<0.2*midterm + 0.4 * final + 0.4 * sum / count
//    << setprecision(prec) << endl;
//    // setprecision changes the precision of any subsequent output that might appear on cout
//	system("pause");
//	return 0;
//}
/*
 * 在校大学生一枚，搬运工，资源控，视觉系，资深电影及音乐发烧友，善发现，喜分享，以感恩先行者的名义为后继者分享，这个世界美好的东西太多，关键在于有一颗发现的心，一份分享的情怀，互联无极限，探索无止境！
 */

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

///these usages are better than "using namespace std"
using std::cin;             using std::sort;
using std::cout;            using std::streamsize;
using std::endl;            using std::string;
using std::setprecision;    using std::vector;

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
