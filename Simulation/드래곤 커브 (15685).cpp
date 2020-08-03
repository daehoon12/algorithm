#include <iostream>
#include <vector>
#include <cstring>
#include <stack>
using namespace std;

bool visit[101][101];

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,-1,0,1 };

int transformations[] = { 0, -1, 1, 0 };
vector<pair<int, int>> location;
int n, x, y, d, g;

int find_answer()
{
	int ret = 0;;
	for (int y = 0; y < 100; y++)
	{
		for (int x = 0; x < 100; x++)
			if (visit[y][x] == true) {
				if (visit[y][x] == visit[y + 1][x] && visit[y][x] == visit[y][x + 1] && visit[y][x] == visit[y + 1][x + 1])
					ret++;
			}
	}
	return ret;
}
void make_visit()
{
	int last_idx = location.size() - 1;
	int tx = location[last_idx].second;
	int ty = location[last_idx].first;
	for (int i = last_idx-1; i >= 0; i--)
	{
		int temp_x = location[i].second - tx;
		int temp_y = location[i].first - ty;

		int nx = temp_x * transformations[0] + temp_y * transformations[1];
		int ny = temp_x * transformations[2] + temp_y * transformations[3];

		nx += tx;
		ny += ty;

		visit[ny][nx] = true;
		location.push_back(make_pair(ny, nx));
	}
}

int main()
{
	cin >> n;
	visit[0][0] = true;
	for (int i = 0; i < n; i++)
    {
		location.clear();
		cin >> x >> y >> d >> g;
		visit[y][x] = true;
		location.push_back(make_pair(y, x));
		int nx = x + dx[d % 4];
		int ny = y + dy[d % 4];
		visit[ny][nx] = true;
		location.push_back(make_pair(ny, nx));

		for (int j = 1; j <= g; j++)
		{
			make_visit();
		}
	}
	int answer = find_answer();
	cout << answer;
	return 0;
}
