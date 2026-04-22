#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

/* ──────────────────────────────────────
   INSERT (Enqueue)
   Adds element at the rear of the queue
   ────────────────────────────────────── */
void enqueue(int value) {
    // Overflow check: queue is full
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    // First element being inserted
    if (front == -1) {
        front = 0;
    }

    rear++;
    queue[rear] = value;
    printf("Inserted: %d  (front=%d, rear=%d)\n", value, front, rear);
}

/* ──────────────────────────────────────
   DELETE (Dequeue)
   Removes element from the front
   ────────────────────────────────────── */
int dequeue() {
    // Underflow check: queue is empty
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
        return -1;
    }

    int value = queue[front];
    front++;

    // Reset when queue becomes empty
    if (front > rear) {
        front = -1;
        rear  = -1;
    }

    printf("Deleted: %d  (front=%d, rear=%d)\n", value, front, rear);
    return value;
}

/* ──────────────────────────────────────
   DISPLAY
   Prints current queue contents
   ────────────────────────────────────── */
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: [ ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("] (front=%d, rear=%d)\n", front, rear);
}

/* ──────────────────────────────────────
   MAIN – demonstrates all cases
   ────────────────────────────────────── */
int main() {
    printf("=== Queue Operations Demo ===\n\n");

    // Normal insertions
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    // Overflow: queue is already full
    printf("\n-- Overflow test --\n");
    enqueue(60);

    // Normal deletions
    printf("\n-- Dequeue operations --\n");
    dequeue();
    dequeue();
    display();

    // Delete remaining elements
    dequeue();
    dequeue();
    dequeue();

    // Underflow: queue is now empty
    printf("\n-- Underflow test --\n");
    dequeue();

    return 0;
}