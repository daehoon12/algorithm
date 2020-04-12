#include <iostream>
#include <algorithm>

using namespace std;
int dx[] = { 1,-1, 0,0 };
int dy[] = { 0,0,1,-1 };
int dfs(int y, int x, int cnt);
int finger(int y, int x);
int n, m;
int map[500][500];
bool visit[500][500];

int answer = 0;
int main()
{

	cin >> n >> m;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
			cin >> map[y][x];
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++) // 브루트 포스
		{
			visit[y][x] = true;
			answer = max(answer, dfs(y, x, 1));
			answer = max(answer, finger(y, x));
			visit[y][x] = false;
		}
	}

	cout << answer;

	return 0;
}

int dfs(int y, int x, int cnt)
{
	if (cnt == 4)
		return map[y][x];
	int sum = 0;
	for (int i = 0; i < 4; i++) // 이 과정에서 'ㅗ' 블록을 제외한 나머지를 구현할 수 있다.
	{
		int cy = dy[i] + y;
		int cx = dx[i] + x;

		if (cy < 0 || cy >= n || cx < 0 || cx >= m)
			continue;

		if (!visit[cy][cx])
		{
			visit[cy][cx] = true;
			sum = max(sum, (map[y][x] + dfs(cy, cx, cnt + 1)));
			visit[cy][cx] = false;
		}
	}
	return sum;
}

int finger(int y, int x) // dfs로 구현이 되지 않는 모양
{
	int sum = 0;
	if (y >= 1 && x >= 1 && x < m - 1) // ㅗ
		sum = max(sum, map[y][x] + map[y][x - 1] + map[y][x + 1] + map[y - 1][x]);
	if (y >= 1 && y < n-1 && x < m - 1) // ㅏ
		sum = max(sum, map[y][x] + map[y+1][x] + map[y-1][x] + map[y][x+1]);
	if (y <n-1 && y>=0 && x>=1 && x< m - 1) // ㅜ
		sum = max(sum, map[y][x-1] + map[y][x + 1] + map[y][x] + map[y+ 1][x]);
	if (y >=1 && y< n-1 && x >= 1) // ㅓ
		sum = max(sum, map[y][x] + map[y+1][x] + map[y-1][x] + map[y][x-1]);

	return sum;
}