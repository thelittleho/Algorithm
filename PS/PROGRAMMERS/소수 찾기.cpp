#include <string>
#include <set>
#include <algorithm>
#include <math.h>

using namespace std;

bool isPrime(int n)
{
    // 2미만 소수는 없다.
    if(n < 2)
        return false;
    
    // 2부터 n의 제곱근까지 소수 검사
    for(int i = 2; i <= sqrt(n); ++i)
    {
        if(n%i == 0)
            return false;
    }
    
    return true;
}


int solution(string numbers) {
    int answer = 0;
    set<int>ans{};
    
    // 입력 문자열 정렬
    sort(numbers.begin(), numbers.end());

    
    // numbers 순열의 첫번째 문자부터 문자를 누적해가며 소수인지 비교한다. 
    do
    {
        string tmp;
        for(int i = 0; i < numbers.size(); ++i)
        {
            tmp += numbers[i];
            if(isPrime(stoi(tmp))) 
                ans.insert(stoi(tmp));      // set이므로 소수인 숫자 조합들을 중복없이 담는다.
        }
    }
    while(next_permutation(numbers.begin(), numbers.end()));
     
    answer = ans.size();
        
    return answer;
}