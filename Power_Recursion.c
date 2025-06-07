#include <stdio.h>

int Power(int base , int power){
    if(base==0 && power==0){
        printf("Indeterminate Term");
    }
    if(power==0 && base!=0){
        return 1;
    }
    else{
        return base * Power(base,power-1);
    }
}

void main(){
    int a,b;
    printf("Enter Base Number");
    scanf("%d", &a);
    printf("Enter Power Number");
    scanf("%d", &b);

    int ans = Power(a,b);

    printf("%d",ans);
}