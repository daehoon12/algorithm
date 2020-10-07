#include <iostream>
#include <cstdio>
#include <algorithm>

#pragma warning (disable:4996)
using namespace std;
int n, m;
int map[1001][1001];
int answer = 0;
void input()
{
	cin >> n >> m;
	for (int y = 1; y <=n; y++)
	{
		for (int x = 1; x <= m; x++)
		{
			scanf("%1d", &map[y][x]);
			if (map[y][x] == 1)
				answer = 1;
		}
	}
}

int main()
{	
	input();
	for (int y = 2; y <= n; y++)
	{
		for (int x = 2; x <= m; x++)
		{
			if (map[y][x] == 1)
			{
				map[y][x] = min(min(map[y - 1][x], map[y - 1][x - 1]), map[y][x - 1]) + 1;
				answer = max(answer, map[y][x]);
			}
		}
	}
	cout << answer * answer;
	return 0;
}
