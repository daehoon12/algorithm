#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector <int> v;
bool check(int mid);
int m, n;
int main()
{
	int answer = 987654321;
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		v.push_back(k);
		sum += k;
	}
	int low = 0;
	int high = sum;
	while (true)
	{
		if (low > high)
			break;
		int mid = (low + high) / 2;
		if (check(mid))
		{
			answer = min(answer, mid);
			high = mid - 1;
		}
		else
			low = mid + 1;
	}
	cout << answer;
	return 0;
}

bool check(int mid)
{
	int cnt = 0;
	for (int i = 0; i < v.size(); i++)
	{
		cnt += v[i] / mid;
		if (v[i] % mid != 0)
			cnt++;
	}
	return n >= cnt;
}