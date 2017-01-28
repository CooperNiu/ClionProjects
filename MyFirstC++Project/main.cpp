#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <cstdio>

using namespace std;

int main() {
    /*
     * Test the function of several escape words
     */
    cout << "Hello, World!" << endl;
    cout << "Hello, World!\r";
    cout << "\tHi, Cooper!";
    cout << "\vHow are you?";
    cout << "\fI'm fine!"<<endl;

    /*
     * Init the string array with strcpy
     */
    char Myname[10];
    strcpy(Myname, "CooperNiu");
    cout<<Myname;

    for (int i = 0; i < 10; ++i) {
        cin>>Myname[i];
    }
    cout<<Myname<<endl;

    /* cin has these disadvantages
     * 它只能接收单独的词(而不能是完整的句子)，因为这种方法以任何空白符为分隔符，包括空格spaces，跳跃符tabulators，换行符newlines和回车符arriage returns。
     * 它不能给buffer指定容量，这使得程序不稳定，如果用户输入超出数组长度，输入信息会被丢失。
     * cin.getline
     */
    char mybuffer [100];
    float price;
    int quantity;
    cout << "Enter price: ";
    cin.getline (mybuffer,100);
    price = atof (mybuffer);
    cout << "Enter quantity: ";
    cin.getline (mybuffer,100);
    quantity = atoi (mybuffer);
    cout << "Total price: " << price*quantity<<endl;

    /*
     * Try to use string multiply functions
     */
    char str[80];
    strcpy (str,"these ");
    strcat (str,"strings ");
    strcat (str,"are ");
    strcat (str,"concatenated.");
    puts (str);

    return 0;
}