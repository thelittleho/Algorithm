#include <iostream>
using namespace std;

int main()
{
    int m, n; cin >> m; cin >> n;
    int adj[m][n];
    int count[10] = {0, };

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == -1) continue;

            count[adj[i][j]] += 1;
            
        }
    }

    for (int i = 0; i < 10; i++)
    {
        if (count[i] == 0)
        {
            continue;
        }
        
        

        cout << i << " " << count[i] << endl;;
    }
    



    
    

    

}