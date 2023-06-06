#include <stdio.h>
#include <stdlib.h>

int Recursive(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return F(n - 3) + F(n - 2);
}

int Iterative(int n)
{
    int a = 0, b = 1, c = 2;
    int d;
    for (int i = 3; i <= n; i++)
    {
        d = a + b;
        a = b;
        b = c;
        c = d;
    }
    return c;
}

int DP(int n)
{
    int memo[n + 1];
    if (memo[n] != 0)
        return memo[n];
    if (n == 0)
        memo[0] = 0;
    if (n == 1)
        memo[1] = 1;
    if (n == 2)
        memo[2] = 2;
    memo[n] = F(n - 3) + F(n - 2);
    return memo[n];
}

int main()
{

    printf("Recursive: %d\n", Recursive(10));
    printf("Iterative: %d\n", Iterative(10));
    printf("DP: %d\n", DP(10));

    return 0;
}