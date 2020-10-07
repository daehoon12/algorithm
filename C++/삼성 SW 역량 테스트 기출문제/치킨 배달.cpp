#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int map[50][50];
vector <pair<int,int>> v, house, shop;
int n,m;
int answer = 987654321;

void dfs(int idx);
int main()
{
	cin >> n >> m;
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 1)
				house.push_back(make_pair(y, x));
			else if (map[y][x] == 2)
				shop.push_back(make_pair(y, x));
		}
	}

	dfs(0);
	cout << answer;
	return 0;
}

void dfs(int idx)
{
	if (v.size()== m)
	{
		int chickinLoadofCity = 0; // 도시의 치킨거리
		for (int i = 0; i < house.size(); i++)
		{
			int min_dist = 987654321;
			for (int j = 0; j < v.size(); j++) // 1개의 집과 m개의 치킨집을 비교해서 최소값을 구한다.
			{
				min_dist = min(min_dist, abs(v[j].first - house[i].first) + abs(v[j].second - house[i].second));

			}
			chickinLoadofCity += min_dist; // 구한 최소값을 더해줌
		}
		if (answer > chickinLoadofCity)
			answer = chickinLoadofCity; // 최소 도시의 치킨거리를 구함.
		
		return;
	}
	for (int i = idx; i < shop.size(); i++) // 조합 사용
	{
		v.push_back(shop[i]);
		dfs(i + 1);
		v.pop_back();
	}
}
