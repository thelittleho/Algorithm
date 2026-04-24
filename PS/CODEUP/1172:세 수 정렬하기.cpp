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
    int a, b, c;
    vector<int> array;

    cin >> a >> b >> c;

    array.push_back(a);
    array.push_back(b);
    array.push_back(c);

    quick_sort(array, 0, array.size()-1);

    for (int value : array)
    {
        cout << value << " ";
    }
    


}