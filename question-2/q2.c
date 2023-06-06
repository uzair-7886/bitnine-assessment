#include <stdio.h>
#include <stdlib.h>



//advantages: simple easy to understand and self explanatory
//disadvantages:  Very inefficient due to repeated recursive calls. Will exceed stack limit for large n.
int Recursive(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return Recursive(n - 3) + Recursive(n - 2);
}


//advantages:  Very efficient. No stack overflow. Works for any value of n
//disadvantages:  Not as simple as recursive solution.
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


//advantages: Simple like recursion, efficient like iteration
//disadvantages: Requires extra space for memoizationn
int DP(int n) {
    int memo[n+1];
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;

    for (int i = 3; i <= n; i++) {
        memo[i] = memo[i-3] + memo[i-2];
    }

    return memo[n];
}

int main()
{

    printf("Recursive: %d\n", Recursive(15));
    printf("Iterative: %d\n", Iterative(15));
    printf("DP: %d\n", DP(15));

    return 0;
}