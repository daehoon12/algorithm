#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int N, M, L;

void input() 
{
	cin >> N >> M >> L;
	v.push_back(0);
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	v.push_back(L);
	sort(v.begin(), v.end());
}

int main()
{
	input();
	int answer = 987654321;
	int low = 1;
	int high = L - 1;

	while (true)
	{
		if (low > high)
			break;

		int mid = (low + high) / 2;
		int cnt = 0;
		for (int i = 1; i < v.size(); i++)
		{
			int dist = v[i] - v[i - 1];
			cnt += dist / mid;
			if (dist % mid == 0) // 거리와 mid 값이 나누어 떨어지면 거리의 맨끝에 휴게소를 세우는 것과 같음.
				cnt--;
		}

		if (cnt > M)
		{
			low = mid + 1;
		}
		else
		{
			/*	 // 이 조건문을 쓰면 틀림 
			cnt가 M보다 작아도 M-cnt개의 휴게소를 아무대나 
			세운다고 가정해도 값은 구할 수 있다.*/
		   // if(cnt == M) 
			answer = min(mid, answer);
			high = mid - 1;
		}
	}
	cout << answer;
	return 0;
}