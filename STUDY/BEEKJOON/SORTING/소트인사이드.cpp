#include <iostream>
#include <vector>

using namespace std;

// Tester Code
void print(const vector<int>& array) {
    cout << "|";
    for (int num : array) 
    {
        cout << num << "|";
    }
    cout << endl;
}

void _merge(vector<int>& array, int start, int mid, int end)
{
    // not finish
}

void merge_sort(vector<int>& array, int start, int end)
{
    // not finish
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



    print(array);


    return 0;
    
}