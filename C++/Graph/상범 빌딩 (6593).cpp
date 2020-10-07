#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

char map[31][31][31];
using namespace std;
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };

int R, C, L;
vector<pair<pair<int, int>, int>> v;
int visit[31][31][31] = { 0, };

int bfs()
{
	int x=0, y=0, z=0;
	queue<pair<pair<int, int>, int>> q;
	q.push(v[0]);
	visit[v[0].first.first][v[0].first.second][v[0].second] = 1;
	v.pop_back();
	while (!q.empty())
	{
		x = q.front().second;
		y = q.front().first.second;
		z = q.front().first.first;

		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int cx = dx[i] + x;
			int cy = dy[i] + y;
			int cz = dz[i] + z;
			if (cx < 0 || cy < 0 || cz < 0 || cx >=C || cy >=R || cz >=L || map[cz][cy][cx] == '#' ) 
				continue;

			if (visit[cz][cy][cx] == 0 )
			{
				visit[cz][cy][cx] = visit[z][y][x] + 1;
				q.push(make_pair(make_pair(cz, cy), cx));
			}

			if(map[cz][cy][cx] == 'E')
				return visit[z][y][x];
		}
	}
	return -1;
}

int main()
{
	while (true) {
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
		{
			return 0;
		}
		for (int z = 0; z < L; z++)
		{
			for (int y = 0; y < R; y++)
			{
				for (int x = 0; x < C; x++)
				{
					cin >> map[z][y][x];
					if (map[z][y][x] == 'S')
						v.push_back(make_pair(make_pair(z, y), x));
				}
			}
		}
		int temp = bfs();
		if (temp == -1)
			cout << "Trapped!" << '\n';
		else
			cout << "Escaped in " << temp << " minute(s)." << '\n';
		memset(visit, 0, sizeof(visit));
	}
	return 0;
}