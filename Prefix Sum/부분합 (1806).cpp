#include <iostream>

using namespace std;
int sum[100001];
int arr[100001];

int N, M;
int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
		if (i == 1)
			sum[i] = arr[i];
		else
			sum[i] = sum[i - 1] + arr[i];
	}
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int num1, num2;
		cin >> num1 >> num2;
		cout << sum[num2] - sum[num1-1] << '\n';
	}
	return 0;
}