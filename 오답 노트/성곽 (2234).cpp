#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int answer1, answer2, answer3;

int dx[] = { -1,0,1,0 };
int dy[] = { 0,-1,0,1 };
int map[51][51];
bool visit[51][51];

void input()
{
	cin >> m >> n;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
			cin >> map[y][x];
	}
}
void print_map()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
			cout << visit[y][x] << " ";
		cout << '\n';
	}
	cout << '\n';
}

int bfs(int y, int x)
{
	int ret = 1;
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		
		int idx = 1;
		for (int i = 0; i < 4; i++)
		{
			if (!(map[y][x] & idx))
			{
				int cx = dx[i] + x;
				int cy = dy[i] + y;

				if (cx < 0 || cx >= m || cy < 0 || cy >= n)
					continue;
				if (!visit[cy][cx])
				{
					ret++;
					visit[cy][cx] =true;
					q.push(make_pair(cy, cx));
				}
			}
			idx <<= 1;
		}
	}
	return ret;
}

void find_answer1_2()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (!visit[y][x])
			{
				visit[y][x] = true;
				answer1++;
				answer2 = max(answer2, bfs(y, x));
			}
		}
	}
}

void find_answer3()
{
	int k = 0;
	for (k = 1; k <= 8; k *= 2)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{

				if ((map[y][x] & k))
				{
					memset(visit, false, sizeof(visit));
					visit[y][x] = true;
					map[y][x] -= k;
					answer3 = max(answer3, bfs(y, x));
					map[y][x] += k;
				}
			}
		}
	}
}

int main()
{
	input();
	find_answer1_2();
	cout << answer1 << '\n' << answer2 << '\n';
	find_answer3();
	cout << answer3;
	return 0;
}
