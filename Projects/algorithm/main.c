#include <stdio.h>

// O(n²)
void INT_bubblesort(int *array, int length) 
{
    for (int i = 0; i < length; ++i) 
    {
        for (int j = 0; j < length - (i + 1); ++j) 
        {
            int left = array[j];
            int right = array[j + 1];
            if (left > right) 
            {
                array[j] = right;
                array[j + 1] = left;
            }
        }
    }
}

int power(int m, int n)
{
    if (n == 0)
        return 1;
    if ((n % 2) == 0)
        return power(m * m, n / 2);
    return m * power(m * m, (n - 1) / 2);
}

int main(void) 
{
    int length = 5;
    int array[5] = {5, 8, 2, 22, 17};
    INT_bubblesort(array, length);
    for (int i = 0; i < length; ++i) 
    {
        printf("%i\n", array[i]);
    }
    return 0;
}
