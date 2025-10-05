#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};


struct Node* head = NULL;

struct Node* createNode(int data);
struct Node* findNode(int data);


void createList();
void displayList();
int search(int key);
int countNodes();
void insertAtBeginning(int data);
void insertAtEnd(int data);
void insertAfterNode(int key, int data);
void insertBeforeNode(int key, int data);
void insertAtPosition(int position, int data);
void insertBetweenNodes(int val1, int val2, int newData);
void deleteFirstNode();
void deleteLastNode();
void deleteNodeWithValue(int key);
void deleteAfterNode(int key);
void deleteBeforeNode(int key);
void deleteBetweenNodes(int val1, int val2);
void deleteAtPosition(int position);
void reverseList();
void displayAlternateNodes();
void displayEvenPositionNodes();
int findMiddleNode();



int main()
{
    int ch, data, key, pos,val1,val2,newData;

    while (1)
    {
        printf("\n---Linked List Menu ---\n");

        printf(" 1. Create a new list (overwrites existing)\n");
        printf(" 2. Insert at the beginning\n");
        printf(" 3. Insert at the end\n");
        printf(" 4. Insert after a specific value\n");
        printf(" 5. Insert before a specific value\n");
        printf(" 6. Insert at a specific position\n");

        printf(" 7. Delete the first node\n");
        printf(" 8. Delete the last node\n");
        printf(" 9. Delete a node with a specific value\n");
        printf("10. Delete a node at a specific position\n");


        printf("11. Display the list\n");
        printf("12. Display alternate nodes (from 1st)\n");
        printf("13. Display even positioned nodes\n");
        printf("14. Find the middle node's value\n");
        printf("15. Search for a value\n");
        printf("16. Count the number of nodes\n");
        printf("17. Reverse the list\n");

        printf("18. Insert a node BETWEEN two nodes\n");
        printf("19. Delete the node BETWEEN two nodes\n");
        printf("20. Delete After a Node \n");
        printf("21. Delete Before a Node \n ");

        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch(ch)
         {
            case 1: createList(); break;
            case 2:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter value to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter node value after which to insert: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAfterNode(key, data);
                break;
            case 5:
                printf("Enter node value before which to insert: ");
                scanf("%d", &key);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertBeforeNode(key, data);
                break;
            case 6:
                printf("Enter position to insert at (1-indexed): ");
                scanf("%d", &pos);
                printf("Enter value to insert: ");
                scanf("%d", &data);
                insertAtPosition(pos, data);
                break;
            case 7: deleteFirstNode(); break;
            case 8: deleteLastNode(); break;
            case 9:
                printf("Enter the value of the node to delete: ");
                scanf("%d", &key);
                deleteNodeWithValue(key);
                break;
            case 10:
                printf("Enter the position to delete (1-indexed): ");
                scanf("%d", &pos);
                deleteAtPosition(pos);
                break;
            case 11: displayList(); break;
            case 12: displayAlternateNodes(); break;
            case 13: displayEvenPositionNodes(); break;
            case 14:
                data = findMiddleNode();
                if (data != -1) printf("Middle node value: %d\n", data);
                else printf("List is empty.\n");
                break;
            case 15:
                printf("Enter value to search: ");
                scanf("%d", &data);
                if (search(data)) printf("✅ %d found in the list.\n", data);
                else printf("  %d not found in the list.\n", data);
                break;
            case 16:
                printf("Total number of nodes: %d\n", countNodes());
                break;
            case 17: reverseList(); break;
            case 18:
                printf("Enter value of first node: ");
                scanf("%d", &val1);
                printf("Enter value of second node: ");
                scanf("%d", &val2);
                printf("Enter data for the new node to insert: ");
                scanf("%d", &newData);
                insertBetweenNodes(val1, val2, newData);
                break;
            case 19:
                printf("Enter value of first node: ");
                scanf("%d", &val1);
                printf("Enter value of second node: ");
                scanf("%d", &val2);
                deleteBetweenNodes(val1, val2);
                break;
            case 20:
                printf("Enter key (after which to delete): ");
                scanf("%d", &key);
                deleteAfterNode(key);
                break;
            case 21:
                printf("Enter key (before which to delete): ");
                scanf("%d", &key);
                deleteBeforeNode(key);
            break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

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

void createList()
 {
    int n, data, i;
    while (head != NULL)
        {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    printf("Enter number of nodes to create: ");
    scanf("%d", &n);
    if (n <= 0) return;
    for (i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(data);
    }
    printf(" List created with %d nodes.\n", n);
}

void displayList()
 {
    struct Node* temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("HEAD -> ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int search(int key)
{
    return (findNode(key) != NULL);
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

void insertAtBeginning(int data)
{
    struct Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
    printf(" Node inserted at the beginning.\n");
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
    struct Node* prevNode = findNode(key);
    if (prevNode == NULL)
    {
        printf("  Node with value %d not found.\n", key);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    printf(" Node inserted after %d.\n", key);
}

void insertBeforeNode(int key, int data)
{
    if (head == NULL)
    {
        printf("  List is empty.\n");
        return;
    }
    if (head->data == key)
     {
        insertAtBeginning(data);
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data != key)
     {
        temp = temp->next;
    }
    if (temp->next == NULL)
    {
        printf("  Node with value %d not found.\n", key);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf(" Node inserted before %d.\n", key);
}
void insertBetweenNodes(int val1, int val2, int newData)
{
    struct Node* temp = head;

    while (temp != NULL && temp->data != val1)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", val1);
        return;
    }

    if (temp->next == NULL || temp->next->data != val2)
    {
        printf("%d and %d are not consecutive nodes.\n", val1, val2);
        return;
    }

    struct Node* newNode = createNode(newData);
    newNode->next = temp->next;
    temp->next = newNode;

    printf("Node %d inserted between %d and %d.\n", newData, val1, val2);
}
void insertAtPosition(int position, int data)
 {
    if (position < 1)
    {
        printf("  Invalid position. Position must be >= 1.\n");
        return;
    }
    if (position == 1)
    {
        insertAtBeginning(data);
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("  Position %d is out of bounds.\n", position);
        return;
    }
    struct Node* newNode = createNode(data);
    newNode->next = temp->next;
    temp->next = newNode;
    printf(" Node inserted at position %d.\n", position);
}

void deleteFirstNode()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf(" ️ First node deleted successfully.\n");
}

void deleteLastNode()
 {
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if (head->next == NULL)
     {
        free(head);
        head = NULL;
        printf("️ Last node (the only node) deleted successfully.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf(" ️ Last node deleted successfully.\n");
}

void deleteNodeWithValue(int key)
 {
    struct Node* nodeToDelete = findNode(key);
    if (nodeToDelete == NULL)
    {
        printf("  Node with value %d not found.\n", key);
        return;
    }
    if (nodeToDelete == head)
    {
        deleteFirstNode();
        return;
    }
    struct Node* temp = head;
    while (temp->next != nodeToDelete)
    {
        temp = temp->next;
    }
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf(" ️ Node with value %d deleted successfully.\n", key);
}

void deleteAfterNode(int key)
{
    struct Node* temp = head;
    // find the node with given key
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL)
    {
        printf(" Node with value %d not found.\n", key);
        return;
    }
    if (temp->next == NULL)
    {
        printf(" No node exists after %d.\n", key);
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    printf(" Node with value %d deleted (after %d).\n", delNode->data, key);
    free(delNode);
}
void deleteBeforeNode(int key)
{
    if (head == NULL || head->next == NULL)
    {
        printf(" Not enough nodes to delete before %d.\n", key);
        return;
    }

    if (head->next->data == key)
    {
        struct Node* delNode = head;
        head = head->next;
        printf(" Node with value %d deleted (before %d).\n", delNode->data, key);
        free(delNode);
        return;
    }

    struct Node* temp = head;
    while (temp->next->next != NULL && temp->next->next->data != key)
        temp = temp->next;

    if (temp->next->next == NULL)
    {
        printf(" Node with value %d not found.\n", key);
        return;
    }

    struct Node* delNode = temp->next;
    temp->next = delNode->next;
    printf(" Node with value %d deleted (before %d).\n", delNode->data, key);
    free(delNode);
}
void deleteBetweenNodes(int val1, int val2)
{
    struct Node* temp = head;


    while (temp != NULL && temp->data != val1)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL || temp->next->next == NULL)
    {
        printf("Nodes not found or not enough nodes to delete between.\n");
        return;
    }


    struct Node* middle = temp->next;
    if (middle->next->data != val2)
    {
        printf("No node exactly between %d and %d.\n", val1, val2);
        return;
    }

    temp->next = middle->next;
    free(middle);

    printf("Node between %d and %d deleted.\n", val1, val2);
}
void deleteAtPosition(int position)
 {
    if (head == NULL || position < 1)
    {
        printf("List is empty or position is invalid.\n");
        return;
    }
    if (position == 1)
    {
        deleteFirstNode();
        return;
    }
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL)
    {
        printf(" Position %d is out of bounds.\n", position);
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf(" ️ Node at position %d deleted successfully.\n", position);
}

void reverseList()
{
    if (head == NULL || head->next == NULL)
    {
        printf("List is empty or has only one node, no need to reverse.\n");
        return;
    }
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;

    printf("List reversed successfully.\n");
    displayList();
}

void displayAlternateNodes()
 {
    struct Node* temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Alternate nodes: ");
    while (temp != NULL)
     {
        printf("%d ", temp->data);
        if (temp->next != NULL)
        {
            temp = temp->next->next;
        } else {
            temp = NULL;
        }
    }
    printf("\n");
}

void displayEvenPositionNodes()
 {
    struct Node* temp = head;
    int count = 1;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Even positioned nodes: ");
    while (temp != NULL)
     {
        if (count % 2 == 0)
        {
            printf("%d ", temp->data);
        }
        temp = temp->next;
        count++;
    }
    printf("\n");
}

int findMiddleNode()
{
    if (head == NULL)
    {
        return -1; // empty list
    }
    struct Node* L_ptr = head;
    struct Node* R_ptr = head;
    while (R_ptr != NULL && R_ptr->next != NULL)
     {
        R_ptr = R_ptr->next->next;
        L_ptr = L_ptr->next;
    }
    return L_ptr->data;
}
