#include <iostream>

using namespace std;

int sum1_100();

float GPA(float grade);

int main() {
    float grade;

    //cout<<sum1_100();
    for(;;){
        cout<<"Input the grade:(input -1 to exit)"<<endl;
        cin>>grade;

        if(grade == -1){
            break;
        }
        cout<<"GPA = "<<GPA(grade)<<endl;
    }
    return 0;
}

int sum1_100() {
    int sum=0;

    for (int i = 0; i < 101; ++i) {
        sum+=i;
    }

    return sum;
}

float GPA(float grade ) {
    if(grade>100){
        return -1;
    }
    else if(grade>=90 && grade<=100){
        return 4.0;
    }
    else if(grade>=85 && grade<90){
        return 3.7;
    }
    else if(grade>=82 && grade<85){
        return 3.3;
    }
    else if(grade>=78 && grade<82){
        return 3.0;
    }
    else if(grade>=75 && grade<78){
        return 2.7;
    }
    else if(grade>=71 && grade<75){
        return 2.3;
    }
    else if(grade>=66 && grade<71){
        return 2.0;
    }
    else if(grade>=62 && grade<65){
        return 1.7;
    }
    else if(grade>60 && grade<62){
        return 1.3;
    }
    else if(grade>=0){
        return 0;
    }
    else if(grade<0){
        return -2;
    }
    else {
        return 1.0;
    }
}
