#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
int n;

vector <pair<int,int>> v[10001];
int visit[10001];
void input()
{
	cin >> n;
	for (int i = 0; i < n-1; i++)
	{
		int start_node, end_node, weight;
		cin >> start_node >> end_node >> weight;
		v[start_node].push_back(make_pair(end_node,weight));
		v[end_node].push_back(make_pair(start_node,weight));
	}
}

int bfs(int start_node)
{
	int ret = 0, max_num = 0;
	queue<pair<int, int>> q;
	q.push(make_pair(start_node, 0));
	while (!q.empty())
	{
		int num = q.front().first;
		int weight = q.front().second;
		q.pop();
		for (int i = 0; i < v[num].size(); i++)
		{
			int next_num = v[num][i].first;
			int next_weight = v[num][i].second;
			if (!visit[next_num])
			{
				visit[next_num] = weight +next_weight;
				q.push(make_pair(next_num, visit[next_num]));
				if (max_num < visit[next_num])
				{
					max_num = visit[next_num];
					ret = next_num;
				}
			}
		}
	}
	return ret;
}

int main()
{
	input();
	int max_node = bfs(1);
	memset(visit, 0, sizeof(visit));
	int answer_idx =bfs(max_node);
	cout << visit[answer_idx];
	return 0;
}