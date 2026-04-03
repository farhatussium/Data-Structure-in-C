#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// 🔵 INSERT
void insert(int value) {
    struct node *newnode, *temp;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;

    if (head == NULL) {
        head = newnode;
        newnode->next = head;
    }
    else {
        temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;
    }
}

// 🔵 DISPLAY
void display() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(head)\n");
}

// 🔴 DELETE FIRST
void deleteFirst() {
    struct node *temp, *last;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (head->next == head) {
        head = NULL;
        free(temp);
        return;
    }

    last = head;
    while (last->next != head) {
        last = last->next;
    }

    head = head->next;
    last->next = head;

    free(temp);
}

// 🔴 DELETE LAST
void deleteLast() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (head->next == head) {
        head = NULL;
        free(temp);
        return;
    }

    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    free(temp);
}

// 🔴 DELETE VALUE
void deleteValue(int value) {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;

    if (head->data == value) {
        deleteFirst();
        return;
    }

    do {
        prev = temp;
        temp = temp->next;

        if (temp->data == value) {
            prev->next = temp->next;
            free(temp);
            return;
        }

    } while (temp != head);

    printf("Value not found\n");
}

// 🔵 MAIN
int main() {
    insert(10);
    insert(20);
    insert(30);
    insert(40);

    display();

    deleteFirst();
    display();

    deleteLast();
    display();

    deleteValue(20);
    display();

    return 0;
}
