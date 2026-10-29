#include <stdio.h>

int binary_search(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) return mid;
        if (arr[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main(void) {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof arr / sizeof arr[0];
    int target;

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);

    printf("\nEnter number to search: ");
    if (scanf("%d", &target) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    int index = binary_search(arr, n, target);
    if (index == -1) printf("%d not found\n", target);
    else printf("%d found at index %d\n", target, index);
    return 0;
}
