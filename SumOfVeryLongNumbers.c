#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

struct Node* addLists(struct Node* list1, struct Node* list2) {
    struct Node* result = NULL;
    struct Node* temp;
    int carry = 0, sum;

    while (list1 != NULL || list2 != NULL) {
        sum = carry + (list1 ? list1->data : 0) + (list2 ? list2->data : 0);
        carry = sum / 10;
        sum %= 10;
        insertAtEnd(&result, sum);

        if (list1) list1 = list1->next;
        if (list2) list2 = list2->next;
    }

    if (carry > 0) {
        insertAtEnd(&result, carry);
    }

    return result;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;

    char digit;
    printf("Enter the first very long number (end with Enter): ");
    while ((digit = getchar()) != '\n') {
        insertAtEnd(&num1, digit - '0');
    }

    printf("Enter the second very long number (end with Enter): ");
    while ((digit = getchar()) != '\n') {
        insertAtEnd(&num2, digit - '0');
    }

    struct Node* sum = addLists(num1, num2);

    printf("Sum of the two very long numbers: ");
    printList(sum);

    return 0;
}