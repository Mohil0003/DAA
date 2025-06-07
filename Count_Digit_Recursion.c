#include <stdio.h>

int Count_Digit(int n){
    if(n<0){
        n=-n;
    }
    if(n<10){
        return 1;
    }
    return 1 + Count_Digit(n/10);

    
}

void main(){
    int n;
    printf("Enter Number : ");
    scanf("%d" , &n);

    int ans = Count_Digit(n);
    printf("%d" , ans);
}