#include <stdio.h>
int a[10001];
int n, i, j, temp;
int main() {
    scanf("%d", &n);
    for (i=1; i<=n; i++) scanf("%d", &a[i]);

    for(i=1; i<n; i++)
    {
        for (j=1; j<n; j++) // 이 부분에 들어가야 할 코드를 작성하면 됩니다.
        {
            if (a[j] > a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

    for (i = 1; i <= n; i++)
        printf("%d\n", a[i]);
    return 0;
}