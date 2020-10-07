#include <iostream>
#include <vector>
int n, m;
using namespace std;

vector <int> v[500];
bool visit[500];
void dfs(int number);
int main()
{
	int answer = 0;
	cin >> n;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int start, end;
		cin >> start >> end;
		v[start].push_back(end);
		v[end].push_back(start);
		
	}
	dfs(1);

	for (int i = 2; i <= n; i++) // 자기 자신은 세면 안됨.
	{
		if (visit[i] == true)
			answer++;
	}
	cout << answer;
	return 0;
}

void dfs(int number)
{
	
	for (int i = 0; i < v[number].size(); i++) // 현재 번호의 친구를 찾는 반복문
	{
			visit[v[number][i]] =true; 
	}

	if (number == 1)
	{
		for (int i = 0; i < v[number].size(); i++) //1의 친구의 친구를 찾는 반복문
		{
			int next = v[number][i];
			dfs(next);
		}
	}
}