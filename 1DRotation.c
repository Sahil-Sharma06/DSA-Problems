#include <stdio.h>

void rotateArray(int arr[], int n, int rotateBy) {
    int temp[rotateBy];

    for (int i = 0; i < rotateBy; i++) {
        temp[i] = arr[i];

    for (int i = rotateBy; i < n; i++) {
        arr[i - rotateBy] = arr[i];
    }

    for (int i = 0; i < rotateBy; i++) {
        arr[n - rotateBy + i] = temp[i];
    }
}
}

int main(){
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int rotateBy;
    printf("Enter the number of positions to rotate by: ");
    scanf("%d", &rotateBy);

    rotateArray(arr, n, rotateBy);

    printf("Rotated array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}