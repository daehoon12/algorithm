#include <iostream>
#include <vector>
using namespace std;
vector <int> v[101];
int n;
bool map[101][101];
bool answer[101][101];
bool visit[101];
void visitInit();
void dfs(int i, int idx);
int main()
{
	cin >> n;
	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 1)
			{
				v[y].push_back(x);
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		dfs(i, i);
		visitInit();
	}

	for (int y = 1; y <= n; y++)
	{
		for (int x = 1; x <= n; x++)
		{
			cout << answer[y][x] << " ";
		}
		cout << '\n';
	}

	return 0;
}

void dfs(int i, int idx)
{
	
	for (int j = 0; j < v[i].size(); j++)
	{
		int next = v[i][j];

		if (!visit[next])
		{
			visit[next] = true;
			answer[idx][next] = true;
			dfs(next, idx);
		}
	}
}

void visitInit()
{
	for (int i = 1; i <= n; i++)
		visit[i] = false;
}
