//q1.c
#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;


void create();
void insert_begin();
void insert_middle();
void insert_end();
void delete_begin();
void delete_middle();   
void delete_end();
void traverse();


int main() {
    int choice;

    while (1) {
        printf("\n--- Doubly Linked List Menu ---\n");
        printf("1. Create\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at Middle\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from Middle\n");
        printf("7. Delete from End\n");
        printf("8. Traverse\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: create(); break;
            case 2: insert_begin(); break;
            case 3: insert_middle(); break;
            case 4: insert_end(); break;
            case 5: delete_begin(); break;
            case 6: delete_middle(); break;
            case 7: delete_end(); break;
            case 8: traverse(); break;
            case 9: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
}

/* Create doubly linked list */
void create() {
    int n, i;
    struct node *newnode, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &newnode->data);

        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = temp = newnode;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

/* Insert at beginning */
void insert_begin() {
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

/* Insert at  middle */
void insert_middle() {
    struct node *slow, *fast, *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    if (head == NULL) {
        newnode->prev = newnode->next = NULL;
        head = newnode;
        return;
    }

    if (head->next == NULL) {
        head->next = newnode;
        newnode->prev = head;
        newnode->next = NULL;
        return;
    }

    slow = head;
    fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    newnode->next = slow;
    newnode->prev = slow->prev;

    slow->prev->next = newnode;
    slow->prev = newnode;
}

/* Insert at end */
void insert_end() {
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
}

/* Delete from beginning */
void delete_begin() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
}

/* Delete  middle */
void delete_middle() {
    struct node *slow, *fast;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    slow = head;
    fast = head;

    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->prev->next = slow->next;

    if (slow->next != NULL)
        slow->next->prev = slow->prev;

    free(slow);
}

/* Delete from end */
void delete_end() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (head->next == NULL) {
        free(head);
        head = NULL;
        return;
    }

    temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}

/* Traverse  */
void traverse() {
    struct node *temp;

    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
