#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
// bfs�� ���� �ִ� ���� ť�� �ְ� �ϳ��� ���鼭 ��ó�� �ִ� 0�� ������ ��
// bfs�� ���� �� ��ó�� 0�� ������ŭ ���� ����

using namespace std;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };
int map[301][301];
bool visit[301][301];

int n, m;
vector <pair<pair<int, int>, int>> location;
void bfs(int y, int x)
{
	queue <pair<int, int>>q;
	q.push(make_pair(y, x));

	visit[y][x] = true;
	while (!q.empty())
	{
		int cnt = 0;
		int tx = q.front().second;
		int ty = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cy = ty + dy[i];
			int cx = tx + dx[i];
			if (cy < 0 || cy >= n || cx < 0 || cx >= m)
				continue;
			if (map[cy][cx] == 0)
				cnt++; // 0�� ����
			if (map[cy][cx] != 0 && !visit[cy][cx])
			{
				visit[cy][cx] = true; // �湮 ǥ�ø� üũ�Ҷ� �ؾ� �ߺ��� ������ ���� �ʴ´�.
				q.push(make_pair(cy, cx));
			}
		}
		location.push_back(make_pair(make_pair(ty, tx), cnt)); // ������ 0�� ������ ��ǥ�� ����
	}
}

void input()
{
	cin >> n >> m;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> map[y][x];
		}
	}
}
void melting()
{
	for (int i = 0; i < location.size(); i++)
	{
		int y = location[i].first.first;
		int x = location[i].first.second;

		map[y][x] -= location[i].second; // �ʿ��ٰ� 0�� ������ŭ ����
		if (map[y][x] < 0) // 
			map[y][x] = 0; 
	}
	location.clear();
}
int main()
{
	input();
	int answer = 0;
	while (true) 
	{
		int cnt = 0;
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (map[y][x] && !visit[y][x]) // ���� �ٴٰ� �ƴϰ� �湮���� ���� ���̸� bfs Ž��
				{
					bfs(y, x);
					melting();
					cnt++; // bfs�� ���ư��� Ƚ��
				}
			}
		}

		if (cnt == 0) // cnt�� 0 -> ��� map�� ���� 0�̶� bfs�� �ѹ��� �������� ����.
		{
			cout << 0;
			return 0;
		}
		if (cnt >= 2)
		{
			cout << answer;
			break;
		}
		answer++;
		memset(visit, false, sizeof(visit));
		
	}
	return 0;
}