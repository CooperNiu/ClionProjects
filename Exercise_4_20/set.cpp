/* 2017��4��20��16:34:29
 * ����������set��Ԫ���Ѿ���С�����ź�����ص㣬���ı��е����е������ֵ������
 */
#include <iostream>
#include <set>
#include <sstream>

using namespace std;

set <string> dict; // string ����

/*
int main()
{
	string s, buf;
	while (cin >> s) {
		for (int i = 0; i < s.length(); ++i) {
			if (isalpha(s[i])) {
				s[i] = tolower(s[i]);
			}
			else {
				s[i] = ' ';
			}

			stringstream ss(s);
			while (ss >> buf) {
				dict.insert(buf);
			}
		}
		for(set<string> ::iterator it = dict.begin(); it != dict.end(); ++it){
			// iterator �ǵ�������������ָ��
			cout<<*it<<endl;
		}
	}
	return 0;
}*/
