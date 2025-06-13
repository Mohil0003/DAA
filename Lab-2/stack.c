#include <stdio.h>
#include <stdlib.h>
#define MAX 100

    int arr[MAX];
    int top=-1;

void push(int value){
    if(top == (MAX-1)){
        printf("Stack Overflow");
    }else{
        arr[++top]=value;
    }
}

int pop(){
    if(top==-1){
        printf("Stack Underflow");
        return 0;
    }else{
        return arr[top--];
    }
}

int peap(int idx){
    if((top + idx - 1)< 0){
        printf("invalid index");
        return 0;
    }else{
        return arr[top-idx+1];
    }
}

void change(int idx , int value){
    if((top-idx +1)<0){
        printf("invalid index");
    }else{
        arr[idx]=value;
    }
}

void display(){
    printf("stack is : ");
    for(int i=0 ; i<=top ; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}


void main(){
    int n;
    int value;
    printf("Enter Length of Stack : ");
    scanf("%d" , &n);
    for(int i=0 ; i<n ; i++){
        printf("Enter Value : ");
        scanf("%d",&value);
        push(value);
    }
    int ans=peap(3);
    printf("peap element  is : %d\n" , ans);
    display();

    printf("after change\n");
    change(4,10);
    display();

}
