#include <iostream>
#include <queue>

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
using namespace std;
char map[1001][1001];
int check[1001][1001];
queue <pair<int, int>> fire, jh;
int r, c;
int main()
{
	cin >> r >> c;
	for (int y = 0; y < r; y++)
	{
		for (int x = 0; x < c; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 'J')
				jh.push(make_pair(y, x));
			if (map[y][x] == 'F')
				fire.push(make_pair(y, x));
		}

	}

	while (!jh.empty())
	{
		// 먼저 불이 움직임.

		int fireIdx = fire.size();

		for (int i = 0; i < fireIdx; i++)
		{
			int tx = fire.front().second;
			int ty = fire.front().first;
			fire.pop();
			for (int i = 0; i < 4; i++)
			{
				int cx = tx + dx[i];
				int cy = ty + dy[i];
				if (cx < 0 || cx >= c || cy < 0 || cy >= r || map[cy][cx] == '#')
					continue;
				if (map[cy][cx] == '.') // 왜 이 조건문을 안 넣으면 메모리 초과가 걸리는 것인가?
				{
					map[cy][cx] = 'F';
					fire.push(make_pair(cy, cx));
				}
			}
		}

		int jhIdx = jh.size();

		for (int i = 0; i < jhIdx; i++)
		{
			int tx = jh.front().second;
			int ty = jh.front().first;
			jh.pop();
			if (tx == 0 || tx == c - 1 || ty == 0 || ty == r - 1)
			{
				cout << check[ty][tx] + 1;
				return 0;
			}
			for (int i = 0; i < 4; i++)
			{
				int cx = tx + dx[i];
				int cy = ty + dy[i];
				if (cx < 0 || cx >= c || cy < 0 || cy >= r || map[cy][cx] == '#')
					continue;

				if (map[cy][cx] != 'F' && check[cy][cx] == false)
				{
					check[cy][cx] = true;
					check[cy][cx] = check[ty][tx] + 1;
					jh.push(make_pair(cy, cx));
				}
			}
		}
	}
	cout << "IMPOSSIBLE";
	return 0;
}