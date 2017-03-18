#include <iostream>
#include <cstdlib>

using namespace std;

int visit(int , int );

int maze[7][7] = {
        {2, 2, 2, 2, 2, 2, 2},
        {2, 0, 0, 0, 0, 0, 2},
        {2, 0, 2, 0, 2, 0, 2},
        {2, 0, 0, 2, 0, 2, 2},
        {2, 2, 0, 2, 0, 2, 2},
        {2, 0, 0, 0, 0, 0, 2},
        {2, 2, 2, 2, 2, 2, 2},
};

int startI = 1, startJ = 1; // entrence
int endI = 5, endJ = 5; // exit
int success = 0;

int main() {
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 7; ++j) {
            if (maze[i][j] == 2)
                cout<<"#";
            else
                cout<<" ";
        }

        cout<<endl;
    }

    if(visit(startI, startJ) == 0)
        cout<<"\nCannot find exit! \n";
    else
        cout<<"\nShow the trace:\n";
    for (int k = 0; k < 7; ++k) {
        for (int i = 0; i < 7; ++i) {
            if (maze[k][i] == 2)
                cout<<"#";
            else if(maze[k][i] == 1)
                cout<<"*";
            else
                cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}

int visit(int i, int j)
{
    maze[i][j]=1;

    if(i == endI && j == endJ){
        success = 1;
    }

    if(success != 1 && maze[i][j+1] == 0){
        visit(i, j+1);
    }
    if(success != 1 && maze[i+1][j] == 0){
        visit(i+1, j);
    }
    if(success != 1 && maze[i][j-1] == 0){
        visit(i, j-1);
    }
    if(success != 1 && maze[i-1][j] == 0){
        visit(i-1, j);
    }

    if(success != 1)
        maze[i][j] = 0;

    return success;
}