#include <iostream>
#include <string>

int n;
using namespace std;

bool check(string s, int cnt)
{
	for (int i = 1; i <= cnt / 2; i++)
	{
		string a = s.substr(cnt - i, i);
		string b = s.substr(cnt - i * 2, i);

		if (a == b)
			return false;
	}
	return true;
}
void go(string s, int cnt)
{
	
	if (cnt == n)
	{
		cout << s;
		exit(0);
	}

	if (!check(s, cnt))
		return;

	for (int i = 1; i <= 3; i++)
	{
		s += to_string(i);
		go(s, cnt + 1);
		s.pop_back();
	}
}
int main()
{
	cin >> n;
	go(to_string(1), 1);
	return 0;
}