#include <iostream>
#include <algorithm>
using namespace std;
int n;
int weight[1001];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> weight[i];
	}

	sort(weight, weight + n);
	int answer = 0;
	
	for (int i = 0; i < n; i++)
	{
		if (weight[i] > answer + 1) // �� �κ��� ���⼭ ���� �������.
			break;
		answer += weight[i];
	}
	cout << answer + 1;
	return 0;
}