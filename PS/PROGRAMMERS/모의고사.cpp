#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 1. 각 수포자의 패턴 정의
    vector<vector<int>> patterns = {
        {1, 2, 3, 4, 5},
        {2, 1, 2, 3, 2, 4, 2, 5}, 
        {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
    };

    // 2. 점수를 저장할 배열 (3명)
    vector<int> scores(3, 0);

    // 3. 정답지와 각 패턴을 비교
    for (int i = 0; i < answers.size(); i++) {
        for (int j = 0; j < patterns.size(); j++) {
            // 핵심: 현재 문제 인덱스(i)를 패턴의 크기로 나눈 나머지가 학생의 답입니다.
            if (answers[i] == patterns[j][i % patterns[j].size()]) {
                scores[j]++;
            }
        }
    }

    // 4. 가장 높은 점수 찾기
    int max_score = *max_element(scores.begin(), scores.end());

    // 5. 최고 득점자(들)를 answer에 담기
    for (int i = 0; i < 3; i++) {
        if (scores[i] == max_score) {
            answer.push_back(i + 1); // 학생 번호는 1번부터 시작
        }
    }

    return answer;
}