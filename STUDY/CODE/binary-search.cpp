#include <iostream>
#include <vector>
using namespace std;


int binary_search(vector<int>& array, int target)
{
    int start = 0;
    int end = array.size() - 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if (array[mid] == target) 
        {
            return mid;
        }
        else if (array[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    
    return -1;
    
}

int main()
{
    vector<int> array = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target = 9;

    cout << "찾으려는 값의 인덱스는 " <<binary_search(array, target) <<"입니다"<< endl;



}