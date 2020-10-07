#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int N, L, R;

int map[51][51];
bool visit[51][51];

void input()
{
	cin >> N >> L >> R;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> map[y][x];
		}
	}
}
bool bfs(int y, int x)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> visit_lo;
	q.push(make_pair(y, x));
	visit_lo.push_back(make_pair(y, x));
	int sum = map[y][x];
	int cnt = 1;
	while (!q.empty())
	{
		int cx = q.front().second;
		int cy = q.front().first;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int tx = cx + dx[i];
			int ty = cy + dy[i];

			if (tx < 0 || tx >=N || ty < 0 || ty >=N)
				continue;

			int temp = map[cy][cx] - map[ty][tx];
			if (abs(temp) >= L && abs(temp) <= R && !visit[ty][tx])
			{
				visit[ty][tx] = true;
				sum += map[ty][tx];
				cnt++;
				visit_lo.push_back(make_pair(ty, tx));
				q.push(make_pair(ty, tx));
			}
		}
	}
	if (visit_lo.size() == 1)
		return false;
	else
	{
		for (int i = 0; i < visit_lo.size(); i++)
		{
			int x = visit_lo[i].second;
			int y = visit_lo[i].first;

			map[y][x] = sum / cnt;
		}
		return true;
	}
}

int main()
{
	input();
	int answer = 0;
	while (true) {
		memset(visit, false, sizeof(visit));
		bool flag = true;
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (!visit[y][x])
				{
					visit[y][x] = true;
					if (bfs(y, x)) {
						flag = false;
					}
				}
			}
		}
		
		if (flag)
			break;
		answer++;
	
		
	}
	cout << answer;
	return 0;
}