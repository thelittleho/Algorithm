#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    vector<int> width, length;

    for (int i = 0; i < sizes.size(); i++)
    {
        if (sizes[i][0] < sizes[i][1])
        {
            swap(sizes[i][0], sizes[i][1]);
        }
    }

    for (int i = 0; i < sizes.size(); i++)
    {
        width.push_back(sizes[i][0]);
        length.push_back(sizes[i][1]);
    }

    answer = (*max_element(width.begin(), width.end())) * (*max_element(length.begin(), length.end()));
    
    
    return answer;
}