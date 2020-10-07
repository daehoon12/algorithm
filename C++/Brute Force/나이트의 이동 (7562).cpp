#include <iostream>
#include <queue>
using namespace std;
int l,t;
int cnt=0;
int startx, starty;
int targetx, targety;
int map[300][300] = { 0, };
void mapInit();
pair <int, int > p[] = {make_pair(1,2), make_pair(2,1) ,make_pair(2,-1), make_pair(1, -2), make_pair(-1, -2), make_pair(-2, -1), make_pair(-2,1), make_pair(-1,2) };
queue <pair<int,int>> q;
int main()
{
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> l;
		cin >> startx >> starty;
		cin >> targetx >> targety;

		q.push(make_pair(starty, startx));

		while (!q.empty())
		{
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			if (x == targetx && y == targety)
			{
				cout << map[y][x] << endl;
				break;
			}
			for (int i = 0; i < 8; i++)
			{
				int cy = y + p[i].first;
				int cx = x + p[i].second;

				if (cy < 0 || cy >= l || cx < 0 || cx >= l)
					continue;

				if (!map[cy][cx]) {
					map[cy][cx] = map[y][x] + 1;
					q.push(make_pair(cy, cx));
				}
			}

		}

		while (!q.empty())
			q.pop();
		mapInit();
	}
	return 0;
}

void mapInit()
{
	for (int i = 0; i < 300; i++)
	{
		for (int j = 0; j < 300; j++)
			map[i][j] = 0;
	}
}