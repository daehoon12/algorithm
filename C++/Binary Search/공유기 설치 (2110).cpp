#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;

vector<int> v;

long long answer = 0;
void input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
}
bool check(int mid)
{
	int cnt = 1;
	int prev = v[0];
	for (int i = 1; i < v.size(); i++)
	{
		if (v[i] - prev >= mid)
		{
			cnt++;
			prev = v[i];
		}
	}
	return cnt >= m;
}
int main()
{
	input();
	sort(v.begin(), v.end());
	long long low = *min_element(v.begin(), v.end());
	long long high = *max_element(v.begin(), v.end());
	while (true)
	{
		if (low > high)
			break;

		long long mid = (low + high) / 2;
		if (check(mid))
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
}