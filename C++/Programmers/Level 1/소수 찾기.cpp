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
		if (a[i] == 0) // 이미 지워진 배열이면 건너뜀 
			continue;
		for (int j = i + i; j <= n; j += i) // 자기 자신은 지우지 않는다. 
			a[j] = 0;
	}

	for (int i = n; i <= n; i++)
	{
		if (a[i] != 0) // 지워지지 않은 값은 소수 
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