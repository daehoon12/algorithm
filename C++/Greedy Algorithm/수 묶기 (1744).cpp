#include <iostream>
#include <queue>

using namespace std;
int n;
priority_queue <int> plusQ;
priority_queue<int, vector<int>, greater<>> minusQ; // 우선순위 큐 내림차순 코드. 꼭 외워두자

int answer = 0;
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;

		if (val > 0)
			plusQ.push(val);
		else
			minusQ.push(val);
	}

	while (!plusQ.empty())
	{
		int plusNum1 = plusQ.top();
		plusQ.pop();
		{
			if (plusQ.empty()) {
				answer += plusNum1;
				continue;
			}
		}
		int plusNum2 = plusQ.top();
		plusQ.pop();

		if (plusNum1 == 1 || plusNum2 == 1)
		{
			answer += (plusNum1 + plusNum2);
		}
		else
			answer += (plusNum1 * plusNum2);

	}

	while (!minusQ.empty())
	{
		int minusNum1 = minusQ.top();
		minusQ.pop();
		{
			if (minusQ.empty()) {
				answer += minusNum1;
				continue;
			}
		}
		int minusNum2 = minusQ.top();
		minusQ.pop();
		answer += (minusNum1 * minusNum2);
	}

	cout << answer;
	return 0;
}