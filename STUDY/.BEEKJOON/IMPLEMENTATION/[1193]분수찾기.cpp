#include <iostream>

using namespace std;

int X;

void input()
{
    cin >> X;
}

void solution()
{
    int line = 1;
    int a, b; // 분자, 분모

    while (X > line) // 입력값이 어느 라인에 위치하는지 검색하는 과정
    {
        X -= line;
        line += 1;
    } // 이때 X는 1 ~ line 사이의 값을 가질 것이다
    
    if (line % 2 == 0)// 라인이 짝수일 떄;
    {
        a = X;
        b = line - X + 1;
    }
    else // 라인이 홀수일 때;
    {
        a = line - X + 1;
        b = X;
    }

    cout << a << "/" << b;

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