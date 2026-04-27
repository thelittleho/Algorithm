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
    vector<int> array;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> number;
        array.push_back(number);
    }

    quick_sort(array, 0, array.size()-1); 

    for (int i = n-1; i >= 0; i--)
    {
        cout << array[i] << " ";
    }

    cout << endl;
    


}