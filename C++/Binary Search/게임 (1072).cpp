#include <iostream>
#include <algorithm>
using namespace std;
long long answer = 0;
long long x, y;

int main()
{
	cin >> x >> y;
	long long z = (y * 100) / x;
	if (z >= 99)
	{
		cout << -1;
		return 0;
	}
	int low = 0;
	int high = 1000000000;
	while (true)
	{
		if (low > high)
			break;
		long long mid = (low + high) / 2;

		long long temp = ((mid+ y) *100) / (x+mid);

		if (z >=temp)
		{
			answer = max(mid+1, answer);
			low = mid + 1;
		}
		else
			high = mid - 1;
	
	}

	cout << answer;
	return 0;
}