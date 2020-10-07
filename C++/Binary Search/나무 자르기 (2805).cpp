#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> v;

int maxNum = 0;
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		maxNum = max(maxNum, k);
		v.push_back(k);
	}
	long long answer = 0;
	long long low = 0;
	long long high = maxNum;
	while (true)
	{
		if (low > high)
			break;
		long long target = 0;
		long long mid = (low + high) / 2;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] - mid > 0)
			{
				target += (v[i] - mid);
			}
		}

		if (target >= m)
		{
			answer = max(answer, mid);
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}

	cout << answer;
	return 0;
}