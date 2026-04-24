#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick_sort(vector<int>& array, int start, int end)
{
    if (start >= end) return;

    int pivet = start;
    int low = start + 1;
    int high = end;

    while (low <= high)
    {
        while (low <= end && array[low] <= array[pivet]) low++;
        while (high > start && array[high] > array[pivet]) high--;

        if (low < high) swap(array[low], array[high]);
    }
    
    swap(array[pivet], array[high]);

    quick_sort(array, start, high-1);
    quick_sort(array, high + 1, end);
}

int main()
{
    int n, number;
    vector<int> will_sort;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> number;
        will_sort.push_back(number);
    }

    quick_sort(will_sort, 0, will_sort.size() - 1);

    for (int value : will_sort)
    {
        cout << value << endl;
    }
    
    
}