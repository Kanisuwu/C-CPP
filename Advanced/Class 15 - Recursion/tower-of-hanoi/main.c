#include <stdio.h>

void toh(int n, int a, int b, int c)
{
    if (n > 0)
    {
        toh(n - 1, a, c, b);
        printf("from %d to %d\n", a, c);
        toh(n - 1, b, a, c);
    }
}

void count(int n)
{
    static int d = 1;
    printf("%d", n);
    printf("%d", d);
    d++;
    if (n > 1) count (n-1);
    printf("%d", d);
}

int main(void)
{
    count(3);
    return 0;
}
