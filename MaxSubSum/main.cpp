#include <iostream>


int MaxSubSum(int *a, int left, int right );
int MaxSum(int n ,int *a);

int main()
{
	// initialize an array with given number
	int a[100] = {1, -2, 0, -2, 34, 20, -5, 2, -42, 22};
	
	std::cout << MaxSum(10, a);
	
	return 0;
}

int MaxSubSum(int *a, int left, int right)
{
	int sum = 0;
	
	if(left == right )
	{
		sum = a[left]>0 ? a[left] : 0;
	}
	else
	{
		int center = (left + right)/2;
		int leftsum = MaxSubSum(a, left, center);
		int rightsum = MaxSubSum(a, center+1, right);
		int s1 = 0;
		int lefts = 0;
		
		for (int i = center; i >= left; i--)
		{
			// add a[i] from center to left
			left += a[i];
			if(lefts > s1)
			{
				s1 = lefts;
			}
		}
		
		int s2 = 0;
		int right = 0;
		
		for(int i = center +1; i<=right; i++)
		{
			right += a[i];
			if(right > s2)
			{
				s2 = right;
			}
		}
		
		sum = s1 + s2;
		if(sum < leftsum)
		{
			sum = leftsum;
		}
		if(sum < rightsum)
		{
			sum = rightsum;
		}
	}
	return sum;
}

int MaxSum(int n, int *a)
{
	return MaxSubSum(a, 1, n);
}