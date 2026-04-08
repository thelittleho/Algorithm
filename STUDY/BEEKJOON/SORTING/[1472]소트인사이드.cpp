#include <iostream>
#include <vector>

using namespace std;

// Tester Code
void print(const vector<int>& array) {
    // i를 마지막 인덱스부터 시작해서 0이 될 때까지 줄여나감
    for (int i = array.size() - 1; i >= 0; i--) 
    {
        cout << array[i];
    }
    cout << endl;
}

// vector를 새로 만들지 않고 tmp 배열을 인자로 받음
void _merge(vector<int>& array, vector<int>& tmp, int start, int mid, int end)
{
    int left = start; 
    int right = mid + 1; 
    int k = start; // 인덱스를 0이 아니라 start부터 시작하면 더 편해요.

    while (left <= mid && right <= end)
    {
        if (array[left] <= array[right]) tmp[k++] = array[left++];
        else tmp[k++] = array[right++];
    }

    // 아까 헷갈리셨던 조건문도 여기서 바로잡을게요!
    while (left <= mid) tmp[k++] = array[left++];
    while (right <= end) tmp[k++] = array[right++];

    // 복사할 때도 원래 범위만큼만
    for (int i = start; i <= end; i++)
    {
        array[i] = tmp[i];
    }
}

void merge_sort(vector<int>& array, vector<int>& tmp, int start, int end)
{
    if (start >= end) return;
    
    int mid = start + (end - start) / 2;

    merge_sort(array, tmp, start, mid);
    merge_sort(array, tmp, mid + 1, end);

    _merge(array, tmp, start, mid, end);
}

int main()
{
    vector<int> array;
    
    long long input;

    cin >> input;

    if (input == 0) array.push_back(0);

    while (input > 0)
    {
        array.push_back(input % 10); // 마지막 자릿수 추출
        input /= 10;
    }

    vector<int> tmp(array.size()); 
    
    int start = 0;
    int end = array.size() - 1;

    merge_sort(array, tmp, start, end); // tmp를 같이 넘겨줌

    print(array);
    return 0;
    
}