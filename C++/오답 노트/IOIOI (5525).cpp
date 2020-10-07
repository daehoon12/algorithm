#include <iostream>

using namespace std;
int N, S;
string str;

int main()
{
	cin >> N;
	cin >> S;
	cin >> str;
	int answer = 0;
	int cnt = 0;
	for (int i = 0; i < str.size() - 2; i++)
	{
		if (str[i] == 'I' && str[i + 1] == 'O' && str[i + 2] == 'I')
		{
			cnt++;
			i++;
			if (cnt == N)
			{
				answer++;
				cnt--; // 감소 시키는 이유는 다음 조건에서도 IOI가 나올수 있어서
			}
		}
		else
			cnt = 0;
	}
	cout << answer;
	return 0;
}
