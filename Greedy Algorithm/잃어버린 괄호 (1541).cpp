#include <iostream>
#include <string>

using namespace std;
string s = "";
int flag = 0;
int answer = 0;
int main()
{
	cin >> s;
	string temp = "";
	for (int i = 0; i <= s.size(); i++)
	{
		temp += s[i];
		if ((s[i] == '-' || s[i] == '\0') && flag == 0)
		{
			flag = 1;
			answer += stoi(temp);
			temp = "";
		}

		else if ((s[i] == '+' || s[i] == '\0') && flag == 0)
		{
			answer += stoi(temp);
			temp = "";
		}
		else if (flag == 1 && (s[i] == '-' || s[i] == '+' || s[i] == '\0'))
		{
			answer -= stoi(temp);
			temp = "";
		}
	
	}
	
	cout << answer;
	return 0;
}