#include <stdio.h>

void main(){
    int a,b;
    printf("Enter Base Number");
    scanf("%d", &a);
    printf("Enter Power Number");
    scanf("%d", &b);
    int ans=1;
    int i=0;

    while(i<b){
        ans*=a;
        i++;
    }

    printf("Ans is : %d",ans);

}