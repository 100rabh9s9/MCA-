#include <stdio.h>
#include <stdlib.h>

struct node
 {
    int data;
    struct node *next;
};

struct node* createNode(int val)
 {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (!newNode)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}

struct node* createList(int n)
 {
    struct node *head = NULL, *temp = NULL, *newNode;
    int data;

    if (n <= 0)
    {
        printf("Number of nodes must be greater than 0.\n");
        return NULL;
    }

    for (int i = 1; i <= n; i++)
        {
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode = createNode(data);

        if (head == NULL)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("Linked list created successfully.\n");
    return head;
}

void displayList(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = head;
    printf("List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int countNodes(struct node *head)
 {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

int main()
{
    struct node *head = NULL;
    int choice, n;

    while (1)
    {
        printf("\n==== Linked List Menu ====\n");
        printf("1. Create List\n");
        printf("2. Display List\n");
        printf("3. Count Nodes\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                head = createList(n);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Number of nodes: %d\n", countNodes(head));
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
