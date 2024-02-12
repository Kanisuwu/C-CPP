#include <stdio.h>
#include <stdlib.h>

struct arr {
    int *A;
    int size;
    int length;
};

void display(struct arr Array) {
    for(int i = 0; i < Array.length; ++i) {
        printf("%d ", Array.A[i]);
    }
    printf("\n");
}

int compare(const void *x, const void *y) {
    int arg1 = *(const int *)x;
    int arg2 = *(const int *)y;
    return (arg1 > arg2) - (arg1 < arg2);  
}

void intswap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int append(struct arr *Array, int num) {
    if (Array->length >= Array->size) {
        printf("Could not append array at line %d\n", __LINE__);
        return -1;
    }
    Array->A[Array->length] = num;
    Array->length++;
    return 0;
}

int insert(struct arr *Array, int index, int num) {
    if (Array->length >= Array->size) {
        printf("Could not insert element at line %d\n", __LINE__);
        return -1;
    }
    if (index > Array->length)
        return -1;
    for (int i = Array->length; i > index; --i) {
        Array->A[i] = Array->A[i - 1];
    }
    Array->A[index] = num;
    Array->length++;
    return 0;
}

int delete(struct arr *Array, int index) {
    if (index > Array->length)
        return -1;
    for (int i = index; i < Array->length - 1; ++i) {
        Array->A[i] = Array->A[i + 1];
    }
    Array->length--;
    return 0;
}

// O(n) = (n+1) + n = 2n + 1
int search(struct arr Array, int key) {
    for (int i = 0; i < Array.length; ++i) {
        if (key == Array.A[i]) {
            intswap(&Array.A[i], &Array.A[0]);
            return 0;
        }
    }
    return -1;
}

// Binary search needs three variables.
// lowest, highest and mid which is ((l + h) / 2).
// Obviously the list MUST BE sorted.
// O(log n)
int bisearch(struct arr Array, int key) {
    int low = 0;
    int high = Array.length - 1;
    while (low <= high) {
        int mid = ((low + high) / 2);
        if (key == Array.A[mid])
            return mid;
        else if (key < Array.A[mid])
            high = mid - 1;
        else 
            low = mid + 1;
    }
    return -1;
}

// O(1) = 1 + 1
int get(struct arr arr, int index) {
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

// O(1) = 1 + 1
int set(struct arr *arr, int index, int value) {
    if (index >= 0 && index < arr->length) {
        arr->A[index] = value;
        return 0;
    }
    return -1;
}

// O(n) = 1 + n + (n - 1) + 1
int max(struct arr arr) {
    int max = arr.A[0];
    for (int i = 1; i < arr.length; ++i) {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

// O(n) = 1 + n + (n - 1) + 1
int min(struct arr arr) {
    int min = arr.A[0];
    for (int i = 1; i < arr.length; ++i) {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int avg(struct arr arr) {
    int total = 0;
    for (int i = 0; i < arr.length; ++i)
        total += arr.A[i];
    return total;
}

int reverse_mem(struct arr *arr) {
    int i, j;
    int *barr = NULL;
    barr = (int *)malloc(sizeof(int) * arr->size);
    if (barr == NULL)
        return -1;
    // YOU. CAN. PUT. COMMA. REMEMBER.
    for (i = arr->length - 1, j = 0; i >= 0; --i, ++j) {
        barr[j] = arr->A[i];
    }
    free(arr->A);
    arr->A = barr;
    return 0;
}

// More efficient than the above in space AND time.
void reverse(struct arr *arr) {
    int i, j, temp;
    // Remember, you can always put commas.
    // i starts at the beginning and j at the end.
    // Progressively interchange the indexes.
    for (i = 0, j = arr->length - 1; i < j; ++i, --j) {
        temp = arr->A[i];
        arr->A[i] = arr->A[j];
        arr->A[j] = temp;
    }
}

// O(n)
void rearrange(struct arr *arr) {
    int i = 0;
    int j = arr->length - 1;
    while (i < j) {
        while(arr->A[i] < 0){++i;}
        while(arr->A[j] >= 0){--j;}
        if (i < j)
            intswap(&arr->A[i], &arr->A[j]);
    }
}

_Bool isSorted(struct arr *arr) {
    for (int i = 0; i < arr->length - 1; ++i) {
        if (arr->A[i] > arr->A[i + 1])
            return 0;
    }
    return 1;
}

void left_shift(struct arr *arr) {
    int i;
    int temp = arr->A[0];
    for (i = 1; i < arr->length; ++i) {
        arr->A[i - 1] = arr->A[i];
    }
    arr->A[arr->length - 1] = temp;
}

struct arr merge(struct arr first, struct arr second) {
    int i = 0, j = 0, k = 0;
    struct arr newArr;
    newArr.A = NULL;
    newArr.size = first.size + second.size;
    newArr.length = first.length + second.length;
    newArr.A = (int *)malloc(newArr.size * sizeof(int));
    while (i < first.length && j < second.length) {
        if (first.A[i] < second.A[j])
            newArr.A[k++] = first.A[i++];
        else
            newArr.A[k++] = second.A[j++];
    }
    for (; i < first.length; i++)
        newArr.A[k++] = first.A[i];
    for (; j < second.length; j++)
        newArr.A[k++] = second.A[j];
    
    return newArr;
}

/*
 *  >>>>> MAIN CODE SECTION <<<<<
 */

int main(void) {
    struct arr Array;
    Array.size = 12;
    Array.length = 12;
    Array.A = (int *)malloc(Array.size * sizeof(int));
    struct arr Array2;
    Array2.size = 12;
    Array2.length = 12;
    struct arr merged;
    Array2.A = (int *)malloc(Array2.size * sizeof(int));

    for (int i = 0; i < Array.length; ++i) {
        Array.A[i] = i + i;
        Array2.A[i] = i * 5;
    }
    display(Array);
    display(Array2);
    merged = merge(Array, Array2);
    display(merged);
    free(merged.A);
    free(Array.A);
    free(Array2.A);
    return 0;
}
