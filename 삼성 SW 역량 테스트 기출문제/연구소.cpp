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
void tempInit(); // 입력한 맵과 똑같은 맵을 만들어주는 함수.
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
			if (map[y][x] == 2) // 만약 바이러스면 벡터에 넣는다.
				virus.push_back(make_pair(y, x));
		}
	}

	tempInit(); //임시 맵

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (temp[y][x] == 0) //만약 0이면 1로 바꾸고 dfs 시작
			{
				temp[y][x] = 1;
				dfs(1);
				temp[y][x] = 0; // 조합을 이용한 풀이
				tempInit(); // 끝날 때마다 temp를 다시 초기화 시켜준다
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
	if (cnt == 3) // 벽을 3개 세웠으면
	{
		bfs(); // 바이러스를 퍼트림.
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
	int bfsmap[8][8]; // temp를 건들면 dfs가 제대로 작동하지 않으므로 bfsmap을 만듦
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			bfsmap[y][x] = temp[y][x]; // 현재 temp의 맵 상태를 bfsmap에 복사.
		}
	}

	queue <pair<int, int >> q;
	for (int i = 0; i < virus.size(); i++)
	{
		q.push(virus[i]); // 바이러스 좌표를 큐에 넣는다.
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

			if (bfsmap[cy][cx] == 0) // 바이러스를 퍼트리는 코드
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
			if (bfsmap[y][x] == 0) // 0의 개수를 세서
				cnt++;
		}
	}
	answer = max(cnt, answer); // answer와 비교
}