import random

array = []
array_range = random.randint(7, 14)

for i in range(0, array_range):
    number = random.randint(1, 50)
    array.append(number)

print(array)

# pivot을 리스트의 0으로 설정
pivot = 0
# low = 1, high = len(array)로 설정해 오름차순에 맞지않으면 맞도록 교환
low = 1
high = len(array) - 1

print(array[pivot])

while(low < high): # low가 high보다 인덱스 번호가 클 때 교환 작업을 종료
    if array[low] < array[pivot]:
        low += 1
    if array[high] > array[pivot]:
        high -= 1
    if array[low] > array[high]:
        array[low], array[high] = array[high], array[low]
    low += 1
    high -= 1    

# 그리고 high와 pivet과 교체
array[pivot], array[high] = array[high], array[pivot]

print(array)

# 0부터 high까지 퀵 정렬, high부터 끝까지 퀵정렬을 시행한다.
