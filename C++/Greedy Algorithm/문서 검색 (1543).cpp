#include <iostream>
#include <string>
using namespace std;


string s = "";
string subs = "";
int i, j;
int answer = 0;
int main()
{
	getline(cin , s);
	getline(cin, subs);
	int length = s.size() - subs.size();

	for (i = 0; i <= length+1; i++)
	{
		bool check = true;
		for (j = 0; j < subs.size(); j++)
		{
			if (subs[j] != s[j + i])
			{
				check = false;
				break;
			}
		}
		if (check == true)
		{
			answer++;
			i += (j - 1);
		}
	}
	cout << answer;
	return 0;
}