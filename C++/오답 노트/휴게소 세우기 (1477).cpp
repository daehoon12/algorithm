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
			if (dist % mid == 0) // �Ÿ��� mid ���� ������ �������� �Ÿ��� �ǳ��� �ްԼҸ� ����� �Ͱ� ����.
				cnt--;
		}

		if (cnt > M)
		{
			low = mid + 1;
		}
		else
		{
			/*	 // �� ���ǹ��� ���� Ʋ�� 
			cnt�� M���� �۾Ƶ� M-cnt���� �ްԼҸ� �ƹ��볪 
			����ٰ� �����ص� ���� ���� �� �ִ�.*/
		   // if(cnt == M) 
			answer = min(mid, answer);
			high = mid - 1;
		}
	}
	cout << answer;
	return 0;
}