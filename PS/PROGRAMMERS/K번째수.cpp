#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int x = 0; x < commands.size(); x++) // x를 제어 변수로 통일
    {
        // 1. i, j, k 값 설정 (인덱스 보정을 위해 -1 처리 고민 필요)
        int i = commands[x][0];
        int j = commands[x][1];
        int k = commands[x][2];

        // 2. 필요한 범위만 복사하여 새로운 벡터 생성
        // array의 i-1번째부터 j번째 앞까지 복사
        vector<int> will_sort;
        for (int m = i - 1; m < j; m++) {
            will_sort.push_back(array[m]);
        }

        // 3. 올바른 반복자를 사용하여 정렬
        sort(will_sort.begin(), will_sort.end());

        // 4. k번째 수 추출
        answer.push_back(will_sort[k - 1]);
    }
        

    return answer;
    
    
}

int main()
{
    
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};

    vector<vector<int>> commands =
    {
        {2, 5, 3},
        {4, 4, 1},
        {1, 7, 3}
    };

    for (int i : solution(array, commands))
    {
        cout << i ;
    }
    

}