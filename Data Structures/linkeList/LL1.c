#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void createList(int n)
{
    struct Node* newNode, *temp;
    int data;
    if (n <= 0)
    {
        printf("Number of nodes must be greater than 0.\n");
        return;
    }
    for (int i = 1; i <= n; i++)
     {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        if (newNode == NULL)
         {
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if (head == NULL)
        {
            head = newNode;
            temp = head;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    printf("Linked list created successfully.\n");
}
void displayList()
{
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
    int choice, n;
    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Create Linked List\n");
        printf("2. Display Linked List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("How many nodes do you want to create? ");
            scanf("%d", &n);
            createList(n);
            break;
        case 2:
            displayList();
            break;
        case 0:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

