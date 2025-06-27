#include<stdio.h>
#include<time.h>

void Selection_Sort(int arr[] , int n){
    int i,j,minj,minx;

    for(i=0 ; i<n-1 ; i++){
        minj = i;
        minx=arr[i];
        
        for(j=i+1 ; j<n ; j++){
            if(arr[j]< minx){
                minj=j;
                minx = arr[minj];
            }
        }
        arr[minj]= arr[i];
        arr[i]=minx;

    }
}


void main(){
    clock_t start , end;
    int choice;
    FILE* fp;
    int n;
    int arr[100000];

    printf("1. Best Case \n 2.Average Case \n 3. Worst Case \n Anything for terminated ");
    scanf("%d" , &choice);

    switch(n){
        case 1:
            fp = fopen("best.txt","r");
            break;

        case 2:
            fp = fopen("average.txt","r");
            break;

        case 3:
            fp = fopen("worst.txt","r");
            break;
            
        default:
            break;
    }

    printf("\nEnter Numebr Elemnet : ");
    scanf("%d" , &n);

    for(int i=0 ; i<n ; i++){
        fscanf(fp ,"%d",&arr[i]);
    }
    
    start= clock();
    Selection_Sort(arr , n);
    end = clock();
    for(int i=0 ; i<n ; i++){
        printf("%d",arr[i]);
    }
    printf("%d" , start);

    double time = (double)(end - start)/ CLOCKS_PER_SEC;

    printf("Time taken : %d" , time);
}