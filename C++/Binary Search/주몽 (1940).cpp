#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> v;
int main()
{
	cin >> n >> m;
	int low = 0;
	int high = n - 1;
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}

	sort(v.begin(), v.end());
	while (true)
	{
		if (low >= high)
			break;

		if (v[low] + v[high] == m)
		{
			answer++;
			low++;
			high--;
		}

		else if (v[low] + v[high] > m)
			high--;
		else
			low++;
	}
	cout << answer;
	return 0;
}