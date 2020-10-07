#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

char map[13][7];
bool visit[13][7];

vector<pair<int, int>> r_lo, b_lo, g_lo, y_lo, p_lo;

void input()
{
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			cin >> map[y][x];
		}
	}
}
bool bfs(vector<pair<int, int>>& v, char color)
{
	queue<pair<int, int>> q;
	bool return_flag = false;
	for (int i = 0; i < v.size(); i++)
	{
		q.push(make_pair(v[i].first, v[i].second));
		int cnt = 0;
		memset(visit, false, sizeof(visit));
		while (!q.empty())
		{
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			if (visit[y][x])
				continue;

			visit[y][x] = true;

			cnt++;
			for (int j = 0; j < 4; j++)
			{
				int cx = dx[j] + x;
				int cy = dy[j] + y;

				if (cx < 0 || cx >= 6 || cy < 0 || cy >= 12 || visit[cy][cx])
					continue;
				if (map[cy][cx] == color && !visit[cy][cx])
				{
					q.push(make_pair(cy, cx));
				}
			}
		}

		if (cnt >= 4) // 같은 색깔을 4개 이상 찾으면 뿌요를 터트리는 코드
		{
			return_flag = true;
			for (int y = 0; y < 12; y++)
			{
				for (int x = 0; x < 6; x++)
				{
					if (visit[y][x])
						map[y][x] = '.';
				}
			}
		}
	}
	if (return_flag == true) // 터트렸으면 T 안 됐으면 F
		return true;
	else
		return false;
}
vector<pair<int, int>> make_color(char color) // color의 좌표를 벡터에 담는 함수.
{
	vector<pair<int, int>> temp;
	for (int y = 0; y < 12; y++)
	{
		for (int x = 0; x < 6; x++)
		{
			if (map[y][x] == color)
				temp.push_back(make_pair(y, x));
		}
	}
	return temp;
}
void down_map() // 3중 for문을 이용해 map을 한단계 아래로 내리는 과정.
{
	for (int z = 0; z < 12; z++)
	{
		for (int y = 0; y < 12; y++)
		{
			for (int x = 0; x < 6; x++)
			{
				if (map[y][x] != '.' && map[y + 1][x] == '.')
				{
					map[y + 1][x] = map[y][x];
					map[y][x] = '.';
				}
			}
		}
	}
}
int main()
{
	input();
	int answer = 0;
	while (true)
	{
		r_lo = make_color('R');
		g_lo = make_color('G');
		b_lo = make_color('B');
		y_lo = make_color('Y');
		p_lo = make_color('P');

		bool r = bfs(r_lo, 'R');
		bool g = bfs(g_lo, 'G');
		bool b = bfs(b_lo, 'B');
		bool y = bfs(y_lo, 'Y');
		bool p = bfs(p_lo, 'P');

		if (r || g || b || y || p) // 하나의 색깔이라도 터지면 값을 증가시킨다.
			answer++;
		if (!r && !g && !b && !y && !p) // 전부 터지지 않을 경우 반복문을 빠져나감
			break;
		down_map();
		
	}
	cout << answer;
	return 0;
}
