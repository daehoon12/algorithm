#include <iostream>
#include <vector>

using namespace std;
int cabin[101] = { 0, };
vector <int> v[101];
bool visit[101];
bool check[101];
int temp[101];
int n, m;
int minNum = 987654321;
int answer = 0;
void visitInit();
void tempInit();
void dfs(int i, int idx, int level);
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int sour, dest;
		cin >> sour >> dest;
		v[sour].push_back(dest);
		v[dest].push_back(sour);
	}
	tempInit();
	for (int i = 1; i <= n; i++)
	{
		check[i] = true;
		visit[i] = true;
		dfs(i, i, 1);
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			cabin[i] += temp[j];
		}
		visitInit();
		tempInit();
	}

	for (int i = 1; i <= n; i++)
	{
		if (minNum > cabin[i])
		{
			minNum = cabin[i];
			answer = i;
		}
	}
	cout << answer;
	return 0;
}


void dfs(int i, int idx, int level)
{

	for (int j = 0; j < v[i].size(); j++)
	{
		if (v[i][j] == idx)
			continue;
		if(temp[v[i][j]] > level)
			temp[v[i][j]] = level;
	}

	for (int j = 0; j < v[i].size(); j++)
	{
		int next = v[i][j];
		if (!visit[next])
		{
			visit[next] = true;
			dfs(next, idx, level + 1);
			visit[next] = false;
		}
	}
}

void visitInit()
{
	for (int i = 1; i <= n; i++)
		visit[i] = false;
}

void tempInit()
{
	for (int i = 1; i <= n; i++)
		temp[i] = 987654321;
}
