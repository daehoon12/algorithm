#include <iostream>
#include <map>
#include <algorithm>

using namespace std;
int t, f;
int parent[100001];
int f_size[100001];
map<string, int> mp; // 이름에 번호를 매기는 방식으로 map을 사용.

void init()
{
	for (int i = 0; i <= 100000; i++)
	{
		parent[i] = i;
		f_size[i] = 1;
	}
}

int Find(int x)
{
	if (parent[x] == x)
		return x;
	else
		return Find(parent[x]);
}

void Union(int x, int y)
{
	if (x > y)
	{
		parent[x] = y;
		f_size[x] += f_size[y]; // 크기를 합쳐주는 작업
		f_size[y] = f_size[x];
	}
	else 
	{
		parent[y] = x;
		f_size[y] += f_size[x]; // 크기를 합쳐주는 작업
		f_size[x] = f_size[y];
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		cin >> f;
		mp.clear();
		init();
		int idx = 1;
		for (int j = 1; j <= f; j++)
		{
			string a, b;
			cin >> a >> b;
			if (mp[a] == 0) 
				mp[a] = idx++;
			if (mp[b] == 0)
				mp[b] = idx++;
		
			int x = Find(mp[a]);
			int y = Find(mp[b]);

			if (x != y)
				Union(x, y);	
			cout << max(f_size[x], f_size[y]) << '\n';
		}
	}
	return 0;
}
