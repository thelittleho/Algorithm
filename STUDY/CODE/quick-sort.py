import random

# 1. 분할과 정렬을 함께 수행하는 퀵 정렬 함수
def quick_sort(array, start, end):
    # [탈출 조건] 원소가 1개 이하인 경우 더 이상 쪼갤 필요가 없으므로 종료
    if start >= end:
        return
    
    pivot = start
    low = start + 1
    high = end
    
    # [방금 전까지 만들었던 파티션 로직]
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

# --- 실행 부분 ---
array = []
array_range = random.randint(7, 14)
for i in range(array_range):
    array.append(random.randint(1, 50))

print("정렬 전:", array)

# 리스트의 처음(0)부터 끝(len-1)까지를 대상으로 퀵 정렬 시작
quick_sort(array, 0, len(array) - 1)

print("정렬 후:", array)