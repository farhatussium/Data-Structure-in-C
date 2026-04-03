#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *head = NULL;

// 🔵 DISPLAY
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// 🔵 INSERT AT BEGINNING
void insertFirst(int value) {
    struct node *newnode;
    newnode = (struct node*) malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = head;
    head = newnode;
}

// 🔵 INSERT AT END
void insertEnd(int value) {
    struct node *newnode, *temp;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;

    if (head == NULL) {
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newnode;
}

// 🔵 INSERT AT POSITION
void insertAtPos(int value, int pos) {
    struct node *newnode, *temp;
    int i;

    newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = value;

    if (pos == 1) {
        newnode->next = head;
        head = newnode;
        return;
    }

    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

// 🔴 DELETE FIRST
void deleteFirst() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;
    free(temp);
}

// 🔴 DELETE LAST
void deleteLast() {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
}

// 🔴 DELETE BY VALUE
void deleteValue(int value) {
    struct node *temp, *prev;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    // If first node
    if (head->data == value) {
        deleteFirst();
        return;
    }

    temp = head;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// 🔴 DELETE AT POSITION
void deleteAtPos(int pos) {
    struct node *temp, *prev;
    int i;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos == 1) {
        deleteFirst();
        return;
    }

    temp = head;
    for (i = 1; i < pos && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
}

// 🔵 MAIN
int main() {
    insertFirst(10);
    insertEnd(20);
    insertEnd(30);
    insertAtPos(15, 2);

    display();

    deleteFirst();
    display();

    deleteLast();
    display();

    deleteValue(15);
    display();

    deleteAtPos(1);
    display();

    return 0;
}