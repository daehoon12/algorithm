#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
/* bfs를 이용한 브루트포스 문제였음.*/
using namespace std;
int	n, m;
queue <pair<int, int>> q;
char map[51][51];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int dist[51][51] = { 0, };
int bfs(int y ,int x);
int answer = 0;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'L')
			{
				answer = max(answer, bfs(i,j));
				
			}
		}
	}

	cout << answer;
	
	return 0;
}	

int bfs(int y, int x)
{
	memset(dist, 0, sizeof(dist));
	queue <pair<int, int>> q;
	int temp=0;
	q.push(make_pair(y, x));
	dist[y][x] = 1;

	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
	
		q.pop();
		temp = max(temp, dist[y][x]);
		for (int i = 0; i < 4; i++)
		{
		 	int cx = x + dx[i];
		    int cy = y + dy[i];
			
		
			if (cx < 0 || cx >= m || cy < 0 || cy >= n)
				continue;
			
			if (map[cy][cx] == 'L' && dist[cy][cx]==0)
			{
				dist[cy][cx] = dist[y][x] + 1;
				q.push(make_pair(cy, cx));
			
			}
		}
	}
	return temp-1;
}