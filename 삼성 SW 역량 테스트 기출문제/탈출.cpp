#include <iostream>
#include <queue>
#include <algorithm>
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };
char map[51][51];
int dist[51][51] = { 0, };
using namespace std;
int answer = 0;
int r, c;

queue <pair<int, int>> water,mole;
int main()
{
	cin >> r >> c;

	for (int y = 0; y < r; y++)
	{
		for (int x = 0; x < c; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == '*')
				water.push(make_pair(y, x));
			if (map[y][x] == 'S')
				mole.push(make_pair(y, x));
		}
	}
	while (!mole.empty())
	{
		int waterIdx = water.size();
		for (int i = 0; i < waterIdx; i++) {
			int tx = water.front().second;
			int ty = water.front().first;
			dist[ty][tx] = -1;

			water.pop();

			for (int i = 0; i < 4; i++)
			{
				int cx = tx + dx[i];
				int cy = ty + dy[i];

				if (cx < 0 || cx >= c || cy < 0 || cy >= r)
					continue;
				if (map[cy][cx] == '.')
				{
					map[cy][cx] = '*';
					water.push(make_pair(cy, cx));
				}

			}

		}
		// 소닉이 움직일 차례
		int moldIdx = mole.size();
		for (int i = 0; i < moldIdx; i++)
		{
			int tx = mole.front().second;
			int ty = mole.front().first;
			mole.pop();

			for (int i = 0; i < 4; i++)
			{
				int cx = tx + dx[i];
				int cy = ty + dy[i];

				if (cx < 0 || cx >= c || cy < 0 || cy >= r)
					continue;

				if (map[cy][cx] == '.' && dist[cy][cx] == 0)
				{
					dist[cy][cx] = dist[ty][tx] + 1;
					mole.push(make_pair(cy, cx));
				}
				else if (map[cy][cx] == 'D')
				{
					cout << dist[ty][tx] + 1;
					return 0;
				}
			}
		}
	}
	cout << "KAKTUS";
	return 0;
}
