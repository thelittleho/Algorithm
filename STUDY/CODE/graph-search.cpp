#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(int start, vector<int> adj[], bool visited[])
{
    queue<int> q;

    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 0; i < adj[x].size(); i++)
        {
            int y = adj[x][i];
            if (!visited[y])
            {
                q.push(y);
                visited[y] = true;
            }   
        }
    }
    
}

int main()
{
    int n =  7;
    vector<int> adj[8];
    bool visited[8] = {false, };

    // 그래프 관계

    // 1번 노드 자식
    adj[1].push_back(2);
    adj[1].push_back(3);

    // 2번 노드 자식
    adj[2].push_back(4);
    adj[2].push_back(5);

    // 3번 노드 자식
    adj[3].push_back(6);
    adj[3].push_back(7);

    cout << "BFS 탐색 결과 :";
    bfs(1, adj, visited);
    cout << endl;

    return 0;


}