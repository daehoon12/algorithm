#include <iostream>
#include <queue>
using namespace std;

int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
int answer = 0;
int map[101][101][101];
vector <pair<pair<int, int>, int >> loc;
queue <pair<pair<int, int>, int >> q;
int m, n, h;

bool checkAnswer()
{
	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				if (map[z][y][x] == 0)
					return false;
			}
		}
	}
	return true;
}
void bfs()
{
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first.second;
		int z = q.front().first.first;
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int cx = dx[i] + x;
			int cy = dy[i] + y;
			int cz = dz[i] + z;

			if (cx < 0 || cy < 0 || cz < 0 || cx >= m || cy >= n || cz >= h || map[cz][cy][cx] != 0)
				continue;
			if (map[cz][cy][cx] == 0)
			{
				map[cz][cy][cx] += map[z][y][x] + 1;
				q.push(make_pair(make_pair(cz, cy), cx));
			}
		}
		answer = map[z][y][x] - 1;
	}
}

void input()
{

	cin >> m >> n >> h;

	for (int z = 0; z < h; z++)
	{
		for (int y = 0; y < n; y++)
		{
			for (int x = 0; x < m; x++)
			{
				cin >> map[z][y][x];
				if (map[z][y][x] == 1)
					q.push(make_pair(make_pair(z, y), x));
					
			}
		}
	}
}
int main()
{
	input();
	if (checkAnswer() == true)
	{
		cout << 0;
		return 0;
	}
	bfs();
	//for (int z = 0; z < h; z++)
	//{
	//	for (int y = 0; y < n; y++)
	//	{
	//		for (int x = 0; x < m; x++)
	//		{
	//			cout << map[z][y][x] << " ";
	//		}
	//		cout << '\n';
	//	}
	//}
	if (checkAnswer() == false)
	{
		cout << -1;
	
	}
	else
		cout << answer;
	return 0;
}