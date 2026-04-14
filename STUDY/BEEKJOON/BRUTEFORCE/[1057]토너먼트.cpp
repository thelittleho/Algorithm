#include <iostream>
#include <vector>

using namespace std;

int N, K, I;

void input()
{
    cin >> N >> K >> I;
}

void solution()
{
    int r = 0;

    while (K != I)
    {
        K -= K/2;
        I -= I/2;

        r += 1;
    }

    cout << r;
    
    

}

void solve()
{
    input();
    solution();

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();

    return 0;
}