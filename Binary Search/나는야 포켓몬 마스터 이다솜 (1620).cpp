#include <iostream>
#include <map>
#include <iterator>
#include <string>

using namespace std;

map <string, int> mp;
string str[100001];
int n, m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		str[i + 1] = s;
		mp.insert(make_pair(s, i + 1));
	}
	for (int i = 0; i < m; i++)
	{
		string s;
		cin >> s;
		if (s[0] > '0' && s[0] <= '9')
		{
			int idx = stoi(s);
			cout << str[idx] << '\n';
		}

		else
		{
			map <string, int> ::iterator iter = mp.find(s); // O(logN)
			cout << (*iter).second << '\n';
		}
	}
	return 0;
}
