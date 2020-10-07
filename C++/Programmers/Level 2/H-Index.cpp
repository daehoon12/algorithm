#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size(); i++)
    {
        int cnt = 0;
        for (int j = i; j < citations.size(); j++)
        {
            if (citations[i] <= citations[j])
                cnt++;
        }
        if (citations[i] <= cnt)
            answer = citations[i];
    }
    return answer;

}
