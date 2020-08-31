#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
int N, M;
int a;
int parent[51];
vector<int> v[51], truth;
void init()
{
	for (int i = 1; i <= 50; i++)
		parent[i] = i;
}
void input()
{
	cin >> N >> M;
	cin >> a;
	for (int i = 0; i < a; i++)
	{
		int num;
		cin >> num;
		truth.push_back(num);
	}
}

int Find(int x)
{
	if (parent[x] == 987654321)
		return -1;

	if (parent[x] == x)
		return x;

	else
		return Find(parent[x]);
}

void Union(int x, int y) {
	x = Find(x); // 2, 3
	y = Find(y);

	if (x < y) // 더 작은 idx가 부모가 됨 
		parent[y] = x;
	else
		parent[x] = y;
}
int main()
{
	int answer = 0;
	init();
	input();
	for (int i = 0; i < M; i++)
	{
		int num;
		cin >> num;
					
		for (int j = 0; j < num; j++)
		{
			int num2;
			cin >> num2;
			v[i].push_back(num2);
		}
		for (int j = 0; j < v[i].size()-1; j++)
		{
			if (Find(v[i][j]) != Find(v[i][j+1]))
			{
				Union(v[i][j], v[i][j+1]);
			}
		}
	}

	for (int i = 0; i < M; i++)
	{
		bool flag = 1;
		int curr = v[i][0];
		for (int j = 0; j < truth.size(); j++)
		{
			if (Find(curr) == Find(truth[j]))
			{
				flag = false;
				break;
			}
		}
		if (flag)
			answer++;
	}

	cout << answer;
	return 0;
}