#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int robotIdx[101];
bool flag = false;
int n, m;
string answer = "";
int a, b;
int map[101][101] = { 0, };

pair<int, int> p[101];
int main()
{
	cin >> a >> b;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		int x, y;
		int dir = 0;
		char ch;
		cin >> x >> y >> ch;
		map[y][x] = i;
		p[i] = make_pair(x, y);
		if (ch == 'N')
		{
			robotIdx[i] = 0;
		}
		else if (ch == 'E')
		{
			robotIdx[i] = 1;
		}
		else if (ch == 'S')
		{
			robotIdx[i] = 2;
		}
		else if (ch == 'W')
		{
			robotIdx[i] = 3;
		}
	}

	for (int i = 1; i <=m; i++)
	{
		
		int number, iter;
		char ch;

		cin >> number >> ch >> iter;
	

		for (int i = 0; i < iter; i++) {
			int x = p[number].first;
			int y = p[number].second;
			if (ch == 'L')
			{
				robotIdx[number] = (robotIdx[number] + 3) % 4;
			}
			else if (ch == 'R')
			{
				robotIdx[number] = (robotIdx[number] + 1) % 4;
			}
			else if (ch == 'F')
			{
				int cy = dy[robotIdx[number]] + y;
				int cx = dx[robotIdx[number]] + x;

				if (cx > a || cx < 1 || cy > b || cy < 1)
				{
					printf("Robot %d crashes into the wall\n", number);
					return 0;
				}
				else if (map[cy][cx] != 0)
				{
					printf("Robot %d crashes into robot %d\n", number, map[cy][cx]);
					return 0;
				}
				map[y][x] = 0;
				p[number] = make_pair(cx, cy);
				map[cy][cx] = number;
			}

		}
	}
	cout << "OK";
	return 0;
}
