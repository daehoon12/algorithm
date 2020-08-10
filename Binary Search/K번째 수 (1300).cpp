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


/*i���� ���ڵ��� i*1, i*2, i*3, ..., i*N���� �����Ǿ� �ִ�.

i���� ���ڵ� �� mid���� �۰ų� ���� ���ڴ� (i*j <= mid)�� �����ϴ� j�� �����̰�

�̴� i*1, i*2, ..., i*j�̹Ƿ�, m/i�� ���� ���� �ȴ�.

�̺�Ž���� ���� �������� answer�� ���� ���ǿ� �´� K�� ���� ��. 

high�� K�� ������ �� �ִ� ���� : 
�̺�Ž���� ������ k�� ��Ƶ� �ȴٴ� ���� ��� k�� ���� �迭�� �ִ� �� �� k��°�� ���� ���� k ���϶�� ���̸�
, �̴� ��� k�� ���� �迭�� k ������ ���� k�� �̻� �����Ѵٴ� �Ͱ� ��ġ
  (ex. n = 3�� ��� 1, 2, 3, 2, 4, 6, 3, 6, 9), ��� k�� ���� ���� k���� ���� k �����̹Ƿ� ���� ������ ����
*/