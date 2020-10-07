#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[10001];
int cntmemory[10001];
bool visit[10001];
void visitInit();
int maxNum = 0;
int n, m;
int cnt = 0;
void dfs(int i);
int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int sour, dest;
		cin >> sour >> dest;
		v[dest].push_back(sour);
	}

	for (int i = 1; i <= n; i++)
	{
		visit[i] = true;
		dfs(i);
		maxNum = max(maxNum, cnt);
		cntmemory[i] = cnt;
		visitInit();
		cnt = 0;
	}

	for (int i = 1; i <= n; i++)
	{
		if (maxNum == cntmemory[i])
		{
			cout << i << " ";
		}
	}
	return 0;
}

void dfs(int i)
{
	
	for (int j = 0; j < v[i].size(); j++)
	{
		
		int next = v[i][j];
		if (!visit[next])
		{
			cnt++;
			visit[next]=true;
			dfs(next);
		}
	}
}

void visitInit()
{
	for (int i = 1; i <= n; i++)
		visit[i] = false;
}