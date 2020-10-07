#include <iostream>
#include <vector>
using namespace std;
int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	int list[30];


	for (int i = 1; i <= n; i++)
	{
		list[i] = 1;
	}

	for (int i = 0; i < lost.size(); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == lost[i])
				list[j]--;
		}
	}
	
	for (int i = 0; i < reserve.size(); i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j == reserve[i])
				list[j]++;
		}
	}
	// 여벌 체육복 학생의 값 : 2, lost 친구 : 0
	for (int i = 1; i < n; i++)
	{
		if (list[i] == 0 && list[i + 1] == 2)
		{
			list[i]++;
			list[i + 1]--;
		}
		else if (list[i] == 0 && list[i - 1] == 2)
		{
			list[i]++;
			list[i - 1]--;
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (list[i] == 1 || list[i] == 2)
			answer++;
	}

	return answer;
}


int main()
{
	int n = 3;
		int answer = 0;
		int list[30];
		vector<int> lost = { 3};
		vector <int> reserve = { 1 };
		cout << solution(n, lost, reserve);
	return 0;
}

