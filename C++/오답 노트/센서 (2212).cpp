#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v, dist;

int N, K;
void input()
{
	cin >> N;
	cin >> K;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
}

int main()
{
	int answer = 0;
	input();
	sort(v.begin(), v.end());
	for (int i = 1; i < v.size(); i++)
	{
		dist.push_back(v[i] - v[i - 1]);
	}
	sort(dist.begin(), dist.end());

	for (int i = 0; i < N-K; i++)
	{
		answer += dist[i];
	}

	cout << answer;
	return 0;
}
