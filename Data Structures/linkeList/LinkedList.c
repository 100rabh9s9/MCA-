#include <stdio.h>
#include <stdlib.h>
//Blueprint for node creation 
struct Node
{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void createList();
void displayList();
int search(int key);
int countNodes();
void displayAlternateNodes();
void displayEvenPositionNodes();
int findMiddleNode();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAfterNode(int key, int data);
void insertBeforeNode(int key, int data);
void insertBetweenNodes(int value1, int value2, int newData);
void insertAtPosition(int position, int data);
struct Node* findNode(int data);  //Helper Function (used in search )
struct Node* createNode(int data);

int main()
 {
    int ch, data, key, pos, found, value1, value2;
    while (1)
        {
        printf("\n--- Menu ---\n");
        printf("1. Create linked list\n");
        printf("2. Display the list\n");
        printf("3. Search a particular value\n");
        printf("4. Count the number of nodes\n");
        printf("5. Display alternate node values from the first node\n");
        printf("6. Display all even positioned nodes\n");
        printf("7. Find the middle node value\n");
        printf("8. Insert a new node as the first node\n");
        printf("9. Insert a new node as the last node\n");
        printf("10. Insert a node after a given node\n");
        printf("11. Insert a node before a given node\n");
        printf("12. Insert a node between 2 nodes\n");
        printf("13. Insert a node at a particular position\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1:
                createList();
                break;
            case 2:
                printf("Linked List: ");
                displayList();
                printf("\n");
                break;
            case 3:
                printf("Enter value to search: ");
                scanf("%d", &data);
                found = search(data);
                if (found)
                    printf("%d found in the list.\n", data);
                else
                    printf("%d not found in the list.\n", data);
                break;
            case 4:
                printf("Number of nodes: %d\n", countNodes());
                break;
            case 5:
                printf("Alternate node values from first node: ");
                displayAlternateNodes();
                printf("\n");
                break;
            case 6:
                printf("Even positioned nodes: ");
                displayEvenPositionNodes();
                printf("\n");
                break;
            case 7:
                data = findMiddleNode();
                if (data != -1)
                    printf("Middle node value: %d\n", data);
                else
                    printf("List is empty.\n");
                break;
            case 8:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                printf("Node inserted at beginning.\n");
                break;
            case 9:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                printf("Node inserted at end.\n");
                break;
            case 10:
                printf("Enter node value after which to insert: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAfterNode(key, data);
                break;
            case 11:
                printf("Enter node value before which to insert: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertBeforeNode(key, data);
                break;
            case 12:
                printf("Enter the value of the first node: ");
                scanf("%d", &value1);
                printf("Enter the value of the second node: ");
                scanf("%d", &value2);
                printf("Enter the value for the new node: ");
                scanf("%d", &data);
                insertBetweenNodes(value1, value2, data);
                break;
            case 13:
                printf("Enter the position (1-indexed) where to insert: ");
                scanf("%d", &pos);
                printf("Enter the value for the new node: ");
                scanf("%d", &data);
                insertAtPosition(pos, data);
                break;
            case 0:
                // Free all nodes before exit
                while (head != NULL)
                {
                    struct Node* temp = head;
                    head = head->next;
                    free(temp);
                }
                printf("Exiting program. Memory freed.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
// Helper function to create a new node
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct Node* findNode(int data)
{
    struct Node* temp = head;
    while (temp != NULL)
        {
        if (temp->data == data)
            {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
// Functions for Linked List
void createList()
 {
    int n, data, i;
    struct Node* temp;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    if (n <= 0)
    {
        printf("Minimum Number of Nodes Must Be atleast 3 .\n");
        return;
    }
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    for (i = 0; i < n; i++)
    {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }
    printf("List created with %d nodes.\n", n);
}
void displayList()
{
    struct Node* temp = head;
    if (temp == NULL)
    {
        printf("List is empty.");
        return;
    }
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
         {
            printf(" --> ");
        }
        temp = temp->next;
    }
    printf(" --> NULL");
}
int search(int key)
 {
    struct Node* temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp; 
        } 
        temp = temp->next;
    }
    return 0;
}
int countNodes()
 {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void displayAlternateNodes()
 {
    struct Node* temp = head;
    int count = 1;
    if (temp == NULL)
    {
        printf("List is empty.");
        return;
    }
    while (temp != NULL)
    {
        if (count % 2 != 0)
         {
            printf("%d ", temp->data);
        }
        temp = temp->next;
        count++;
    }
}
void displayEvenPositionNodes()
 {
    struct Node* temp = head;
    int count = 1;
    if (temp == NULL)
    {
        printf("List is empty.");
        return;
    }
    while (temp != NULL)
    {
        if (count % 2 == 0)
        {
            printf("%d ", temp->data);
        }
        temp = temp->next;
        count++;
    }
}
int findMiddleNode()
 {
    if (head == NULL)
        return -1;

    int count = 0;
    struct Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    int middleIndex = count / 2;
    temp = head;

    for (int i = 0; i < middleIndex; i++)
    {
        temp = temp->next;
    }

    return temp->data;
}
void insertAtBeginning(int data)
 {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(int data)
{
    struct Node* newNode = createNode(data);

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
}
void insertAfterNode(int key, int data)
{
    struct Node* temp = head;
    while (temp != NULL && temp->data != key)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", key);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node inserted after %d.\n", key);
}
void insertBeforeNode(int key, int data)
 {
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->data == key)
    {
        insertAtBeginning(data);
        printf("Node inserted before %d.\n", key);
        return;
    }
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr != NULL && curr->data != key)
    {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL)
    {
        printf("Node with value %d not found.\n", key);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = curr;
    prev->next = newNode;

    printf("Node inserted before %d.\n", key);
}
void insertBetweenNodes(int value1, int value2, int newData)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    struct Node* node1 = findNode(value1);
    struct Node* node2 = findNode(value2);
    if (node1 == NULL)
    {
        printf("Node with value %d not found.\n", value1);
        return;
    }
    if (node2 == NULL)
    {
        printf("Node with value %d not found.\n", value2);
        return;
    }
    // Check if node2 comes after node1
    if (node1->next != node2)
    {
        printf("Node with value %d is not immediately after node with value %d.\n", value2, value1);
        return;
    }
    struct Node* newNode = createNode(newData);
    newNode->next = node2;
    node1->next = newNode;
    printf("Node with value %d inserted between nodes with values %d and %d.\n", newData, value1, value2);
}
void insertAtPosition(int position, int data)
 {
    if (position < 1)
    {
        printf("Invalid position. Position should be >= 1.\n");
        return;
    }
    struct Node* newNode = createNode(data);
    // Insert at the beginning
    if (position == 1)
    {
        newNode->next = head;
        head = newNode;
        printf("Node with value %d inserted at position %d.\n", data, position);
        return;
    }
    // Find the position to insert
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Position %d is out of bounds.\n", position);
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Node with value %d inserted at position %d.\n", data, position);
}


