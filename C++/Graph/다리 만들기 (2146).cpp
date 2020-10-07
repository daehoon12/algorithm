#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
int map[100][100];
bool visit[100][100];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n;
int answer = 987654321;

using namespace std;

void dfs(int y, int x, int number);
int bfs(int number);

int main()
{
	cin >> n;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> map[y][x]; // ��ǲ
		}
	}

	int cnt = 2;

	for (int y = 0; y < n; y++) // ���� ��ȣ�� ����.
	{
		for (int x = 0; x < n; x++)
		{
			if (map[y][x] == 1 && !visit[y][x])
			{
				dfs(y, x, cnt);
				cnt++;
			}
		}
	}

	for (int i = 2; i < cnt; i++)
	{
		memset(visit, false, sizeof(visit));
		answer = min(answer, bfs(i));
	}
	cout << answer;
	return 0;
}

void dfs(int y, int x, int cnt)
{
	map[y][x] = cnt;
	
	for (int i = 0; i < 4; i++)
	{
		int cy = dy[i] + y;
		int cx = dx[i] + x;

		if (cx < 0 || cx >= n || cy < 0 || cy >= n)
			continue;

		if (map[cy][cx] == 1)
			dfs(cy, cx, cnt);
	}
}

int bfs(int number)
{
	queue<pair<int, int>>q;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			if (number == map[y][x])
			{
				visit[y][x] = true;
				q.push(make_pair(y, x)); 
			}
		}
	}
	int result = 0;

	while (!q.empty())
	{
		int s = q.size(); // �̰� �����ָ� result �� 1�� �۰Գ���.
		for (int i = 0; i < s; i++)
		{
			int y = q.front().first;
			int x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int cy = y + dy[i];
				int cx = x + dx[i];

				if (cx < 0 || cx >= n || cy < 0 || cy >= n)
					continue;

				if (!map[cy][cx] && !visit[cy][cx]) // �ٴٿ� �ְ� �湮���� ����
				{
					visit[cy][cx] = true;
					q.push(make_pair(cy, cx));
				}

				else if (map[cy][cx] && map[cy][cx] != number) // �ٸ� ����
				{	
					return result;
				}
			}
		}
		result++; // for���� �������� �� ���� �÷���
	}
}