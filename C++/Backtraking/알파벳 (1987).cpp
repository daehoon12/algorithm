#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
bool visit[26];
char map[21][21];
int r, c;
int maxNum = 0;
int answer = 0;
int cnt = 0;

void dfs(int y, int x, char ch, int cnt) {
	visit[ch - 'A'] = true;

	
	for (int i = 0; i < 4; i++)
	{
		int cx = x + dx[i];
		int cy = y + dy[i];

		if (cx < 0 || cx >= c || cy < 0 || cy >= r || visit[map[cy][cx] - 'A'] == true)
			continue;

		visit[map[cy][cx] - 'A'] = true;
		dfs(cy, cx, map[cy][cx], cnt+1);
		visit[map[cy][cx] - 'A'] = false;
	}
	answer = max(answer, cnt+1);
	visit[ch - 'A'] = false;
}
int main()
{
	cin >> r >> c;

	for (int y = 0; y < r; y++)
	{
		for (int x = 0; x < c; x++)
		{
			cin >> map[y][x];
		}
	}

	memset(visit, false, sizeof(visit));
	dfs(0, 0, map[0][0], 0);
	
	cout << answer;
	return 0;
}