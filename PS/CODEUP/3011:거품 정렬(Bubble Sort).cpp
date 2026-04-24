#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dubble_sort(vector<int>& array, int start, int end)
{
    int step;

    for (int i = start; i < end - 1; i++)
    {
        for (int j = 0; j < end - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                swap(array[j], array[j+1]);
                step += 1;
            }
        }
        
    }
    


    return step;
}

int main()
{
    int n, number, step;
    vector<int> array;

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> number;
        array.push_back(number);
    }

    cout << dubble_sort(array, 0, array.size()-1);
    
}