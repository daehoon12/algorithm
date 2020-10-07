#include <iostream>
#include <queue>
#include <cstring>
/* 함수 2개 만드는 것보다는 그냥 변수를 바꾸는 걸로*/
using namespace std;
char map[100][100];
int dist[100][100] = { 0, };
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n;
int cnt = 0;
void bfs1(int y, int x);
void bfs2(int y, int x);

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] == 0)
			{
				bfs1(i, j);
				cnt++;
			}
		}
	}

	memset(dist, 0, sizeof(dist));

	cout << cnt << " ";
	cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (dist[i][j] == 0)
			{
				bfs2(i, j);
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}

void bfs1(int y, int x)
{
	
	queue < pair<int, int>> q;
	dist[y][x] = 1;
	q.push(make_pair(y, x));

	while (!q.empty())
	{
		int tx = q.front().second;
		int ty = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int cx = dx[i] + tx;
			int cy = dy[i] + ty;


			if (cx < 0 || cx >= n || cy < 0 || cy >= n)
				continue;

			if (dist[cy][cx] == 0 && (map[cy][cx] == map[ty][tx]))
			{
				dist[cy][cx] = dist[ty][tx] + 1;
				q.push(make_pair(cy, cx));
			}
		}


	}
}
void bfs2(int y, int x)
{
	queue < pair<int, int>> q;
	dist[y][x] = 1;
	q.push(make_pair(y, x));

	while (!q.empty())
	{
		int tx = q.front().second;
		int ty = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int cx = dx[i] + tx;
			int cy = dy[i] + ty;


			if (cx < 0 || cx >= n || cy < 0 || cy >= n)
				continue;

			if (map[y][x] == 'R' || map[y][x] == 'G')
			{
				if (dist[cy][cx] == 0 && (map[cy][cx] == 'R' || map[cy][cx] == 'G'))
				{
					dist[cy][cx] = dist[ty][tx] + 1;
					q.push(make_pair(cy, cx));
				}
			}
			else if(map[y][x] == 'B')
			{
				if (dist[cy][cx] == 0 && map[cy][cx] == 'B')
				{
					dist[cy][cx] = dist[ty][tx] + 1;
					q.push(make_pair(cy, cx));
				}
			}
			}
		}
}
