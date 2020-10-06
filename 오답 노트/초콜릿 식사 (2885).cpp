#include <iostream>

using namespace std;
int K;

int main()
{
	int num=1;
	cin >> K;
	while (num < K)
	{
		num <<= 1; // 이게 키포인트
	}
	int answer1 = num;
	int sum = 0;
	int cnt = 0;

	while (K > 0)
	{
		if (K >= num)
			K -= num;
		else 
		{
			num /= 2;
			cnt++;
		}
	}
	cout << answer1 << " " << cnt;
	return 0;
}
