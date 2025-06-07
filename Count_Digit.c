#include <stdio.h>

void main(){
    int n;
    printf("Enter Number : ");
    scanf("%d" ,&n);
    int count=0;

    while(n!=0){
        count++;
        n=n/10;

    }

    printf("%d",count);
}