#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> answer;
vector <int> v;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1,0 ,-1 };

int n, m, k;
int divd = 0;
int map[101][101];
bool visit[101][101];
int cnt = 0;

void dfs(int y, int x);
int main()
{
	cin >> n >> m >> k;


	for (int t = 0; t < k; t++)
	{
		int sx, sy, ex, ey;
		cin >> sx >> sy >> ex >> ey;
		
		for (int i = sy; i < ey; i++)
		{
			for (int j = sx; j < ex; j++)
			{
				map[i][j] = 1;
			}
		}
	}
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (map[y][x] == 0 && !visit[y][x])
			{
				cnt++;
				divd++;
				dfs(y, x);
				answer.push_back(cnt);
				cnt = 0;
			}
		}
	}

	cout << divd << '\n';
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << " ";
	}
	return 0;
}

void dfs(int y, int x)
{
	visit[y][x] = true;

	for (int i = 0; i < 4; i++)
	{
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx < 0 || cx >= m || cy < 0 || cy >= n)
			continue;


		if (map[cy][cx] == 0 && visit[cy][cx] == false)
		{
			cnt++;
			dfs(cy, cx);
		}
	}
}