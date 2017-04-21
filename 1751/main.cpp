#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
// 2485 最小生成树
const int maxint = 6000;
const int inf = -65535;
int country[maxint][maxint];

void prim(int n, int **c)
{
	int lowcost[maxint];
	int closest[maxint];
	bool s[maxint];
	s[1] = true;
	for (int i = 2; i <= n; ++i) {
		lowcost[i] = c[1][i];
		closest[i] = 1;
		s[i] = false;
	}

	for (int i = 1; i < n; ++i) {
		int min = inf;
		int j = 1;
		for (int k = 2; k <= n; ++k) {
			if ((lowcost[k] < min) && (!s[k])) {
				min = lowcost[k];
				j = k;
			}
		}
		cout << j<<' '<<closest[j]<<endl;
		s[j]=true;

		for (int k = 2; k <= n; ++k) {
			if((c[j][k]<lowcost[k])&&(!s[k])){
				lowcost[k]=c[j][k];
				closest[k]=j;
			}
		}
	}
}
int main()
{
	int T;
	scanf("%d", &T);

	while(T--){
		int N;
		scanf("%d", &N);
		memset(country, maxint, sizeof(country));
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				scanf("%d", &country[i][j]);
				// read all the county distance
			}
		}
//			getchar();// read the blank line
		prim(N, (int **)country);
		/// 二维数组传参这个知识点很重要！！！
	}
	return 0;
}