# 질문
`퀵 정렬은 불안정 정렬 에 속하며, 다른 원소와의 비교만으로 정렬을 수행하는 비교 정렬 에 속한다.`    
→ 불안정 정렬    
중복된 값이 입력 순서와 동일하지 않게 정렬되는 알고리즘   
→ 안정 정렬  
중복된 값을 입력 순서와 동일하게 정렬하는 알고리즘
`합병 정렬(merge sort)과 달리 퀵 정렬은 리스트를 비균등하게 분할한다.`    
→ 퀵 정렬은 어떻게 **비균등히 분할**하고 합병정렬은 어떻게 **균등**하게 분할하는가?

```python
[('대구', 1400), ('순천', 1500), ('대구', 1430), ('부산', 1300), ('목포', 1400), ('대구', 1500)]
```
여기 예시에서 안정 정렬은 시간(입력) 순서대로 정렬하는 반면
```python
[('대구', 1400), ('대구', 1430), ('대구', 1500), ('목포', 1400), ('부산', 1300), ('순천', 1500)]
```
불안정 정렬은 그렇지 못하다.


# 퀵 정렬 알고리즘의 구체적인 개념

첫번째 리스트를 피벗으로 성정해 두 개의 비균등(균등할 수도 있음)한 크기로 분할하고 분할된 부분의 리스트를 정렬한 다음, 두 개의 정렬된 부분 리스트를 합해 전체가 정렬된 리스트를 제시한다.

- 퀵 정렬은 다음의 단계로 구성된다.
  - **분할(Divide)**: 입력 배열을 피벗을 기준으로 비균등하게 2개의 부분 배열 (피벗을 중심으로 왼쪽:피벗보다 작은 요소들, 오른쪽:피벗보다 큰 요소들)로 분할한다.
  - **정복(Conquer)**: 부분 배열을 정렬한다. 부분 배열의 크기가 충분히 작지 않으면 순환 호출을 이용하여 다시 분할 정복 방법을 적용한다.
  - **결합(Conbine)**: 정렬된 부분 배열을 하나의 배열에 합병한다.
 
  - 순환 호출이 한 번 진행될 때마다 최소한 하나의 원소(피벗)는 최종적으로 위치가 정해지므로, 이 알고리즘은 반드시 끝난다는 보장 가능

<img width="2300" height="3287" alt="quick-sort2" src="https://github.com/user-attachments/assets/06219e7f-cae4-435e-a466-7ca31fcc8b1d" />


# python/C++ 퀵정렬 구현 방법
```python
import random 

array = []
array_range = random.randint(7, 14)
for i in range(array_range):
    array.append(random.randint(1, 50))

print("정렬 전:", array)

# 리스트의 처음(0)부터 끝(len-1)까지를 대상으로 퀵 정렬 시작
quick_sort(array, 0, len(array) - 1)

print("정렬 후:", array)

```
- 먼저 우리는 무작위로 생성된 리스트를 정리하는 것이므로 `7개에서 14개의 크기`를 갖는 리스트를 생성하고 각각의 인덱스에 `1~50까지의 양수`를 입력한다. 
- 확인을 위해 정렬 전 리스트를 출력한다.
- `quick_sort`에 리스트의 정렬하고 싶은 범위(start~end)를 입력한다.
- 정렬 후의 리스트를 출력한다.

```python
def quick_sort(array, start, end):
    # [탈출 조건] 원소가 1개 이하인 경우 더 이상 쪼갤 필요가 없으므로 종료
    if start >= end:
        return
    
    pivot = start
    low = start + 1
    high = end
    
    while low <= high:
        # low는 피벗보다 큰 값을 찾을 때까지 전진 (리스트 범위 초과 방지 조건 추가)
        while low <= end and array[low] <= array[pivot]:
            low += 1
            
        # high는 피벗보다 작은 값을 찾을 때까지 전진 (리스트 범위 초과 방지 조건 추가)
        while high > start and array[high] > array[pivot]:
            high -= 1
            
        if low < high:
            array[low], array[high] = array[high], array[low]

    # 분할이 끝나면 피벗과 high(피벗보다 작은 그룹의 마지막) 교체
    array[pivot], array[high] = array[high], array[pivot]
    
    # 2. [핵심] 분할된 좌항과 우항에 대해 자기 자신을 다시 호출 (재귀)
    # 현재 high의 위치에는 피벗이 들어가서 확정되었으므로, 그 양옆을 다시 정렬합니다.
    quick_sort(array, start, high - 1) # 좌항 정렬
    quick_sort(array, high + 1, end)   # 우항 정렬
```

```python
if start >= end:
        return
```
- `start < end`인 경우
적어도 2개 이상의 원소가 존재하기에 퀵소트가 가능하다.
- `start == end`인 경우
1개의 원소가 존제하기 때문에 퀵소트가 필요없다. (종료조건)
- `start > end`
모든 원소가 정렬되었기에 퀵소트가 필요없다. (종료조건)    

`종료조건`을 걸어두지 않으면 start 포인터와 end 포인터가 서로 넘어서 무한히 재귀하기에 종료조건을 걸어야한다.