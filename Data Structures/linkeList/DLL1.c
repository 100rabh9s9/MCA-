#include <stdio.h>
#include <stdlib.h>

// Define node structure
struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
};

// Global head pointer
struct Node* head = NULL;

// Insert at the end
void insert_end(int value)
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}
// Display the list
void display()
 {
    struct Node* temp = head;

    if (temp == NULL)
     {
        printf("List is empty.\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf("\n");
}
int main()
{
    int n, value;

    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
     {
        printf("Enter value %d: ", i);
        scanf("%d", &value);
        insert_end(value);
    }
    display();

    return 0;
}
