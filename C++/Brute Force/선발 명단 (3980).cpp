#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int stated[11][11];
bool visit[11];
int t;
int answer = 0;



void go(int idx1, int idx2, int cnt, int sum)
{
	if (idx1 == 11)
	{
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 11; i++)
	{
		if (!visit[i] && stated[idx1][i] != 0)
		{
			visit[i] = true;
			sum += stated[idx1][i];
			go(idx1 + 1, i, cnt + 1, sum);
			sum -= stated[idx1][i];
			visit[i] = false;
		}
	}
}

int main()
{
	cin >> t;
	for (int z = 0; z < t; z++)
	{
		for (int y = 0; y < 11; y++)
		{
			for (int x = 0; x < 11; x++)
				cin >> stated[y][x];
		}
		answer = 0;
		memset(visit, false, sizeof(visit));
		go(0, 0, 0, 0);
		cout << answer << '\n';
	}
	return 0;
}