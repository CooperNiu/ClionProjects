/* 2017年4月20日16:34:29
 * 程序利用了set中元素已经从小到大排好序的特点，将文本中的所有单词以字典序输出
 */
#include <iostream>
#include <set>
#include <sstream>

using namespace std;

set <string> dict; // string 集合

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
			// iterator 是迭代器，类似于指针
			cout<<*it<<endl;
		}
	}
	return 0;
}*/
