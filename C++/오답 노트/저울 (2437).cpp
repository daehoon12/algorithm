#include <iostream>
#include <algorithm>
using namespace std;
int n,answer;
int weight[1001];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}

	sort(weight, weight + n);
	for (int i = 0; i < n; i++)
	{
		if (weight[i] > answer + 1) // 이 부분이 여기서 가장 어려웠음.
			break;
		answer += weight[i];
	}
	cout << answer + 1;
	return 0;
}
