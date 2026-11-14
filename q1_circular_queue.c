/*
 * Question 1: Circular queue implementation in C
 * CCS 2214 - Data Structures and Algorithms
 *
 * A circular queue reuses the empty slots left behind by dequeued
 * elements by wrapping the front and rear indices around the array.
 * One slot is tracked through a size counter, so the full capacity
 * of the array can be used and "full" and "empty" are easy to tell apart.
 */
#include <stdio.h>

#define MAX 5

typedef struct {
    int items[MAX];
    int front;   /* index of the first element */
    int rear;    /* index of the last element  */
    int size;    /* number of elements stored  */
} CircularQueue;

void initQueue(CircularQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(const CircularQueue *q) { return q->size == 0; }
int isFull(const CircularQueue *q)  { return q->size == MAX; }

void enqueue(CircularQueue *q, int value) {
    if (isFull(q)) {
        printf("Queue is full. Cannot insert %d\n", value);
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->items[q->rear] = value;
    q->size++;
    printf("Inserted %d\n", value);
}

int dequeue(CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty. Nothing to remove\n");
        return -1;
    }
    int value = q->items[q->front];
    q->front = (q->front + 1) % MAX;
    q->size--;
    printf("Removed %d\n", value);
    return value;
}

void display(const CircularQueue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front -> rear): ");
    for (int i = 0, idx = q->front; i < q->size; i++, idx = (idx + 1) % MAX)
        printf("%d ", q->items[idx]);
    printf("\n");
}

int main(void) {
    CircularQueue q;
    initQueue(&q);

    printf("--- Fill the queue ---\n");
    for (int i = 1; i <= 5; i++) enqueue(&q, i * 10);
    display(&q);

    printf("\n--- Try to insert into a full queue ---\n");
    enqueue(&q, 60);

    printf("\n--- Remove two elements ---\n");
    dequeue(&q);
    dequeue(&q);
    display(&q);

    printf("\n--- Insert again: freed slots are reused (wrap-around) ---\n");
    enqueue(&q, 60);
    enqueue(&q, 70);
    display(&q);

    printf("\n--- Empty the queue ---\n");
    while (!isEmpty(&q)) dequeue(&q);
    dequeue(&q);
    return 0;
}
