# 🔄 C++ STL 반복자(Iterator) 완벽 가이드

반복자는 **데이터 구조의 추상화**입니다. 내부 구조(배열, 리스트 등)에 상관없이 **포인터와 유사한 방식(`it++`, `*it`)**으로 컨테이너를 균일하게 다룰 수 있게 해주는 "일반화된 포인터"입니다.

---

## 1. 반복자의 핵심 개념
- **인터페이스 통합**: 배열의 `ptr++`와 연결 리스트의 `node = node->next`를 `it++`라는 동일한 문법으로 통합합니다.
- **알고리즘의 다리**: STL 알고리즘(sort, find 등)은 컨테이너가 아닌, 반복자가 제공하는 **[시작, 끝)** 범위를 보고 작동합니다.
- **반복자 범위**: STL의 모든 범위는 반개방 범위인 **[begin, end)**를 따릅니다. `end()`는 마지막 원소가 아니라 **마지막 원소의 다음 지점**을 가리킵니다.

---

## 2. 반복자의 5가지 종류 및 특징

| 반복자 종류 | 읽기/쓰기 | 이동 (증감) | 접근/연산 | 관련 컨테이너 및 예시 |
| :--- | :---: | :---: | :---: | :--- |
| **입력 (Input)** | 읽기 전용 | `++` | ❌ | `istream_iterator` |
| **출력 (Output)** | 쓰기 전용 | `++` | ❌ | `ostream_iterator`, `back_inserter` |
| **순방향 (Forward)** | 읽기/쓰기 | `++` | ❌ | `forward_list` |
| **양방향 (Bidirectional)** | 읽기/쓰기 | `++`, `--` | ❌ | `list`, `set`, `map` |
| **임의 접근 (Random Access)** | 읽기/쓰기 | `++`, `--` | `[]`, `+`, `-`, `+=`, `-=` | **일반 포인터**, `vector`, `deque` |

---

## 3. 코드 예제로 보는 기초 활용

### ① 포인터와 반복자의 관계 (배열 예제)
```cpp
int ari[] = {1, 2, 3, 4, 5};
int* it;

// &ari[0]는 begin, &ari[5]는 end 역할 (반개방 범위)
for (it = &ari[0]; it != &ari[5]; it++) {
    printf("%d\n", *it);
}

### ② 벡터와 반복자 표준 사용법

```cpp
vector<int> vi = {1, 2, 3, 4, 5};
vector<int>::iterator it; // 반복자 선언

for (it = vi.begin(); it != vi.end(); it++) {
    printf("%d\n", *it);
}
```

## 4. 실전 심화 개념 (중요!)
### ① 반복자 무효화 (Iterator Invalidation) ⚠️
컨테이너의 구조가 변하면 기존 반복자를 사용할 수 없게 되는 현상입니다.

- **원인**: vector에서 push_back() 시 메모리 재할당이 일어나면 기존 주소가 바뀜.

- **대응**: 원소 삽입/삭제 후에는 반드시 반복자를 새로 할당받아야 합니다.

### ② 특수 반복자 (역방향 & 상수형)
- **역방향** (reverse_iterator): rbegin(), rend()를 사용하며 ++ 시 인덱스가 감소하는 방향으로 이동합니다.

- **상수형** (const_iterator): 원소 수정을 방지하며, const 컨테이너를 다룰 때 필수입니다.

## 5. Modern C++ & <iterator> 헤더 활용

### ① Modern C++ 팁
auto 키워드를 쓰면 복잡한 반복자 타입을 일일이 적지 않아도 됩니다.
```Cpp

// 1. auto 활용
for (auto it = v.begin(); it != v.end(); ++it) { ... }

// 2. 범위 기반 for 루프 (가장 권장됨)
for (const auto& element : v) { cout << element; }
```

### ② <iterator> 헤더의 유용한 도구
기본 반복자 외에 알고리즘의 효율을 높여주는 도구들입니다.

- **삽입 반복자**: `back_inserter()` (공간을 늘리며 push_back 수행)

- **스트림 반복자**: `ostream_iterator<int>(cout, ", ")` (데이터를 즉시 출력)

- **연산 함수**: `std::advance(it, n)`, `std::distance(it1, it2)`

### ③ 실전: std::copy와 출력 반복자 활용

```cpp

#include <iterator>
#include <algorithm>

vector<int> v = {1, 2, 3, 4, 5};
// 루프 없이 벡터의 모든 원소를 ", "와 함께 출력
copy(v.begin(), v.end(), ostream_iterator<int>(cout, ", "));
```