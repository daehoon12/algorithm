#include <iostream>
#include <cstring>
using namespace std;
bool map[31][31];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,-1,1 }; // 0 : 동, 1 :서, 2 : 남, 3 : 북
pair <int, double> dir[4];
bool visit[4];
int n;
double answer = 0;
void dfs(int cnt, int direct, double percent, int y, int x)
{
	if (cnt == n) {
		answer += percent;
		return;
	}

	map[y][x] = true; // 조합
	for (int i = 0; i < 4; i++)
	{
		if (map[dy[i] + y][dx[i] + x] == true)
			continue;
		dfs(cnt + 1, dir[i].first, percent * (dir[i].second/100), dy[i] + y, dx[i] + x);
	}
	map[y][x] = false;
}
int main()
{
	cin >> n;
	for (int i = 0; i < 4; i++)
	{
		cin >> dir[i].second;
		dir[i].first = i;		
	}

	dfs(0,0, 1, 15,15);
	cout.precision(10);
	cout << answer;
	return 0;
}