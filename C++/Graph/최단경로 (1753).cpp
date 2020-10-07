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
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // pair의 first 값에 따라 내림차순으로 우선순위가 결정된다.
	dist[startNum] = 0;
	pq.push(make_pair(0, startNum));

	while (!pq.empty())
	{
		int current = pq.top().second;
		int distance = pq.top().first; // StartNum에서 Current 까지 가는 거리
		pq.pop();

		if (dist[current] < distance) // 위에서의 거리가 기존의 거리보다 크면 그냥 넘김 
			continue;
		for (int i = 0; i < v[current].size(); i++)
		{
			int next = v[current][i].second; // 현재 위치와 연결된 Node를 찾음
			int nextDistance = v[current][i].first + distance;

			if (nextDistance < dist[next]) // distance 업데이트 
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