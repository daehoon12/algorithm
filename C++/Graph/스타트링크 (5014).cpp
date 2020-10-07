#include <iostream>
#include <queue>

using namespace std;
int dist[1000000];
int F, S, G, U, D;
int bfs();
queue<int > q;
int main()
{
	cin >> F >> S >> G >> U >> D;
	int answer = bfs();
	if (answer == -1)
		cout << "use the stairs";
	else
		cout << answer << endl;

	return 0;
}

int bfs()
{
	queue<int > q;
	q.push(S);
	dist[S] = 1;
	
	while (!q.empty())
	{

		int state = q.front();
		q.pop();

		if (state == G)
			return dist[state]-1;

		int dy[] = { U,-D };
		for (int i = 0; i < 2; i++)
		{
			int cy = state + dy[i];
			if (cy< 1 || cy>F)
				continue;

			if (dist[cy] == 0) {
				dist[cy] = dist[state] + 1;
				q.push(cy);
			}
		}
	}
	return -1;
}