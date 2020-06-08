#include <vector>
#include <algorithm>
using namespace std;
bool check[200001];
int solution(vector<int> nums)
{
    int answer = 0;
    int cnt = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (check[nums[i]] == false)
        {
            check[nums[i]] = true;
            cnt++;
        }
    }
    
    if (nums.size() / 2 <= cnt)
        answer = nums.size() / 2;
    else
        answer = cnt;
        
}

int main()
{
    return 0;
}