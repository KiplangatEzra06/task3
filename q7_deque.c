/*
 * Question 7: Operations on a double ended queue (deque) in C
 * Circular array implementation:
 *   insertFront, insertRear, deleteFront, deleteRear
 */
#include <stdio.h>

#define MAX 5

int deque[MAX];
int front = 0;      /* index of the first element */
int rear = -1;      /* index of the last element  */
int size = 0;

/* Front insertion */
void insertFront(int value) {
    if (size == MAX) {
        printf("Deque overflow: cannot insert %d at front\n", value);
        return;
    }
    front = (front - 1 + MAX) % MAX;
    deque[front] = value;
    if (size == 0) rear = front;
    size++;
    printf("Inserted %d at front\n", value);
}

/* Rear insertion */
void insertRear(int value) {
    if (size == MAX) {
        printf("Deque overflow: cannot insert %d at rear\n", value);
        return;
    }
    rear = (rear + 1) % MAX;
    deque[rear] = value;
    size++;
    printf("Inserted %d at rear\n", value);
}

/* Front deletion */
void deleteFront(void) {
    if (size == 0) {
        printf("Deque underflow: deque is empty\n");
        return;
    }
    printf("Deleted %d from front\n", deque[front]);
    front = (front + 1) % MAX;
    size--;
}

/* Rear deletion */
void deleteRear(void) {
    if (size == 0) {
        printf("Deque underflow: deque is empty\n");
        return;
    }
    printf("Deleted %d from rear\n", deque[rear]);
    rear = (rear - 1 + MAX) % MAX;
    size--;
}

void display(void) {
    if (size == 0) {
        printf("Deque is empty\n");
        return;
    }
    printf("Deque (front -> rear): ");
    for (int i = 0, idx = front; i < size; i++, idx = (idx + 1) % MAX)
        printf("%d ", deque[idx]);
    printf("\n");
}

int main(void) {
    int choice, value;
    do {
        printf("\n1. Insert front\n2. Insert rear\n3. Delete front\n"
               "4. Delete rear\n5. Display\n6. Exit\nChoice: ");
        if (scanf("%d", &choice) != 1) break;
        switch (choice) {
            case 1:
                printf("Enter value: ");
                if (scanf("%d", &value) == 1) insertFront(value);
                break;
            case 2:
                printf("Enter value: ");
                if (scanf("%d", &value) == 1) insertRear(value);
                break;
            case 3: deleteFront(); break;
            case 4: deleteRear(); break;
            case 5: display(); break;
            case 6: printf("Goodbye\n"); break;
            default: printf("Invalid choice\n");
        }
    } while (choice != 6);
    return 0;
}
