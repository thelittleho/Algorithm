#include <iostream>
#include <algorithm>
#include <vector>

#include <random>
#include <ctime>

using namespace std;

void _merge(vector<int>& array, int start, int mid, int end)
{
    int i = start; // 왼쪽 덩어리의 시작
    int j = mid + 1; // 오른쪽 덩어리의 시작
    int k = 0;  // 임시 배열의 인덱스

    vector<int> sorted(end - start + 1);

    while (i <= mid && j <= end)
    {
        if (array[i] <= array[j])
        {
            sorted[k++] = array[i++];
        }
        else
        {
            sorted[k++] = array[j++];
        }
    }
    
    while (i <= mid)
        {
            sorted[k++] = array[i++];
        }

    while (j <= end)
        {
            sorted[k++] = array[j++];
        }
    
    for (int l = 0; l < sorted.size(); l++) 
    {
        array[start + l] = sorted[l];
    }
    
}

void merge_sort(vector<int>& array, int start, int end)
{
    if (start >= end) return;

    int mid = (start + end) / 2;

    merge_sort(array, start, mid);
    merge_sort(array, mid + 1, end);

    _merge(array, start, mid, end);
    
}

void print(const vector<int>& array) {
    cout << "배열 원소 : |";
    for (int num : array) {
        cout << num << "|";
    }
    cout << endl;
}

int main()
{
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<int> range_dist(7, 14);
    uniform_int_distribution<int> value_dist(1, 50);

    int array_range = range_dist(gen);
    vector<int> array;

    for (int i = 0; i < array_range; i++)
    {
        array.push_back(value_dist(gen));
    }
    
    print(array);
    merge_sort(array, 0, array_range-1);
    print(array);
}