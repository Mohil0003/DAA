// add switch case for file pointer scanning
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>



// Quick Sort Using Pivot Function:

void pivot(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[high] = arr[i + 1];
    arr[i + 1] = pivot;
}

void Quick_Sort(int arr[], int low, int high) {
    if (low < high) {
        pivot(arr, low, high);
    }
    int pivot = arr[high];
    int i = low - 1;

    if (low < high) {
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

        Quick_Sort(arr, low, i);
        Quick_Sort(arr, i + 2, high);
    }
}

void main() {
    clock_t start , end;
    int choice;
    FILE* fp;
    int n;
    int arr[100000];
    double time;

    printf("1. Average Case \n 2. Worst Case \n Anything for terminated ");
    scanf("%d" , &choice);
    switch(choice) {
        case 1:
            fp = fopen("average.txt","r");
            break;
        case 2:
            fp = fopen("worst.txt","r");
            break;
        default:
            printf("Terminated\n");
            return;
    }
    printf("\nEnter Number of Elements : ");
    scanf("%d" , &n);

    for(int i=0 ; i<n ; i++){
        fscanf(fp ,"%d",&arr[i]);
    }
    fclose(fp);

    start = clock();
    Quick_Sort(arr, 0, n - 1);
    end = clock();
    time = ((double)(end - start)) / CLOCKS_PER_SEC;

   printf("Time taken to sort: %f seconds\n", time);
}  




// Quick Sort without Pivot  Function:

// void Quick_Sort(int arr[], int low, int high) {
//     if (low < high) {
//         int pivot = arr[high];
//         int i = low - 1;
//         for (int j = low; j < high; j++) {
//             if (arr[j] < pivot) {
//                 i++;
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//         int temp = arr[i + 1];
//         arr[i + 1] = arr[high];
//         arr[high] = temp;
//         int partitionIndex = i + 1;
//         Quick_Sort(arr, low, partitionIndex - 1);
//         Quick_Sort(arr, partitionIndex + 1, high);
//     }
// }
// void main() {
//     int n;
//     printf("Enter the number of elements: ");
//     scanf("%d", &n);
//     int *arr = (int *)malloc(n * sizeof(int));
//     printf("Enter the elements: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &arr[i]);
//     }
//     Quick_Sort(arr, 0, n - 1);
//     printf("Sorted array: ");
//     for (int i = 0; i < n; i++) {
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
//     free(arr);
// }