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
     * ��ֻ�ܽ��յ����Ĵ�(�������������ľ���)����Ϊ���ַ������κοհ׷�Ϊ�ָ����������ո�spaces����Ծ��tabulators�����з�newlines�ͻس���arriage returns��
     * �����ܸ�bufferָ����������ʹ�ó����ȶ�������û����볬�����鳤�ȣ�������Ϣ�ᱻ��ʧ��
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