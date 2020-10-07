#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int answer = 0;
int n, m;
priority_queue <int> minusQ;
priority_queue <int, vector<int>, greater<int>> plusQ ;
int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		if (k > 0)
		{
			plusQ.push(k);
		}
		else
		{
			minusQ.push(k);
		}
	}
	
	while (true)
	{
		int num1 = 0, num2 = 0;
		if (plusQ.empty() && minusQ.empty())
			break;

		if (!plusQ.empty()) {

			if (plusQ.size() % m)
			{
				int idx = plusQ.size() % m;
				for (int i = 0; i < idx - 1; i++) {
					plusQ.pop();
				}
				num1 = plusQ.top();
		
			}
			else if (plusQ.size() % m == 0)
			{
				int idx = m - 1;
				for (int i = 0; i < idx; i++) {
					plusQ.pop();
				}
				num1 = plusQ.top();

			}	
		}

		if (!minusQ.empty()) {

			if (minusQ.size() % m)
			{
				int idx = minusQ.size() % m;
				for (int i = 0; i < idx - 1; i++) {
					minusQ.pop();
				}
				num2 = minusQ.top();

			}
			else if (minusQ.size() % m == 0)
			{
				int idx = m - 1;
				for (int i = 0; i < idx; i++) {
					minusQ.pop();
				}
				num2 = minusQ.top();

			}
		}

		if (num1 != 0 && num2 != 0)
		{
			if (abs(num1) > abs(num2))
			{
				answer += abs(num2) * 2;
				if (!minusQ.empty())
					minusQ.pop();
			}
			else {
				answer += abs(num1) * 2;
				if (!plusQ.empty())
					plusQ.pop();
			}
		}

		else if (num1 == 0)
		{
			if (minusQ.size()==1)
			{
				answer += abs(num2);
				minusQ.pop();
			}
			else if (!minusQ.empty())
			{
				answer += abs(num2) * 2;
				minusQ.pop();
			}
		}
		else if (num2 == 0) {
			if (plusQ.size() == 1) {
				answer += abs(num1);
				plusQ.pop();
			}
			else if (!plusQ.empty())
			{
				answer += abs(num1)*2;
				plusQ.pop();
			}
		}
	}

	cout << answer;
	return 0;
}