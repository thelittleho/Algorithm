#include <vector>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = 0;
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (k >= dungeons[i][0] && k - dungeons[i][1] >= 0)
        {
            answer += 1;
            k -= dungeons[i][1];
        }
        
    }
    
    return answer;
}