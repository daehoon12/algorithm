#include <string>
#include <iostream>
#include <algorithm>

using namespace std;
int cnt = 0;
string a = "";
string b = "";
int answer = 987654321;
int main()
{
	cin >> a >> b;
	int bound = b.size() - a.size();
	for (int i = 0; i <= bound; i++)
	{
		int idx = 0;
		cnt = 0;
		for (int j = i; j < a.size()+i; j++)
		{
			if (a[idx] != b[j])
				cnt++;
			idx++;
		}
		answer = min(cnt, answer);
	}
	cout << answer;
	}