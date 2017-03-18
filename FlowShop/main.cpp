#include <iostream>
#include <algorithm>
#include "Jobtype.h"

using namespace std;

int const N = 5;

int FlowShop(int n, int a[], int b[], int c[]);
void BubbleSort(Jobtype *d,int n);


int main()
{
	int a[] = {2,4,3,6,1};
	int b[] = {5,2,3,1,7};
	int c[N];
	
	int minTime =  FlowShop(N,a,b,c);
	
	cout<<"作业在机器1上的运行时间为："<<endl;
	for(int i=0; i<N; i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	cout<<"作业在机器2上的运行时间为："<<endl;
	for(int i=0; i<N; i++)
	{
		cout<<b[i]<<" ";
	}
	cout<<endl;
	
	cout<<"完成作业的最短时间为："<<minTime<<endl;
	cout<<"编号从0开始，作业调度的顺序为："<<endl;
	for(int i=0; i<N; i++)
	{
		cout<<c[i]<<" ";
	}
	cout<<endl;
	
	system("pause");
	return 0;
}

int FlowShop(int n, int a[], int b[], int c[])
{
	Jobtype *d = new Jobtype[n];
	
	for (int i = 0; i < n; ++i)
	{
		d[i].key = a[i]>b[i]?b[i]:a[i];
		d[i].job = a[i]<=b[i];
		d[i].index = i;
	}
	
	BubbleSort(d, n);
	
	int j = 0, k = n-1;
	
	for (int i = 0; i < n; ++i)
	{
		if(d[i].job)
		{
			c[j++] = d[i].index;
		}
		else
		{
			c[k--] = d[i].index;
		}
	}
	
	j = a[c[0]];
	k = j+b[c[0]];
	
	for (int i = 1; i < n; ++i)
	{
		j += a[c[i]];
		k = j<k?k+b[c[j]]:b[c[i]];
	}
	
	delete d;
	
	return k;
}
void BubbleSort(Jobtype *d, int n)
{
	int i,j,flag;
	Jobtype temp;
	
	for(i=0;i<n;i++){
		flag = 0;
		for(j=n-1;j>i;j--){
			//如果前一个数大于后一个数，则交换
			if(d[j]<=d[j-1]){
				temp = d[j];
				d[j] = d[j-1];
				d[j-1] = temp;
				flag = 1;
			}
		}
		//如果本次排序没有进行一次交换，则break，减少了执行之间。
		if(flag == 0){
			break;
		}
	}
}