#include <iostream>
#include <algorithm>

using namespace std;

void map(int *a, int *b)
{
    if (*a % 2 == 0)
        *a /= 2;
    else if (*a % 2 == 1)
        *a = *a / 2 + 1;
    
    if (*b % 2 == 0)
        *b /= 2;
    else if (*b % 2 == 1)
        *b = *b / 2 + 1;
}
int solution(int n, int a, int b)
{
    int answer = 1;
    int toner = n;
    
    while (true)
    {
        answer++;
        map(&a,&b);
        if ((a + 1 == b || b + 1 == a) && max(a, b) % 2 == 0)
        {
            break;
        }
        
    }
    
    return answer;
}

int main()
{
    cout << solution(8, 1, 2);
}