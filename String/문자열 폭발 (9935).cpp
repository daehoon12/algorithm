#include <iostream>
#include <vector>
using namespace std;
char answer[1000001];
string s, bomb;


int main()
{
	cin >> s;
	cin >> bomb;
	int idx = 0;
	for (int i = 0; i < s.length(); i++)
	{
		answer[idx++] = s[i]; // 일단 추가하고
		if (bomb[bomb.size() - 1] == answer[idx-1])
		{
			if (idx - bomb.length() < 0)
				continue;
			bool flag = true;
			for (int j = 0; j < bomb.length(); j++)
			{
				if (answer[idx - j - 1] != bomb[bomb.length() - j - 1])
				{
					flag = false;
					break;
				}
			}
			if (flag)
				idx -= bomb.length();
		}

	}
	if (!idx) // idx 값이 0 == 모든 문자열 폭발
		cout << "FRULA";
	
	for (int i = 0; i < idx; i++)
		cout << answer[i];
	return 0;
}
