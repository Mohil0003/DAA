#include<stdio.h>
#include<time.h>

void Linear_Search(int arr[] , int n , int key){
    int i;
    for(i=0; i<n; i++){
        if(arr[i] == key){
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found\n");
}

void Binary_Search(int arr[] , int n , int key){
    int low=0;
    int high=n-1;

    

    while(low <= high){

        int mid = low + (high-low)/2;

        if (arr[mid] == key){
            printf("Element found at : %d",mid);
            return;
        }

        if (arr[mid] < key){
            low = mid + 1;    
        }
        else{
            high = mid - 1;
        }
    }
}

void recursive_Binary_Search(int arr[] , int low , int high , int key){
    if (low > high) {
        printf("Element not found\n");
        return;
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == key) {
        printf("Element found at : %d", mid);
        return;
    }

    if (arr[mid] < key) {
        recursive_Binary_Search(arr, mid + 1, high, key);
    } else {
        recursive_Binary_Search(arr, low, mid - 1, key);
    }
}

void main(){
    clock_t start, end;
    int choice;
    FILE* fp;
    int n;
    int arr[100000];
    int key;
    double time;
    int num;

    printf("\n 1 for Linear Search \n 2 for Binary Search\n 3 for recursive Binary Search\n Anything for Exit.\n");
    scanf("%d",&choice);

    printf("\n 1 for 100 Element \n 2 for 1000 Element \n 3 for 10000 Element \n 4 for 100000 Element \n 5 for Exit.\n");
    scanf("%d",&n);


    switch(n){
        case 1:
            fp = fopen("array_100.txt","r");
            num=100;
            break;

        case 2:
            fp = fopen("array_1000.txt","r");
            num=1000;
            break;

        case 3:
            fp = fopen("array_10000","r");
            num=10000;
            break;
            
        case 4:
            fp = fopen("array_100000","r");
            num=100000;
            break;

        default:
            break;
    }

    for(int i=0 ; i<=num ; i++){
        fscanf(fp ,"%d",&arr[i]);
    }

    printf("\nEnter Numebr to Find : ");
    scanf("%d" , &key);

    switch(choice){

        case 1:
            start = clock();
            Linear_Search(arr , num , key);
            end = clock();
            time = (double)(end - start)/ CLOCKS_PER_SEC;
            printf("Time taken For Linear Search: %f" , time);
            break;

        case 2:
            start = clock();
            Binary_Search(arr , num , key);
            end = clock();
            time = (double)(end - start)/ CLOCKS_PER_SEC;
            printf("Time taken For Binary Search: %f" , time);
            break;
        case 3:
            start = clock();
            recursive_Binary_Search(arr , 0 , num-1 , key);
            end = clock();
            time = (double)(end - start)/ CLOCKS_PER_SEC;
            printf("Time taken For recursive Binary Search: %f" , time);
            break;

        default:
            break;
    }
    

}