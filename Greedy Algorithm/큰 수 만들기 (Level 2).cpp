#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> idx;
string answer = "";
bool check[1000001];
string s = "";
int k;
int temp = 0;
int main()
{
	cin >> s >> k;
	int outloop = s.size() - k;

	int pos = 0;
	while (true)
	{
		if (outloop <= 0)
			break;
		char maxChar = '0';
		for (int i = pos; i <= s.size() - outloop; i++) // 내가 구현 못했던 부분.
		{
			if (s[i] > maxChar)
			{
				maxChar = s[i];
				pos = i;
			}
			
		}
		answer += maxChar;
		outloop--;
		s.erase(s.begin() + pos);
	}
	cout << answer;
	return 0;
}
