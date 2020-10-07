#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n';

using namespace std;
bool visit[9];

vector<int> ind,v;
int n, m;

int main()
{
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++)
	{
		v.push_back(i);
	}

	for (int i = 0; i < m; i++) //	1이 뽑을만할 숫자.
	{
		ind.push_back(1);
	}

	for (int i = 0; i < v.size() - m; i++) //
	{
		ind.push_back(0);
	}

	sort(ind.begin(), ind.end(), greater<int>());

	do
	{
		for (int i = 0; i < v.size(); i++)
			if (ind[i] == 1)
			{
				cout << v[i] << " ";
			}
		cout << '\n';
	} while (next_permutation(ind.begin(), ind.end(), greater<int>()));
	return 0;
}