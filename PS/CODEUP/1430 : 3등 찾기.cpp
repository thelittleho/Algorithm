#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void bubble_sort(string* name, int* grade, int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
        {
            if (grade[j] > grade[j+1])
            {
                // swap_grade_ver.
                swap(grade[j], grade[j+1]);

                // swap_name_ver
                swap(name[j], name[j+1]);

            }
            
        }
        
    }
    
}

int main()
{
    int n;
    string name[51]; int grade[51] = {0, };

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> name[i] >> grade[i];
    }

    bubble_sort(name, grade, n);

    cout << name[(n-1)-2] << endl;
    
}