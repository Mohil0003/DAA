// Linked List Implementation using all basic methods

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int data){
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode== NULL){
        printf("Memory Allocation Failed ! \n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtFirst(struct Node** Head, int data){
    struct Node* newNode = createNode(data);
    newNode->next=*Head;
    *Head = newNode;
}

void insertAtLast(struct Node** Head, int data){
    struct Node* newNode = createNode(data);
    if(*Head==NULL){
        *Head=newNode;
        return;
    }
    struct Node* Temp= *Head;
    while(Temp->next != NULL){
        Temp=Temp->next;
    }
    Temp->next=newNode;
}

void deleteAtLast(struct Node** Head){
    struct Node* Temp = *Head;
    if(Temp==NULL){
        printf("Empty !!!");
        return;
    }
    if (Temp->next == NULL) {
        free(Temp);
        *Head = NULL;
        printf("Last node deleted.\n");
        return;
    }
    while(Temp->next->next!=NULL){
        Temp=Temp->next;
    }
    free(Temp->next);
    Temp->next= NULL;
    printf("Last Node Deleted !!!\n");
    return;
}

void deleteNode(struct Node** Head, int key) {
    struct Node* Temp = *Head, *Prev = NULL;

    if (Temp != NULL && Temp->data == key) {
        *Head = Temp->next;
        free(Temp);
        printf("Node Deleted \n");
        return;
    }
    while (Temp != NULL && Temp->data != key) {
        Prev = Temp;
        Temp = Temp->next;
    }
    if (Temp == NULL){
        printf("Node Deleted \n");
        return;
    }

    Prev->next = Temp->next;
    free(Temp);
    printf("Node Deleted \n");

}

void deleteAtFirst(struct Node** Head){
    if(*Head==NULL){
        printf("Empty !!!");
        return;
    }
    struct Node* Temp=*Head;
    *Head =(*Head)->next;
    free(Temp);
    printf("Node Delete from Begining !!\n");
    
}


void displayLinkedList(struct Node* Head){
    struct Node* Temp = Head;
    printf("Linked List: ");
    while (Temp != NULL) {
        printf("%d -> ", Temp->data);
        Temp = Temp->next;
    }
    printf("NULL\n");
}


void main(){
    struct Node* Head = NULL;

    insertAtFirst(&Head , 20);
    insertAtFirst(&Head , 10);
    insertAtLast(&Head , 30);
    insertAtLast(&Head , 40);
    insertAtLast(&Head , 50);

    displayLinkedList(Head);

    deleteAtFirst(&Head);
    displayLinkedList(Head);

    deleteAtLast(&Head);
    displayLinkedList(Head);

    deleteNode(&Head,30);
    displayLinkedList(Head);

}
