#include <string>
#include <vector>

using namespace std;
int a[1000001];
int answer2 = 0;
void primeNumber(int n)
{
	for (int i = 2; i <= n; i++) // init
	{
		a[i] = i;
	}

	for (int i = 2; i <= n; i++)
	{
		if (a[i] == 0) // �̹� ������ �迭�̸� �ǳʶ� 
			continue;
		for (int j = i + i; j <= n; j += i) // �ڱ� �ڽ��� ������ �ʴ´�. 
			a[j] = 0;
	}

	for (int i = n; i <= n; i++)
	{
		if (a[i] != 0) // �������� ���� ���� �Ҽ� 
			answer2++;
	}
}
int solution(int n) {
	int answer = 0;
	primeNumber(n);
	answer = answer2;
	return answer;
}

int main()
{
	solution(10);
}