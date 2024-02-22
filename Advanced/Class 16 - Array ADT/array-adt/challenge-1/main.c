#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

void minmax(int *arr, int n, int *mini, int *maxi) {
    int min = arr[0];
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        else if (arr[i] > max)
            max = arr[i];
    }
    *mini = min;
    *maxi = max;
}

int geth(int *array, int length) {
    int high = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] > high)
            high = array[i];
    }
    return high;
}

int getl(int *array, int length) {
    int low = array[0];
    for (int i = 1; i < length; i++) {
        if (array[i] < low)
            low = array[i];
    }
    return low;
}

// Sum of first n natural number formula:
// n * (n + 1) / 2
int sum(int *array, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum = sum + array[i];
    }
    int S = (length * (length + 1)) / 2;
    S -= sum;
    return S;
}

// O(n)
int iscan(int *array, int length) {
    int i;
    int first_index = array[0] - 0;
    int current;
    for (i = 1; i < length; i++) {
        current = array[i] - i;
        if (first_index != current) {
            while (first_index < array[i]-i) {
                printf("%d ", first_index + i);
                first_index++;
                }
            }
    }
    printf("\n");
    return 0;
}
// Hash table
void iscan2(int *array, int length) {
    int i;
    int low = getl(array, length);
    int high = geth(array, length);
    int max = high + 1;
    int *hash = (int *)malloc(max * sizeof(int));
    printf("Numbers missing: ");
    for (i = 0; i < max; i++) {
        hash[i] = 0;
    }
    for (i = 0; i < length; i++) {
        if (array[i] < max)
            hash[array[i]] = 1;
    }
    for (i = low; i < max; i++) {
        if(hash[i] == 0)
            printf("%d ", i);
    }
    printf("\n");
    free(hash);
}

void dup_hash(int *array, int length) {
    int i;
    int low = getl(array, length);
    int high = geth(array, length);
    int max = high + 1;
    int *hash = (int *)malloc(max * sizeof(int));
    printf("Numbers missing: ");
    for (i = 0; i < max; i++) {
        hash[i] = 0;
    }
    for (i = 0; i < length; i++) {
        if (array[i] < max)
            hash[array[i]]++;
    }
    for (i = low; i < max; i++) {
        if(hash[i] > 1)
            printf("%d[%d] ", i, hash[i]);
    }
    printf("\n");
    free(hash);
}

void duplicates_sorted(int *array, int length) {
    int i;
    int last_dup = 0;
    for (i = 0; i < length - 1; i++) {
        if ((array[i] == array[i + 1]) && (array[i] != last_dup)) {
            last_dup = array[i];
            printf("%d ", array[i]);
        }
    }
    printf("\n");
}

// O(n²)
void dup_unsort(int *array, int length) {
    int i, j;
    int count;
    for (i = 0; i < length - 1; i++) {
        count = 1;
        if (array[i] == INT_MIN)
            continue;
        for (j = i + 1; j < length; j++) {
            if (array[i] == array[j]){
                array[j] = INT_MIN;
                count++;
            }
        }
        if (count > 1)
            printf("%d[%d]\n", array[i], count);
    }
}

// O(n)
void unsort_hash(int *array, int length) {
    int i, low, high;
    minmax(array, length, &low, &high);
    int max = high + 1;
    int *hash = (int *)malloc(max * sizeof(int));
    // Init. hash to all 0s
    for (i = 0; i < max; i++)
        hash[i] = 0;
    for (i = 0; i < length; i++)
        if (array[i] < max)
            hash[array[i]]++;
    for (i = low; i < max; i++)
        if (hash[i] > 1)
            printf("%d[%d]\n", i, hash[i]);
    free(hash);
}

// O(n²)
void pair_unsort(int *array, int length, int target) {
    int i, j;
    for (i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if ((array[i] + array[j]) == target)
                printf("%d + %d = %d\n", array[i], array[j], target);
        }
    }
}

// O(n)
void pairhash_unsort(int *array, int length, int target) {
    int i, diff;
    int high = geth(array, length);
    int max = high + 1;
    int *hash = (int *)malloc(max * sizeof(int));
    for (i = 0; i < max; i++)
        hash[i] = 0;
    for (i = 0; i < length; i++) {
        diff = target - array[i];
        if (hash[diff] != 0)
            printf("%d + %d = %d\n", diff, array[i], target);
        hash[array[i]]++;
    }
}

// O(n)
void pair(int *array, int length, int target) {
    int i = 0, j = length - 1;
    int sum;
    while (i < j) {
        sum = array[i] + array[j];
        if (sum > target)
            j--;
        else if (sum < target)
            i++;
        else {
            printf("%d + %d = %d\n", array[i], array[j], sum);
            i++;
            j--;
        }
    }
}


int main(void) {
    int array[8] = {7, 2, 4, 5, 6, 8, 12, 9};
    int min;
    int max;
    minmax(array, 8, &min, &max);
    printf("Min: %d\nMax: %d\n", min, max);
    return 0;
}
