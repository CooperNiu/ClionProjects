#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
#include <queue>

using namespace std;

int add(int a, int b );
float add(float a, float b);
int divide(int a, int b );
float divide(float a, float b);
int multiply(int a, int b );
float multiply(float a, float b);
int subtract(int a, int b );
float subtract(float a, float b);

int main() {
    char calculator_operator;
    int a, b;
    float m, n;

//    cin>>a>>calculator_operator>>b;
//    if(a==0 && b==0){
//        return 0;
//    }
//    else{
//        switch (calculator_operator){
//            case '+':
//                cout<<add(a, b);
//                break;
//            case '-':
//                cout<<subtract(a,b);
//                break;
//            case '*':
//                cout<<multiply(a, b);
//                break;
//            case '/':
//                cout<<divide(a, b);
//                break;
//            default:
//                return 0;
//        }
//    }

    cin>>m>>calculator_operator>>n;

    if(m==0 && n==0){
        return 0;
    }
    else{
        switch (calculator_operator){
            case '+':
                cout<<add(m, n);
                break;
            case '-':
                cout<<subtract(m,n);
                break;
            case '*':
                cout<<multiply(m, n);
                break;
            case '/':
                cout<<divide(m, n);
                break;
            default:
                return 0;
        }
    }
    return 0;
}

int add(int a, int b) {
    int sum = a+b;
    return sum;
}

float add(float a, float b) {
    float sum = a+b;
    return sum;
}

int divide(int a, int b) {
    int sum = a/b;
    return sum;
}

float divide(float a, float b) {
    float sum = a/b;
    return sum;
}

int multiply(int a, int b) {
    int sum = a*b;
    return sum;
}

float multiply(float a, float b) {
    float sum = a*b;
    return sum;
}

int subtract(int a, int b) {
    int sum = a-b;
    return sum;
}

float subtract(float a, float b) {
    float sum = a-b;
    return sum;
}
