#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void quick_(vector<int>& array, int start, int end)
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

    quick_(array, start, high-1);
    quick_(array, high + 1, end);
}

int main()
{
    int n, number;
    vector<int> will_;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> number;
        will_.push_back(number);
    }

    quick_(will_, 0, will_.size() - 1);

    for (int value : will_)
    {
        cout << value << endl;
    }
    
    
}