#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
char map[51][5][7];
vector <pair <pair<int, int>, int>> v;

bool cmp(pair <pair<int, int>, int> a, pair <pair<int, int>, int> b)
{
	if (a.second > b.second)
		return true;
	else if (a.second == b.second)
		return a.first.first < b.first.first;
	
	return false;
}
int main()
{
	cin >> n;

	for (int i = 1; i <=n; i++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 7; x++)
			{
				cin >> map[i][y][x];
			}
		}
	}

	
	for (int i = 1; i <=n; i++)
	{
		for (int j = i+1; j <=n; j++)
		{
			int cnt = 0;
			for (int y = 0; y < 5; y++)
			{
				for (int x = 0; x < 7; x++)
				{
					if (map[i][y][x] == map[j][y][x])
						cnt++;
				}	
			}
			v.push_back(make_pair(make_pair(i, j), cnt));
			
		}
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].first.first << " " << v[0].first.second;
}