#include <iostream>
#include <vector>

using namespace std;

vector<int> adj[6];
int visited[6];

void DFS(int u) // u는 시작점(From)
{
    visited[u] = 1;

    cout << u << " -- ";

    for (int v : adj[u])
    {
        if (visited[v] == 0)
        {
            DFS(v);
        }
        
    }
    


}

int main()
{
    adj[1].push_back(2);
    adj[1].push_back(4);

    adj[2].push_back(3);

    adj[3].push_back(4);
    adj[4].push_back(5);

    // 1부터 시작
    DFS(1);

}