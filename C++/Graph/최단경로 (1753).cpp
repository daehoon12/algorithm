#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dist[20001] = { 0, };
int n,e;
int startNode;
int INF = 100000000000;
vector <pair<int, int>> v[20001];
void distInit()
{
	for (int i = 0; i < 20001; i++)
	{
		dist[i] = INF;
	}
}

void dijkstra(int startNum)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair�� first ���� ���� ������������ �켱������ �����ȴ�.
	dist[startNum] = 0;
	pq.push(make_pair(0, startNum));

	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = pq.top().first; // StartNum���� Current ���� ���� �Ÿ�
		pq.pop();

		if (dist[current] < distance) // �������� �Ÿ��� ������ �Ÿ����� ũ�� �׳� �ѱ� 
			continue;
		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i].second; // ���� ��ġ�� ����� Node�� ã��
			int nextDistance = v[current][i].first + distance;

			if (nextDistance < dist[next]) // distance ������Ʈ 
			{
				dist[next] = nextDistance;
				pq.push(make_pair(next, nextDistance));
			}
		}
	}

}

void input()
{
	cin >> n >> e;
	cin >> startNode;
	for (int i = 0; i < e; i++)
	{
		int s, e, cost;
		cin >> s >> e >> cost;
		v[s].push_back(make_pair(cost, e));
	}
}
int main()
{
	input();
	distInit();
	dijkstra(startNode);
	for (int i = 1; i <= n; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
	return 0;
}