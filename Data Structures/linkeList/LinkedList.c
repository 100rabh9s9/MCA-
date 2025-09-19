#include <stdio.h>
#include <stdlib.h>

struct Node
 {
     int data; struct Node* next;
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

int main()

{
 int ch, data, key, pos, found;
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
        default:
            printf("Invalid choice! Try again.\n");
    }
}

return 0;
}
//Functions for Linked List//
void createList()
{
    int n, data, i;
    struct Node* temp;
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    if (n <= 0)
    {
         printf("Number of nodes must be positive.\n");
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
        printf("%d --> ", temp->data);
        temp = temp->next;
        }
 }

int search(int key)
 {
     struct Node* temp = head;
     while (temp != NULL)
        {
          if (temp->data == key)
              return 1;
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
      while (temp != NULL)
        {
            if (count % 2 != 0)
            printf("%d ", temp->data);
            temp = temp->next;
            count++;
          }
 }

void displayEvenPositionNodes()
{
    struct Node* temp = head;
    int count = 1;
    while (temp != NULL)
        {
            if (count % 2 == 0)
               printf("%d ", temp->data);
                temp = temp->next;
                count++;
            }
 }
int findMiddleNode()
{
    if (head == NULL)
        return -1;
    int len = countNodes();
    int mid = len / 2;

    struct Node* temp = head;
    for (int i = 0; i < mid; i++)
        {
        temp = temp->next;
    }
    return temp->data;
}

void insertAtBeginning(int data)
{
 struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
     }
void insertAtEnd(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
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
}
void insertAfterNode(int key, int data)
 {
      struct Node* temp = head;
        while (temp != NULL && temp->data != key)

            temp = temp->next;
            if (temp == NULL)
        {
            printf("Node with value %d not found.\n", key);
            return;
            }

struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = temp->next;
temp->next = newNode;

printf("Node inserted after %d.\n", key);
}

void insertBeforeNode(int key, int data)
{ if (head == NULL)
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

struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = curr;
prev->next = newNode;

printf("Node inserted before %d.\n", key);
  }
