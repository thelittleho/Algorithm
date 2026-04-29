#include <iostream>
using namespace std;

bool adj_matrix[10][10], visited[10];

const int row = sizeof(adj_matrix) / sizeof(adj_matrix[0]);
const int col = sizeof(adj_matrix[0]) / sizeof(adj_matrix[0][0]);

void iter_print(bool adj_matrix[][col])
{
    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            cout << " |" << adj_matrix[i][j] << "| ";
        }

        cout << endl;
        
    }

}

// 0번부터 방문안한 노드를 찾고 해당 노드부터 방문하고 연결된 노드를 이어서 출력하는 재귀함수 구현
void solve(int from)
{
    visited[from] = 1;
    cout << from << endl;

    for (int i = 0; i < col; i++)
    {
        if (visited[i]) continue;

        if (adj_matrix[from][i])
        {
            solve(i);
        }
        
        
    }
    
}

int main()
{
    // 1-2 | 1-3 | 3-4라는 경로 발생
    adj_matrix[1][2] = 1; adj_matrix[2][1] = 1;
    adj_matrix[1][3] = 1; adj_matrix[3][1] = 1;
    adj_matrix[3][4] = 1; adj_matrix[4][3] = 1;

    iter_print(adj_matrix);
    cout<< "---------------------------------------------" << endl;
    solve(1);

    return 0;

}