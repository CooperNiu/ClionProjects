/* 2017��4��17��14:17:33
 * ��ϰһ������д�ĳ���
 * �������ͼ������̬������ʹ�á����ٶ�ά���顢ȥ���ַ�����β�Ŀո�erase������ʹ��
 */
#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
using namespace std;

//����������������ͼ��
/*int main()
{
	int i, j, k;
	for (i = 0; i <= 3; i++) {
		for (j = 0; j <= 2 - i; j++)
			printf(" ");
		for (k = 0; k <= 2 * i; k++)
			printf("*");
		printf("\n");
	}
	for (i = 0; i <= 2; i++) {
		for (j = 0; j <= i; j++)
			printf(" ");
		for (k = 0; k <= 4 - 2 * i; k++)
			printf("*");
		printf("\n");
	}
}*/

//��������Ƕ�̬������ʹ�á����ٶ�ά�����
/*
//��̬�����ά����
#include <iostream>
using namespace std;
int main()
{
	int **a;  //ָ��ָ���ָ��
	int n,m;//n�� m��
	int i,j;
	cin>>n>>m; //��������������
	int sum=0;

	//����ռ�
	a= new int * [n];  //n�� int ָ�� ����
	for(i=0;i<n;i++)    //n����СΪm��һά����
	{
		a[i]=new int[m]; //1����СΪm��һά���飬a[i]��intָ��
	}

	//��������
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			//cin>>a[i][j];//����
			cin>> *(*(a+i)+j);//ͬ��a�൱����ָ��

		}
	}

	//�������
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			//cout<<a[i][j]<<"\t";//���
//			cout<< *(*(a+i)+j)<<"\t";
			sum += *(*(a+i)+j);
		}
//		cout<<endl;
	}

	cout<<sum;
	//�ͷ�����Ŀռ䣡����
	for(i=0;i<n;i++) //�ͷ�n����СΪm��һά����
	{
		delete []a[i];
	}
	delete []a;//�ͷ�intָ������
	return 0;
}
*/

//�������������ȥ���ַ�����β�Ŀո�
/*
string& trim(string &);

string string1;

int main()
{
	string s ;
	cin>>s;
	cout << trim(s) ;

	return 0;
}

string& trim(string &s)
{
	if (s.empty())
	{
		return s;
	}
	s.erase(0,s.find_first_not_of(" "));
	s.erase(s.find_last_not_of(" ") + 1);
	string1=s+"#";
	return string1;
}*/
// �Լ�д��ȥ�ո�ĳ��򣬻�û����ȫ����mooc�ϵ�Ҫ�󣬵��ǿ�������ȥ�ַ���ǰ��Ŀո�
/*int main()
{
	bool flag = true; // �Ƿ��ǵ�һ�������ǿո�
	string str;
	unsigned int spacenum = 0; // �ո���Ŀ
	unsigned int temp = 0;

	cin >> str;
	for (int i = 0; i < str.length(); ++i) {
		if (isspace(str[i]) && flag) {
		// isspace���������жϸ��ַ��Ƿ�Ϊ�ո�
			str.erase(i); // ����ȥ�ո���
			// ȥ�ո�����������ʽ
			// erase���ַ�������
			// erase����ʼλ�ã���ֹλ�ã�
			// erase����ʼλ�ã��ַ�������
		}
		else {
			i++;
			continue;
		}
		flag=false;
		if (isspace(str[i]) && isspace(str[i + 1])) {
			str.erase(str.begin() + i, str.end() - 1);
			break;
		}
	}

	cout << str;
	return 0;
}*/

// ���1-12���������ֶ�Ӧ��Ӣ�ĵ���
/*int main()
{
	char *str[13] = {" ","one", "two", "three","four","five","six","seven","eight","nine","ten",
	                  "eleven","twelve"};

	int i;
	cin>>i;
	cout<<str[i];
	return 0;
}*/

//����ָ����������е�Ԫ��
/*
��Ŀ���ݣ�
��д���򣬰Ѵ�1��n��n����������ĳ��int�����飬Ȼ����int��ָ�����������Ԫ�ص�ֵ��,

�����ʽ:
�������n

�����ʽ��
�����1��n n������Ԫ��,ע�����һ��Ԫ��֮��û�пո�

����������
9

���������
1 2 3 4 5 6 7 8 9
ʱ�����ƣ�500ms�ڴ����ƣ�32000kb

int main()
{
	int n;
	int a[1000];
	cin>>n;
	for (int i = 0; i < n; ++i) {
		a[i]=i+1;
	}
	int *pInt=a;
	for (int i = 0; i < n; ++i) {
		cout<<*(pInt++);
		if (i<n-1){
			cout<<' ';
		}
	}
	return 0;
}
  */