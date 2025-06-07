// #include <stdio.h>

// void main(){
//     int term;
//     printf("Enter Number of terms : " );
//     scanf("%d" , &term);
//     int sum=0;
//     int a=0;
//     int b=1;

//     printf("%d %d ",a,b);

//     for(int i=1 ; i<=term ; i++){
//         sum=a+b;
//         a=b;
//         b=sum;
//         printf("%d " , sum);
//     }
// }

#include<stdio.h>

void main(){
    int n;
    int first = 0;
    int second = 1;
    int i;
    int sum = 0;

    printf("Enter number of terms : ");
    scanf("%d", &n);
    int ans[n];

    ans[0] = first;
    ans[1] = second;

    for (i = 2; i <= n; i++)
    {
        sum = first + second;
        ans[i] = sum;
        first = second;
        second = sum;
    }

    for (i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
     
}