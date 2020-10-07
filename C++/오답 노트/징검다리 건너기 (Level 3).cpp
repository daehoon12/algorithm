#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(int mid, int k, vector<int> stones)
{
    int ret = 0;
    int cnt = 0;
    for (int i = 0; i < stones.size(); i++)
    {
        stones[i] -= mid;
        if (stones[i] < 0) // mid명이 다리를 건넌 후의 다리 상태
            cnt++;
        else
            cnt = 0;

        if (cnt == k)
            return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int low = 1;
    int high = *max_element(stones.begin(), stones.end());
    
    while (true)
    {
        if (low > high)
            break;
        
        int mid = (low + high) / 2;
        if (check(mid, k, stones))
        {
            answer = max(answer, mid);
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return answer;
}
 
int main()
{
    solution({ 2,4,5,3,2,1,4,2,5,1 }, 3);
    return 0;
}
