#include <stdio.h>

void main(){
    int n;
    printf("Enter Number : ");
    scanf("%d", &n);
    int fact = 1;
    for(int i = 1; i <= n; i++){
        fact *= i;
    }
    printf("Factorial of %d is %d\n", n, fact);
}