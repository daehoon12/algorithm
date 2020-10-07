#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool visit[101];
int check[101];
vector<int> lv[101], rv[101];
int answer = 0;
int temp = 0;
int cnt = 0;
int m, n;
void input()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int start_num, end_num;
		cin >> start_num >> end_num;
		lv[start_num].push_back(end_num);
		rv[end_num].push_back(start_num);
	}
}

void dfs(int number, vector<int> v[101])
{
	
	for (int i = 0; i < v[number].size(); i++)
	{
		int next = v[number][i];
		if (!visit[next])
		{
			visit[next] = true;
			cnt++;
			dfs(next, v);
		}
	}
}
int main()
{
	input();
	for (int i = 1; i <= n; i++) // 자기보다 가벼운 구슬 찾기
	{
		dfs(i,lv);
		if (cnt >= (n + 1) / 2)
			answer++;
		cnt = 0;
		dfs(i, rv);
		if (cnt >= (n + 1) / 2)
			answer++;
		cnt = 0;
		memset(visit, false, sizeof(visit));
	}

	cout << answer;
	return 0;
}