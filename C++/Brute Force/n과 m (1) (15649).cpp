#include <iostream>
#include <vector>
#define endl "\n"

using namespace std;
bool visit[9];

vector<int> v;
int m, n;

void dfs(int cnt);

int main()
{
	cin >> m >> n;

	dfs(0);
	return 0;
}

void dfs(int cnt)
{
	if (cnt == n)
	{
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= m; i++)
	{
		if (!visit[i])
		{
			visit[i] = true;
			v.push_back(i);
			dfs(cnt + 1);
			v.pop_back();
			visit[i] = false;
		}
	}
}	