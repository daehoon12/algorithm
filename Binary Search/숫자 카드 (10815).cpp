#include <iostream>
#include <algorithm>
#include <cstdio>
#pragma warning (disable:4996)
using namespace std;
int arr1[100001];
int arr2[100001];
int n, m;

int binary_search(int target);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d" , &arr1[i]);
	}

	scanf("%d", &m);
	sort(arr1, arr1 + n);
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &arr2[i]);
	}
	for (int i = 0; i < m; i++)
	{
		printf("%d \n", binary_search(arr2[i]));
	}
	return 0;
}

int binary_search(int target)
{
	int low = 0;
	int high = n - 1;

	while (high >= low)
	{
		int middle = (low + high) / 2;

		if (target == arr1[middle])
			return 1;

		else if (target > arr1[middle])
		{
			low = middle + 1;
		}
		else if (target < arr1[middle])
			high = middle - 1;
	}
	return 0;

}