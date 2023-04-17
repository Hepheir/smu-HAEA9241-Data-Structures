#include <cstdio>

#define ARRAY_SIZE 8

int array[ARRAY_SIZE] = {16,12,8,38,19,4,20,27};
int count = ARRAY_SIZE;

int move_count = 0;

void swap(int *x, int *y) {
    int z = *x;
    *x = *y;
    *y = z;
    move_count++;
}

int split(int s, int e, int arr[]) {
    int pivot = arr[s];
    int left = s+1;
    int right = e;
    while (left <= right) {
        // find most right value which is less than pivot
        while (left <= right && arr[right] >= pivot)
            right--;
        // find most left value which is greater than pivot
        while (left <= right && arr[left] <= pivot)
            left++;
        if (left <= right) {
            swap(&arr[left], &arr[right]);
        }
    }
    swap(&arr[right], &arr[s]);
    return right;
}

void quick_sort(int s, int e, int arr[]) {
    if (s >= e)
        return;
    int m = split(s, e, arr);
    quick_sort(s, m-1, arr);
    quick_sort(m+1, e, arr);
}

void quick_sort(int n, int arr[]) {
    quick_sort(0, n-1, arr);
}

void print_array(int n, int arr[]);

int main()
{
    printf("%16s ", "before sort:");
    print_array(count, array);

    quick_sort(count, array);

    printf("%16s ", "after sort:");
    print_array(count, array);
    printf("-> total %d moves.\n", move_count);
}

void print_array(int n, int arr[]) {
    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}
