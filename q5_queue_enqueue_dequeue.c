/*
 * Question 5: Enqueue and dequeue operations on a queue (array based)
 * Menu driven program.
 */
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = 0;
int rear = -1;
int count = 0;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue overflow: cannot insert %d\n", value);
        return;
    }
    queue[++rear] = value;
    count++;
    printf("Inserted %d\n", value);
}

void dequeue(void) {
    if (count == 0) {
        printf("Queue underflow: queue is empty\n");
        return;
    }
    printf("Removed %d\n", queue[front++]);
    count--;
    if (count == 0) {              /* reset so the space can be used again */
        front = 0;
        rear = -1;
    }
}

void display(void) {
    if (count == 0) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue (front -> rear): ");
    for (int i = front; i <= rear; i++) printf("%d ", queue[i]);
    printf("\n");
}

int main(void) {
    int choice, value;
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) == 1) enqueue(value);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Goodbye\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 4);
    return 0;
}
