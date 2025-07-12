from typing import MutableSequence

def bubble_sort( a : MutableSequence ) -> MutableSequence:
    n = len(a)

    for i in range(n-1, 0 , -1):
        for j in range(i):
            if a[j] >  a[j+1]:
                a[j], a[j+1] = a[j+1], a[j]
    
    return a


N = int(input())
a = [None]*N

for i in range(N):
    a[i] = int(input())


bubble_sort(a)

for i in a:
    print(i)

