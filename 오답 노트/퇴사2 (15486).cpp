#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[15000001];
pair<int, int> timetable[15000001];
void input()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> timetable[i].first >> timetable[i].second;
	}
}
int main()
{
	input();
	int answer = 0;
	for (int i = N; i >= 1; i--)
	{
		int next = i + timetable[i].first;
		if (next > N + 1)
			timetable[i].second = timetable[i + 1].second;
		else
			timetable[i].second = max(timetable[i].second + timetable[next].second, timetable[i + 1].second);
		answer = max(answer, timetable[i].second);
	}
	cout << answer;
	return 0;
}