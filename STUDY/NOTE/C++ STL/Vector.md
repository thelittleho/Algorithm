# vector
## vector란?
**vector**는 C++ STL의 시퀀스 컨테이너로, 동적으로 크기를 조절할 수 있는 배열을 제공하며 요소들을 연속된 메모리 공간에 저장한다.

다양한 상황에서 유용하게 쓰이는 컨테이너이며, 특히 **동적 배열이 필요할 때** 매우 유용하다.

## vector의 특징
- **동적 크기 조절**
- **임의 접근**
- **연속적인 메모리 할당**
- **효율적인 끝 요소 추가 및 삭제**
- **템플릿 클래스** : 템플릿 클래스이므로, 모든 데이터 타입을 사용가능하다.

## vector의 단점
배열의 일종이기 때문에, **중간에 요소를 삽입하거나 제거하는 작업부분에서는 상당히 느리다.**

## vector의 헤더파일 및 사용

```cpp
#include <string>
#include <vector>

int main()
{
    vector<string> str = {'Hello', 'world'};

    vector<int> num = {0, 1, 5, 6};

    vector<int> empvect;
}
```
