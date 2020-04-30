#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int cnt = 0;
bool check[1001];
int maxNum = 0;
int answer = 0;
vector <int> v[1001];
void visitInit();
void dfs(int i);
int main()
{

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int k;
		cin >> k;
		v[i].push_back(k);
	}

	for (int i = 1; i <= n; i++)
	{
		dfs(i);
		if (cnt > maxNum)
		{
			maxNum = cnt;
			answer = i;
		}
		cnt = 0;
		visitInit();
	}
	cout << answer;
	return 0;
}

void dfs(int i)
{
	cnt++;
	check[i] = true;

	for (int j = 0; j < v[i].size(); j++)
	{
		int next = v[i][j];
		if (!check[next])
		{
			dfs(next);
		}
	}
}

void visitInit()
{
	for (int i = 1; i <= n; i++)
	{
		check[i] = false;
	}
}