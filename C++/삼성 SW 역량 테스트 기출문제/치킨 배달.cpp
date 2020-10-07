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
		int chickinLoadofCity = 0; // ������ ġŲ�Ÿ�
		for (int i = 0; i < house.size(); i++)
		{
			int min_dist = 987654321;
			for (int j = 0; j < v.size(); j++) // 1���� ���� m���� ġŲ���� ���ؼ� �ּҰ��� ���Ѵ�.
			{
				min_dist = min(min_dist, abs(v[j].first - house[i].first) + abs(v[j].second - house[i].second));

			}
			chickinLoadofCity += min_dist; // ���� �ּҰ��� ������
		}
		if (answer > chickinLoadofCity)
			answer = chickinLoadofCity; // �ּ� ������ ġŲ�Ÿ��� ����.
		
		return;
	}
	for (int i = idx; i < shop.size(); i++) // ���� ���
	{
		v.push_back(shop[i]);
		dfs(i + 1);
		v.pop_back();
	}
}
