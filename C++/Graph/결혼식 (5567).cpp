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

	for (int i = 2; i <= n; i++) // �ڱ� �ڽ��� ���� �ȵ�.
	{
		if (visit[i] == true)
			answer++;
	}
	cout << answer;
	return 0;
}

void dfs(int number)
{
	
	for (int i = 0; i < v[number].size(); i++) // ���� ��ȣ�� ģ���� ã�� �ݺ���
	{
			visit[v[number][i]] =true; 
	}

	if (number == 1)
	{
		for (int i = 0; i < v[number].size(); i++) //1�� ģ���� ģ���� ã�� �ݺ���
		{
			int next = v[number][i];
			dfs(next);
		}
	}
}