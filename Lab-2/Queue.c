// Queue Implementation using basic methods

#include <stdio.h>
#define SIZE 100

struct Queue {
    int items[SIZE];
    int front;
    int rear;
};

void initialize(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == SIZE - 1) {
        printf("Queue is full!\n");
        return;
    }

    if (q->front == -1) {
        q->front = 0;
    }

    q->rear++;
    q->items[q->rear] = value;
    printf("Enqueued: %d\n", value);
}

void dequeue(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Dequeued: %d\n", q->items[q->front]);
    q->front++;

    if (q->front > q->rear) {
        q->front = q->rear = -1;
    }
}

void peek(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Front element: %d\n", q->items[q->front]);
}

void display(struct Queue* q) {
    if (q->front == -1 || q->front > q->rear) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->items[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    display(&q);

    peek(&q);

    dequeue(&q);
    dequeue(&q);

    display(&q);

    dequeue(&q);
    dequeue(&q); 

}
