#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int map[8][8];
int temp[8][8];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int m, n;
void tempInit(); // �Է��� �ʰ� �Ȱ��� ���� ������ִ� �Լ�.
int answer = 0;
void bfs();
void dfs(int cnt);
vector <pair<int, int>> virus;
int main()
{
	cin >> n >> m;

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 2) // ���� ���̷����� ���Ϳ� �ִ´�.
				virus.push_back(make_pair(y, x));
		}
	}

	tempInit(); //�ӽ� ��

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (temp[y][x] == 0) //���� 0�̸� 1�� �ٲٰ� dfs ����
			{
				temp[y][x] = 1;
				dfs(1);
				temp[y][x] = 0; // ������ �̿��� Ǯ��
				tempInit(); // ���� ������ temp�� �ٽ� �ʱ�ȭ �����ش�
			}
		}
	}
	cout << answer;
	return 0;
}
void tempInit()
{
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			temp[y][x] = map[y][x];
		}
	}
}

void dfs(int cnt)
{
	if (cnt == 3) // ���� 3�� ��������
	{
		bfs(); // ���̷����� ��Ʈ��.
		return;
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (!temp[y][x])
			{
				temp[y][x] = 1;
				dfs(cnt + 1);
				temp[y][x] = 0;
			}
		}
	}
}

void bfs()
{
	int bfsmap[8][8]; // temp�� �ǵ�� dfs�� ����� �۵����� �����Ƿ� bfsmap�� ����
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			bfsmap[y][x] = temp[y][x]; // ���� temp�� �� ���¸� bfsmap�� ����.
		}
	}

	queue <pair<int, int >> q;
	for (int i = 0; i < virus.size(); i++)
	{
		q.push(virus[i]); // ���̷��� ��ǥ�� ť�� �ִ´�.
	}

	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop(); 

		for (int i = 0; i < 4; i++)
		{
			int cx = dx[i] + x;
			int cy = dy[i] + y;

			if (cx < 0 || cx >= m || cy < 0 || cy >= n)
				continue;

			if (bfsmap[cy][cx] == 0) // ���̷����� ��Ʈ���� �ڵ�
			{
				bfsmap[cy][cx] = 2;
				q.push(make_pair(cy, cx));
			}
		}

	}
	int cnt = 0;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (bfsmap[y][x] == 0) // 0�� ������ ����
				cnt++;
		}
	}
	answer = max(cnt, answer); // answer�� ��
}