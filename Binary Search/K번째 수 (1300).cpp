#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long long n, k;
	int answer = 0;
	cin >> n;
	cin >> k;

	long long low = 1;
	long long high = n*n;
	while (true)
	{
		if (low > high)
			break;
		long long cnt = 0;
		long long mid = (low + high) / 2;
		for (int i = 1; i <= n; i++)
		{
			cnt += min(mid / i, n);
		}
		if (cnt < k)
		{
			low = mid + 1;
		}
		else
		{
			answer = mid;
			high = mid - 1;
		}

	}
	cout << answer;
	return 0;
}


/*i행의 숫자들은 i*1, i*2, i*3, ..., i*N으로 구성되어 있다.

i행의 숫자들 중 mid보다 작거나 같은 숫자는 (i*j <= mid)를 만족하는 j의 개수이고

이는 i*1, i*2, ..., i*j이므로, m/i와 같은 값이 된다.

이분탐색을 빠져 나갈때의 answer의 값이 조건에 맞는 K의 값이 됨. 

high를 K로 설정할 수 있는 이유 : 
이분탐색의 상한을 k로 잡아도 된다는 것은 모든 k에 대해 배열에 있는 수 중 k번째로 작은 수가 k 이하라는 뜻이며
, 이는 모든 k에 대해 배열에 k 이하인 수가 k개 이상 존재한다는 것과 동치
  (ex. n = 3일 경우 1, 2, 3, 2, 4, 6, 3, 6, 9), 모든 k에 대해 앞의 k개의 수가 k 이하이므로 위의 명제가 성립
*/