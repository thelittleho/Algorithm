# 소수 판별 알고리즘(with Big-O)

1. [$O(N)$의 알고리즘](#의-알고리즘)
2. [$O(\sqrt{N})$의 알고리즘](#의-알고리즘-1)
3. [$O(N\log(\log N))$의 알고리즘](#의-알고리즘-2)

- 소수의 조건    
소수는 **1과 자기자신**을 제외한 약수를 갖지않는 1보다 큰 자연수를 말한다.

# $O(N)$의 알고리즘
가장 간단하지만 가장 시간이 오래걸리는 알고리즘이다.    
우리가 일반적으로 생각했을 때 소수를 판별하는 방법(알고리즘)은 무엇인가?    
2부터 우리가 소수인지 확인하려 구하려는 수 앞까지 하나하나 수를 불러와 해당하는 수와 나누고 나머지가 존재하는 지 여부를 확인하면 된다.    

```cpp
bool isPrime(int n) {
	for (int i = 2; i < n; i++) {
		if (n%i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
			return false;
		}
	}
	//2 ~ n-1까지 약수가 없다면 소수이므로, true return
	return true;
}
```
위 코드의 단점은 하나하나 약수인지 확인하는 방법이기 때문에 너무 큰 수를 넣으면 오랜시간이 걸린다는 점이다.
# $O(\sqrt{N})$의 알고리즘
> n의 약수는 무조건 1 ~ $\sqrt{n}$의 범위에 존재한다.

- 소수인지를 확인할 숫자 n의 제곱근 $\sqrt{n}$의 기준으로 약수끼리의 곱은 대칭이다.
- 그렇기에 $\sqrt{n}$이하의 작은 값만 검사하면 나머지는 필요가 없다.

$n = 8$    
$\quad (1 \times 18) \quad (2 \times 9) \quad (3 \times 6) \quad$ `√18 = 4.242` $\quad (3 \times 6) \quad (9 \times 2) \quad (18 \times 1) \quad$    

```cpp
#include <cmath>

bool isPrime(int n) {
	for (int i = 2; i <= sqrt(n); i++) {//2~n의 제곱근까지
		if (n%i == 0) {//i가 n의 약수라면 소수가 아니므로 false return
			return false;
		}
	}
	//2 ~ n-1까지 약수가 없다면 소수이므로, true return
	return true;
}
```
# $O(N\log(\log N))$의 알고리즘
위의 방법도 결국 수가 커지면 $O(\sqrt{N})$도 커지기 때문에 훨씬 효율적인 방법을 찾아야한다.    
정수론에는 여러가지가 있지만 대표적으로 `에라토스테네스의 체`가 존재한다.     
에라토스테네스의 체에서 사용하는 원리는 다음과 같다 :    
**해당 수가 소수라면, 해당 수의 배수들은 모두 해당 수를 약수로 가지고 있으므로 소수가 되지 못한다.**    
말로는 상당히 힘든 부분이니 예를 들어 설명한다.    
2 ~ 50까지의 수에서 소수를 구해야한다.     
먼저, 소수가 아닌 1을 제외시킨다. 소수 아닌 수는 빨간 색 소수인 수는 파란색으로 체크를 한다.
| | | | | | | | | | |
|---|---|---|---|---|---|---|---|---|---|
| <span style="color:red">1| 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 |
| 11 | 12 | 13 | 14 | 15 | 16 | 17 | 18 | 19 | 20 |
| 21 | 22 | 23 | 24 | 25 | 26 | 27 | 28 | 29 | 30 |
| 31 | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 | 40 |
| 41 | 42 | 43 | 44 | 45 | 46 | 47 | 48 | 49 | 50 |   

소수의 조건은 2 이상이 되는 자연수이기 때문에 1을 제외하고 시작한다.   

| | | | | | | | | | |
|---|---|---|---|---|---|---|---|---|---|
| <span style="color:red">1| <span style="color:blue">2 | 3 | <span style="color:red">4 | 5 | <span style="color:red">6 | 7 | <span style="color:red">8 | 9 | <span style="color:red">10 |
| 11 | <span style="color:red">12 | 13 | <span style="color:red">14 | 15 | <span style="color:red">16 | 17 | <span style="color:red">18 | 19 | <span style="color:red">20 |
| 21 | <span style="color:red">22 | 23 | <span style="color:red">24 | 25 | <span style="color:red">26 | 27 | <span style="color:red">28 | 29 | <span style="color:red">30 |
| 31 | <span style="color:red">32 | 33 | <span style="color:red">34 | 35 | <span style="color:red">36 | 37 | <span style="color:red">38 | 39 | <span style="color:red">40 |
| 41 | <span style="color:red">42 | 43 | <span style="color:red">44 | 45 | <span style="color:red">46 | 47 | <span style="color:red">48 | 49 | <span style="color:red">50 |    

다음 수인 2를 살펴보자 2는 당연히 1과 자기자신을 약수로 가지므로 소수이다.    
추가적으로 2의 배수인 수는 모두 **최소한** 2를 약수로 가지기 때문에 배제한다.
| | | | | | | | | | |
|---|---|---|---|---|---|---|---|---|---|
| <span style="color:red">1| <span style="color:blue">2 | <span style="color:blue">3 | <span style="color:red">4 | 5 | <span style="color:red">6 | 7 | <span style="color:red">8 | <span style="color:red">9 | <span style="color:red">10 |
| 11 | <span style="color:red">12 | 13 | <span style="color:red">14 | <span style="color:red">15 | <span style="color:red">16 | 17 | <span style="color:red">18 | 19 | <span style="color:red">20 |
| <span style="color:red">21 | <span style="color:red">22 | 23 | <span style="color:red">24 | 25 | <span style="color:red">26 | <span style="color:red">27 | <span style="color:red">28 | 29 | <span style="color:red">30 |
| 31 | <span style="color:red">32 | <span style="color:red">33 | <span style="color:red">34 | 35 | <span style="color:red">36 | 37 | <span style="color:red">38 | <span style="color:red">39 | <span style="color:red">40 |
| 41 | <span style="color:red">42 | 43 | <span style="color:red">44 | <span style="color:red">45 | <span style="color:red">46 | 47 | <span style="color:red">48 | 49 | <span style="color:red">50 |

다음 3을 알아보자, 3은 1, 3을 약수로 가지기에 소수이고,    
3의 배수 또한 배제한다.    

| | | | | | | | | | |
|---|---|---|---|---|---|---|---|---|---|
| <span style="color:red">1| <span style="color:blue">2 | <span style="color:blue">3 | <span style="color:red">4 | <span style="color:blue">5 | <span style="color:red">6 | 7 | <span style="color:red">8 | <span style="color:red">9 | <span style="color:red">10 |
| 11 | <span style="color:red">12 | 13 | <span style="color:red">14 | <span style="color:red">15 | <span style="color:red">16 | 17 | <span style="color:red">18 | 19 | <span style="color:red">20 |
| <span style="color:red">21 | <span style="color:red">22 | 23 | <span style="color:red">24 | <span style="color:red">25 | <span style="color:red">26 | <span style="color:red">27 | <span style="color:red">28 | 29 | <span style="color:red">30 |
| 31 | <span style="color:red">32 | <span style="color:red">33 | <span style="color:red">34 | <span style="color:red">35 | <span style="color:red">36 | 37 | <span style="color:red">38 | <span style="color:red">39 | <span style="color:red">40 |
| 41 | <span style="color:red">42 | 43 | <span style="color:red">44 | <span style="color:red">45 | <span style="color:red">46 | 47 | <span style="color:red">48 | 49 | <span style="color:red">50 |    

5 또한 약수이고 5의 배수도 진행한다.

| | | | | | | | | | |
|---|---|---|---|---|---|---|---|---|---|
| <span style="color:red">1| <span style="color:blue">2 | <span style="color:blue">3 | <span style="color:red">4 | <span style="color:blue">5 | <span style="color:red">6 | <span style="color:blue">7 | <span style="color:red">8 | <span style="color:red">9 | <span style="color:red">10 |
| 11 | <span style="color:red">12 | 13 | <span style="color:red">14 | <span style="color:red">15 | <span style="color:red">16 | 17 | <span style="color:red">18 | 19 | <span style="color:red">20 |
| <span style="color:red">21 | <span style="color:red">22 | 23 | <span style="color:red">24 | <span style="color:red">25 | <span style="color:red">26 | <span style="color:red">27 | <span style="color:red">28 | 29 | <span style="color:red">30 |
| 31 | <span style="color:red">32 | <span style="color:red">33 | <span style="color:red">34 | <span style="color:red">35 | <span style="color:red">36 | 37 | <span style="color:red">38 | <span style="color:red">39 | <span style="color:red">40 |
| 41 | <span style="color:red">42 | 43 | <span style="color:red">44 | <span style="color:red">45 | <span style="color:red">46 | 47 | <span style="color:red">48 | <span style="color:red">49 | <span style="color:red">50 |

7도 동일하게 진행한다.

| | | | | | | | | | |
|---|---|---|---|---|---|---|---|---|---|
| <span style="color:red">1| <span style="color:blue">2 | <span style="color:blue">3 | <span style="color:red">4 | <span style="color:blue">5 | <span style="color:red">6 | <span style="color:blue">7 | <span style="color:red">8 | <span style="color:red">9 | <span style="color:red">10 |
| <span style="color:blue">11 | <span style="color:red">12 | <span style="color:blue">13 | <span style="color:red">14 | <span style="color:red">15 | <span style="color:red">16 | <span style="color:blue">17 | <span style="color:red">18 | <span style="color:blue">19 | <span style="color:red">20 |
| <span style="color:red">21 | <span style="color:red">22 | <span style="color:blue">23 | <span style="color:red">24 | <span style="color:red">25 | <span style="color:red">26 | <span style="color:red">27 | <span style="color:red">28 | <span style="color:blue">29 | <span style="color:red">30 |
| 31 | <span style="color:red">32 | <span style="color:red">33 | <span style="color:red">34 | <span style="color:red">35 | <span style="color:red">36 | <span style="color:blue">37 | <span style="color:red">38 | <span style="color:red">39 | <span style="color:red">40 |
| 41 | <span style="color:red">42 | <span style="color:blue">43 | <span style="color:red">44 | <span style="color:red">45 | <span style="color:red">46 | <span style="color:blue">47 | <span style="color:red">48 | <span style="color:red">49 | <span style="color:red">50 |

이후 나머지 수는 소수이므로 모두 소수로 표시하고 과정은 종료된다.

```cpp
void isPrime(int n) // 2 ~ n까지의 소수들을 구한다.
{
	bool *isPrime = new bool[n+1]; 

	for(int i=0; i <= n; i++) // 모든 배열을 true로 초기화
	{
		isPrime[i] = true;
	}

	for(int i=2; i <= n; i++)
	{
		if(isPrime[i])
		{
			cout << i << " ";

			for(int j= i * 2; j <= n; j += i)
			{
				isPrime[j] = false;
			}
		}
	}

}

```

# REFERENCE

- [[알고리즘] 소수판별 알고리즘 C++](https://khu98.tistory.com/227#google_vignette)

