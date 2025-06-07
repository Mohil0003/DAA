#include <stdio.h>

int Sum_of_Digit(n){
    if(n==1){
        return 1;
    }
    else{
        return n + Sum_of_Digit(n-1);
    }
}


void main(){
    int n;
    printf("Enter Number : ");
    scanf("%d",&n);

    int ans = Sum_of_Digit(n);
    printf("%d",ans);
}