#include <cstdio>

int array[5] = {82, 61, 5, 30, 74};
int count = 5;

int move_count = 0;

void insert(int n, int arr[], int val) {
    /**
     * i : index to insert
     * j : index to move existing elements
     */
    int i, j;
    // find index to insert
    for (i = 0; i < n && arr[i] < val; i++);
    // make space to insert a new item
    for (j = n-1; j > i; j--) {
        arr[j] = arr[j-1];
        move_count++;
    }
    // store the value
    arr[i] = val;
}

void insertion_sort(int n, int arr[]) {
    for (int i = 1; i < n; i++) {
        insert(i+1, arr, arr[i]);
    }
}

void print_array(int n, int arr[]);

int main()
{
    printf("%16s ", "before sort:");
    print_array(count, array);

    insertion_sort(count, array);

    printf("%16s ", "after sort:");
    print_array(count, array);
    printf("-> total %d moves.\n", move_count);
}

void print_array(int n, int arr[]) {
    for (int i = 0; i < n; i++)
        printf("%2d ", arr[i]);
    printf("\n");
}
