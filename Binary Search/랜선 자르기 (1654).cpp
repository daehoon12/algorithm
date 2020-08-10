#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
long long answer = 0;
int maxNum = 0;
vector<int> v;

int main()
{
	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
		maxNum = max(maxNum, k);
	}

	long long low = 1;
	long long high = maxNum;
	while (true) {
		int cnt = 0;
		if (low > high)
			break;

		long long mid = (low + high) / 2;
		for (int i = 0; i < v.size(); i++)
		{
			cnt += (v[i] / mid);

		}
		if (cnt >= m)
		{
			answer = max(answer, mid);
			low = mid + 1;
		}
		else
			high = mid -1;
	}
	cout << answer;		
	return 0;
}