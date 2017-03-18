#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void hanoi(int n, char A, char B, char C);

int main() {
    int n;
    cout<<"Please input the sheet number:"<<endl;

    cin>>n;

    hanoi(n, 'A', 'B', 'C');

    return 0;
}

void hanoi(int n, char A, char B, char C) {
    if(n==1)
    {
        cout<<"Move sheet "<<n<<" from "<<A<<" to "<<C<<endl;
    }
    else
    {
        hanoi(n-1, A, B, C);
        cout<<"Move sheet "<<n<<"from "<<A<<"to "<<C<<endl;
        hanoi(n-1, B, A, C);
    }
}

