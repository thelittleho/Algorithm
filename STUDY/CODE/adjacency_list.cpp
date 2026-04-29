#include <iostream>
#include <vector>
using namespace std;

const int v = 10;
vector<int> adj[v];
int visited[v];

void solve(int _idx)
{
    visited[_idx] = 1;
    cout << _idx << endl;

    for(int there : adj[_idx])
    {
        if (visited[there]) continue;

        solve(there);
    }
}

int main()
{
    adj[0].push_back(1); adj[0].push_back(4);
    
    adj[1].push_back(0); adj[1].push_back(2);
    adj[1].push_back(3); adj[1].push_back(4);
    
    adj[2].push_back(1); adj[2].push_back(3);
    
    adj[3].push_back(1); adj[3].push_back(2);
    adj[3].push_back(4);
    
    adj[4].push_back(0); adj[4].push_back(1);
    adj[4].push_back(3);

    for (int i = 0; i < v; ++i)
    {
        // adj 벡터의 사이즈가 0이 아니라면
        // 어떠한 값이 있다는 것 즉 연결된 정점들이 들어있다라는 뜻
        if (adj[i].size() && visited[i] == false)
            solve(i);
    }

    return 0;

}