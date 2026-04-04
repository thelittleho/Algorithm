#include <iostream>
#include <vector>
#include <random> // 랜덤 라이브러리
#include <ctime> // 시간 정보
#include <algorithm>

using namespace std;

void quick_sort(vector<int>& array, int start, int end)
{
    if (start >= end) return;

    int pivet = start;
    int low  = start + 1;
    int high = end;

    while (low <= high)
    {
        while (low <= end and array[low] <= array[pivet])
        {
            low++;
        }
        while (high > start and array[high] > array[pivet])
        {
            high--;
        }

        if (low < high)
        {
            swap(array[low], array[high]);
        }
        
        
    }

    swap(array[pivet], array[high]);

    quick_sort(array, start, high-1);
    quick_sort(array, high+1, end);
}

int main()
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> range_dist(7, 14);
    uniform_int_distribution<int> value_dist(1, 50);

    int array_range = range_dist(gen);
    vector<int> array;

    for (int i = 0; i < array_range; ++i)
    {
        array.push_back(value_dist(gen));
    }
    
    cout << "생성된 배열의 크기 : " << array_range << endl;
    cout << "배열원소 : |";

    for (int num : array)
    {
        cout << num << "|";
    }
    cout << endl;

    quick_sort(array, 0, array_range-1);

    cout << "정렬 이후의 원소 : |";

    for (int num : array)
    {
        cout << num << "|";
    }
    cout << endl;

    return 0;
}