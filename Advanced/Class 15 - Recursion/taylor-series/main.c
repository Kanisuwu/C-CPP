#include <stdio.h>


void count(int n) {
    static int d = 1;
    printf("%d", n);
    printf("%d", d);
    d++;
    if (n > 0) {
        count(n - 1);
    }
}

double e(int x, int n)
{
    static double p = 1, f = 1;
    double r;
    if (n == 0)
        return (1);
    else
    {
        r = e(x, n-1);
        p = p * x;
        f = f * n;
        return r + p/f;
    }
}

double e2(double x, int n)
{
    double s = 1;
    int i;
    double num = 1;
    double den = 1;

    for (i = 1; i <= n; ++i)
    {
        num *= x;
        den *= i;
        s += num/den;
    }
    return s;
}

/*
 * 
 */
int fib(int n)
{
    static int array[50] = {-1};
    if (n <= 1)
    {
        array[n] = n;
        return n;
    }
    else
    {
        if (array[n - 2] == -1)
            array[n - 2] = fib(n - 2);
        if (array[n - 1] == -1)
            array[n - 1] = fib(n - 1);
    }
    return fib(n - 2) + fib(n - 1);
}

/*
 * O(n)
 */
int fib_l(int n)
{
    int t0 = 0, t1 = 1, s, i;
    if (n <= 1)
    {
        return n;
    }
    for (i = 2; i <= n; ++i)
    {
        s = t0 + t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int factorial(int n)
{
    if (n <= 1)
        return 1;
    int sum = n;
    for (int i = 1; i < n; ++i)
    {
        sum *= n - i;
    }
    return sum;
}

int C(int n, int r)
{
    int t1, t2, t3;
    t1 = factorial(n);
    t2 = factorial(r);
    t3 = factorial(n - r);
    return t1/(t2*t3);
}


int main(void)
{
    printf("%d\n", C(5, 2));
}
