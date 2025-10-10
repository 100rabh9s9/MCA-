#include <stdio.h>
#include <stdlib.h>
//--Doubly Linked List--//
struct Node
{
    int data;
    struct Node* prev; // Point to previous Node 
    struct Node* next;
};
struct Node* head = NULL;

void CreateList(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
{
    printf("Memory allocation failed!\n");
    return;
   }
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

void display()
 {
    struct Node* temp = head;
    if (temp == NULL)
    {
        printf("\nList is empty.\n");
        return;
    }
    printf("Doubly Linked List: ");
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <--> ");
        temp = temp->next;
    }
    printf("\n");
}

void search(int value)  //Helper Function for Searching a value 
{
    struct Node* temp = head;
    int position = 1;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Value %d found at position %d.\n", value, position);
            return;
        }
        temp = temp->next;
        position++;
    }
    printf("Value %d not found in the list.\n", value);
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
    if (temp == NULL) {
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
        }
        else
        {
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
    while (temp != NULL) {
        if (count % 2 == 0) {
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
        return -1; // Empty list
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
void insertAtBeginning(int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        {
           head->prev = newNode;
        }
        head = newNode;
}

void insertAtEnd(int value)
{
     CreateList(value);
}

void insertAfterNode(int prevValue, int newValue)
{
    struct Node* temp = head;

    while (temp != NULL && temp->data != prevValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", prevValue);
        return;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newValue;
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void insertBeforeNode(int nextValue, int newValue)
 {
    struct Node* temp = head;

    while (temp != NULL && temp->data != nextValue)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Node with value %d not found.\n", nextValue);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newValue;
    newNode->prev = temp->prev;
    newNode->next = temp;

    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }

    temp->prev = newNode;
}

void insertBetweenNodes(int firstValue, int secondValue, int newValue)
{
    struct Node* firstNode = head;

    while (firstNode != NULL && firstNode->data != firstValue)
    {
        firstNode = firstNode->next;
    }
    if (firstNode == NULL)
    {
        printf("Node with value %d not found.\n", firstValue);
        return;
    }
    if (firstNode->next == NULL || firstNode->next->data != secondValue)
    {
        printf("Error: Nodes %d and %d are not adjacent.\n", firstValue, secondValue);
        return;
    }
    struct Node* secondNode = firstNode->next;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = newValue;

    newNode->prev = firstNode;
    newNode->next = secondNode;
    firstNode->next = newNode;
    secondNode->prev = newNode;
}
void insertAtPosition(int position, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (position == 1)
    {
        newNode->next = head;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    struct Node* temp = head;
    int count = 1;
    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
    {
        printf("Position %d is out of range.\n", position);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }

    temp->next = newNode;
}

void deleteFirstNode()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    int deletedValue = temp->data;
    head = head->next;

    if (head != NULL)
    {
        head->prev = NULL;
    }

    free(temp);
    printf("Deleted first node with value: %d\n", deletedValue);
}

void deleteLastNode()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
     {
        temp = temp->next;
    }
    int deletedValue = temp->data;

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }

    free(temp);
    printf("Deleted last node with value: %d\n", deletedValue);
}

void deleteAfterNode(int prevValue)
{
    struct Node* temp = head;

    while (temp != NULL && temp->data != prevValue)
    {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
        {
        printf("Node with value %d or the node after it not found.\n", prevValue);
        return;
    }

    struct Node* nodeToDelete = temp->next;
     int deletedValue = nodeToDelete->data;
    temp->next = nodeToDelete->next;

    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = temp;
    }

    free(nodeToDelete);
    printf("Deleted node (%d) after node (%d).\n", deletedValue, prevValue);
}

void deleteBeforeNode(int nextValue)
{
    if (head == NULL || head->next == NULL)
    {
        printf("Cannot delete: list has fewer than 2 nodes.\n");
        return;
    }

    struct Node* targetNode = head;

    while (targetNode != NULL && targetNode->data != nextValue) {
        targetNode = targetNode->next;
    }

    if (targetNode == NULL || targetNode == head)
    {
        printf("Node with value %d not found or it is the head.\n", nextValue);
        return;
    }

    struct Node* nodeToDelete = targetNode->prev;
    int deletedValue = nodeToDelete->data;

    struct Node* prevNode = nodeToDelete->prev;

    targetNode->prev = prevNode;

    if (prevNode == NULL)
    {
        head = targetNode;
    }
     else
    {
        prevNode->next = targetNode;
    }
    free(nodeToDelete);
    printf("Deleted node (%d) before node (%d).\n", deletedValue, nextValue);
}

void deleteAtPosition(int position)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    int deletedValue;
    int count = 1;

    if (position == 1)
        {
            deletedValue = temp->data;
            head = temp->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        return;
    }

    while (temp != NULL && count < position)
    {
        temp = temp->next;
        count++;
    }
    if (temp == NULL)
    {
        printf("Position %d is out of range.\n", position);
        return;
    }
        deletedValue = temp->data;

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Deleted node with value %d at position %d.\n", deletedValue, position);
}

void reverseList()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        head = temp->prev;
    }
    display();
}

int main()
{
    int choice, value, n, position, prevValue, nextValue, firstValue, secondValue;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create and display the list\n");
        printf("2. Search for a value\n");
        printf("3. Count No of Nodes\n");
        printf("4. Display Alternate Nodes\n");
        printf("5. Display Even Position Nodes\n");
        printf("6. Find Middle Node\n");
        
        printf("7. Insert a new node as the first node\n");
        printf("8. Insert a new node as the last node\n");
        printf("9. Insert a node after a given node\n");
        printf("10. Insert a node before a given node\n");
        printf("11. Insert a node between two nodes\n");
        printf("12. Insert a node at a particular position\n");
        
        printf("13. Delete the first node\n");
        printf("14. Delete the last node\n");
        printf("15. Delete a node after a given node\n");
        printf("16. Delete a node before a given node\n");
        printf("17. Delete a node at a particular position\n");
        
        printf("18. Reverse the list\n");
        printf("19.Display List\n ");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter the number of elements to insert: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++)
                {
                    printf("Enter value %d: ", i + 1);
                    scanf("%d", &value);
                    CreateList(value);
                }
                break;
            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 3:
                printf("Total No of Nodes: %d\n", countNodes());
                break;
            case 4:
                displayAlternateNodes();
                break;
            case 5:
                displayEvenPositionNodes();
                break;
            case 6:
                value = findMiddleNode();
                if (value != -1)
                    {
                    printf("Middle node value: %d\n", value);
                }
                else
                {
                    printf("List is empty.\n");
                }
                break;
            case 7:
                printf("Enter value to insert at the beginning: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 8:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 9:
                printf("Enter the value after which to insert: ");
                scanf("%d", &prevValue);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertAfterNode(prevValue, value);
                break;
            case 10:
                printf("Enter the value before which to insert: ");
                scanf("%d", &nextValue);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                insertBeforeNode(nextValue, value);
                break;
            case 11:
                printf("Enter the first node value: ");
                scanf("%d", &firstValue);
                printf("Enter the second node value: ");
                scanf("%d", &secondValue);
                printf("Enter the value to insert between the nodes: ");
                scanf("%d", &value);
                insertBetweenNodes(firstValue, secondValue, value);
                break;
            case 12:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtPosition(position, value);
                break;
            case 13:
                deleteFirstNode();
                break;
            case 14:
                deleteLastNode();
                break;
            case 15:
                printf("Enter the value after which to delete node: ");
                scanf("%d", &prevValue);
                deleteAfterNode(prevValue);
                break;
            case 16:
                printf("Enter the value before which to delete node: ");
                scanf("%d", &nextValue);
                deleteBeforeNode(nextValue);
                break;
            case 17:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(position);
                break;
            case 18:
                reverseList();
                break;
            case 19: display();
                    break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}

