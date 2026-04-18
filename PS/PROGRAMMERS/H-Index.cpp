#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator> // distance 함수를 쓰기 위해 필요

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    // 1. 오름차순 정렬 (0, 1, 3, 5, 6)
    sort(citations.begin(), citations.end());

    int max_val = *max_element(citations.begin(), citations.end());

    // 2. h 후보군을 0부터 최댓값까지 검사
    for (int h = 0; h <= max_val; h++) {
        int i;
        for (i = 0; i < citations.size(); i++) {
            if (h <= citations[i]) {
                break; // h번 이상 인용된 논문이 시작되는 위치(i) 찾기
            }
        }

        // h번 이상 인용된 논문의 개수: 전체 크기 - i
        int count_over_h = citations.size() - i;
        // h번 미만 인용된 논문의 개수: i
        int count_under_h = i;

        // 의도하신 조건: h번 이상 인용된 논문이 h개 이상이고, 나머지가 h개 이하인가?
        if (count_over_h >= h && count_under_h <= h) {
            answer = h; // 조건을 만족하는 가장 큰 h가 저장됨
        }
    }

    return answer;
}

int main() {
    vector<int> citations = {3, 0, 6, 1, 5};
    int h = solution(citations);

    cout << "H-Index: " << h << endl; // 결과: 3
    return 0;
}