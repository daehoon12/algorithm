#include <iostream>
#include <queue>
#include <string>
using namespace std;
int t;
int dist[10001];
bool primeNum[10001];
void eratos()
{
	for (int i = 0; i < 10001; i++)
		primeNum[i] = true;
	for (int i = 2; i < 10001; i++)
	{
		if (primeNum[i] == false)
			continue;
		for (int j = i+i ; j < 10001; j += i)
		{
			primeNum[j] = false;
		}
	}
}
string startNum, endNum;

void bfs(string start)
{
	queue <string> q;
	q.push(start);
	dist[stoi(start)] = 0;
	while (!q.empty())
	{

		string temp = q.front();
		string defalutNum = temp;
		//cout << temp << "->" << " ";
		if (stoi(temp) == stoi(endNum))
		{
			cout << dist[stoi(temp)] << '\n';
			return;
		}

		q.pop();
		for (int i = 3; i >= 0; i--)
		{
			temp = defalutNum;
			for (int j = 0; j < 10; j++)
			{
				temp[i] = j + '0';
				int idx = stoi(temp);
				if (idx >=1000 && primeNum[idx] && dist[idx] == -1)
				{
					q.push(temp);
					dist[idx] = dist[stoi(defalutNum)] + 1;
				}
			}
		}
	}
	cout << "Impossible" << '\n';
}
int main()
{
	cin >> t;
	eratos();
	for (int i = 0; i < t; i++)
	{
		cin >> startNum >> endNum;
		memset(dist, -1, sizeof(dist));
		bfs(startNum);
	}
}

