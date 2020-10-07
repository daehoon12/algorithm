#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
// bfs로 값이 있는 값을 큐에 넣고 하나씩 빼면서 근처에 있는 0의 개수를 샘
// bfs가 끝난 뒤 근처의 0의 개수만큼 값을 빼줌

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
				cnt++; // 0의 개수
			if (map[cy][cx] != 0 && !visit[cy][cx])
			{
				visit[cy][cx] = true; // 방문 표시를 체크할때 해야 중복된 값들이 들어가지 않는다.
				q.push(make_pair(cy, cx));
			}
		}
		location.push_back(make_pair(make_pair(ty, tx), cnt)); // 주위에 0의 개수와 좌표를 저장
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

		map[y][x] -= location[i].second; // 맵에다가 0의 개수만큼 빼줌
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
				if (map[y][x] && !visit[y][x]) // 맵이 바다가 아니고 방문하지 않은 곳이면 bfs 탐색
				{
					bfs(y, x);
					melting();
					cnt++; // bfs가 돌아가는 횟수
				}
			}
		}

		if (cnt == 0) // cnt가 0 -> 모든 map의 값이 0이라 bfs를 한번도 실행하지 않음.
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