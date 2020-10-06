/* 최단 거리를 구하는 문제가 아님.
   모든 경로를 탐색하되 최소의 거울을 배열값에 넣어야 한다.*/
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int W, H;
char graph[101][101];

int dx[] = { 0,1,0,-1 }; // 북 동 남 서
int dy[] = { -1,0,1,0 };
int visit[101][101];

class lazer {
public:
	int y, x, dir, cnt;
	lazer(int y, int x, int dir, int cnt)
	{
		this->y = y;
		this->x = x;
		this->dir = dir;
		this->cnt = cnt;
	}
};
pair<int, int > start_point, end_point;

void input()
{
	cin >> W >> H;
	bool flag = true;
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			cin >> graph[y][x];
			if (graph[y][x] == 'C')
			{
				if (flag == true) {
					flag = false;
					start_point = { y,x };
				}
				else
					end_point = { y,x };
				
			}
			visit[y][x] = 987654321;
		}
	}
}

int bfs()
{
	queue<lazer> q;
	visit[start_point.first][start_point.second] = 0;
	for (int i = 0; i < 4; i++)
	{
		int cx = start_point.second + dx[i];
		int cy = start_point.first + dy[i];
		if (cx < 0 || cx >= W || cy < 0 || cy >= H)
			continue;
		if (graph[cy][cx] != '*') 
		{
			visit[cy][cx] = 0;
			q.push(lazer(cy, cx, i, 0));
		}
	}
  
	while (!q.empty())
	{
		int x = q.front().x;
		int y = q.front().y;
		int c_cnt = q.front().cnt;
		int c_dir = q.front().dir;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int cx = x + dx[i];
			int cy = y + dy[i];
			int n_cnt =c_cnt;
			if (cx < 0 || cx >= W || cy < 0 || cy >=H || graph[cy][cx] == '*')
				continue;
			if (c_dir != i) // 거울이 필요함..
				n_cnt = c_cnt + 1;
			if (visit[cy][cx] >= n_cnt) // 더 적은 거울로 갈수 있으면
			{
				visit[cy][cx] = n_cnt; // 업데이트
				q.push(lazer(cy, cx, i, n_cnt));
			}
		}
	}
	return visit[end_point.first][end_point.second];
}

void print_map()
{
	for (int y = 0; y < W; y++)
	{
		for (int x = 0; x < H; x++)
		{
			cout << visit[y][x] << " ";
		}
		cout << '\n';
	}
}

int main()
{
	input();
	cout << bfs();
	//cout << '\n';
	//print_map();
	return 0;
}
