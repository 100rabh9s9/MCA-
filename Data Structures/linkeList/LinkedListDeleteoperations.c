#include <stdio.h>
#include <stdlib.h>

struct Node //BluePrint
 {
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
 {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
//Perform  insertions to create a LL to perform the Deletion Operations (Since Only Deletion is performed here)
void insertAtBeginning(struct Node** head, int data)
 {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(struct Node** head, int data)
 {
    struct Node* newNode = createNode(data);
    if (*head == NULL)
        {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
//To Display the List
void displayList(struct Node* head)
 {
    if (head == NULL)
        {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;
    printf("List: ");
    while (temp != NULL)
        {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
// To find if a node is there or not (Similar to search)
struct Node* findNode(struct Node* head, int data)
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
// To get length of LL
int getLength(struct Node* head)
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

// 1. Delete First Node
struct Node* deleteFirstNode(struct Node* head)
{
    if (head == NULL)
        {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("First node deleted successfully.\n");
    return head;
}

// 2. Delete Last Node
struct Node* deleteLastNode(struct Node* head)
{
    if (head == NULL)
        {
        printf("List is empty. Nothing to delete.\n");
        return head;
    }

    // If only one node exists
    if (head->next == NULL)
        {
        free(head);
        printf("Last node (only node) deleted successfully.\n");
        return NULL;
    }

    // Traverse to the second last node
    struct Node* temp = head;
    while (temp->next->next != NULL)
        {
        temp = temp->next;
    }

    // Delete the last node
    free(temp->next);
    temp->next = NULL;
    printf("Last node deleted successfully.\n");
    return head;
}

// 3. Delete node after a given node
void deleteAfterNode(struct Node* prevNode)
{
    if (prevNode == NULL)
        {
        printf("Previous node cannot be NULL.\n");
        return;
    }

    if (prevNode->next == NULL)
        {
        printf("No node exists after the given node.\n");
        return;
    }

    struct Node* nodeToDelete = prevNode->next;
    prevNode->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node after the given node deleted successfully.\n");
}

// 4. Delete node before a given node
struct Node* deleteBeforeNode(struct Node* head, struct Node* targetNode)
 {
    if (head == NULL || targetNode == NULL)
        {
        printf("List is empty or target node is NULL.\n");
        return head;
    }

    // If target node is the first node
    if (head == targetNode)
        {
        printf("No node exists before the first node.\n");
        return head;
    }

    // If second node is the target node
    if (head->next == targetNode)
        {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node before the given node deleted successfully.\n");
        return head;
    }

    // Find the node before the target node's previous node
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->next != targetNode)
        {
        temp = temp->next;
    }

    if (temp->next == NULL || temp->next->next != targetNode)
        {
        printf("Target node not found in the list.\n");
        return head;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node before the given node deleted successfully.\n");
    return head;
}

// 5. Delete node between two nodes
struct Node* deleteBetweenNodes(struct Node* head, struct Node* node1, struct Node* node2)
{
    if (head == NULL || node1 == NULL || node2 == NULL)
        {
        printf("Invalid input. List or nodes are NULL.\n");
        return head;
    }
    if (node1->next == node2)
        {
        printf("No node exists between the given nodes.\n");
        return head;
    }
    if (node1->next == NULL)
        {
        printf("No node exists after the first node.\n");
        return head;
    }
    // Delete the node after node1 (which should be before node2)
    struct Node* nodeToDelete = node1->next;
    if (nodeToDelete == node2)
        {
        printf("No node exists between the given nodes.\n");
        return head;
    }
    node1->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node between the given nodes deleted successfully.\n");
    return head;
}
// 6. Delete node at a given position (1-indexed)
struct Node* deleteAtPosition(struct Node* head, int position)
 {
    if (head == NULL)
        {
        printf("List is empty.\n");
        return head;
    }

    if (position < 1)
        {
        printf("Invalid position. Position should be >= 1.\n");
        return head;
    }
    // If deleting the first node
    if (position == 1)
        {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Node at position %d deleted successfully.\n", position);
        return head;
    }
    // Traverse to the node before the target position
    struct Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL)
        {
        printf("Position %d is out of bounds.\n", position);
        return head;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node at position %d deleted successfully.\n", position);
    return head;
}

// 7. Reverse the linked list
struct Node* reverseList(struct Node* head)
 {
    if (head == NULL || head->next == NULL)//Check if anything exist in list 
        {
        printf("List is empty or has only one node.\n");
        return head;
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

    printf("List reversed successfully.\n");
    return prev; // prev is now the new head
}

int main()
{
    struct Node* head = NULL;
    int choice, data, position;
    struct Node* node1, * node2, * targetNode;
 
    printf("Creating a list: \n");
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    insertAtEnd(&head, 50);
    displayList(head);

    while (1)
        {
        printf("\nLINKED LIST DELETE OPERATIONS\n");
        printf("1. Delete First Node\n");
        printf("2. Delete Last Node\n");
        printf("3. Delete Node After Given Node\n");
        printf("4. Delete Node Before Given Node\n");
        printf("5. Delete Node Between Two Nodes\n");
        printf("6. Delete Node at Given Position\n");
        printf("7. Reverse the List\n");
        printf("8. Display List\n");
        printf("9. Insert Node at End (for testing)\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
         {
            case 1:
                head = deleteFirstNode(head);
                displayList(head);
                break;

            case 2:
                head = deleteLastNode(head);
                displayList(head);
                break;

            case 3:
                printf("Enter the data of the node after which to delete: ");
                scanf("%d", &data);
                targetNode = findNode(head, data);
                if (targetNode != NULL)
                    {
                    deleteAfterNode(targetNode);
                    displayList(head);
                }
                else
                {
                    printf("Node with data %d not found.\n", data);
                }
                break;

            case 4:
                printf("Enter the data of the node before which to delete: ");
                scanf("%d", &data);
                targetNode = findNode(head, data);
                if (targetNode != NULL)
                    {
                    head = deleteBeforeNode(head, targetNode);
                    displayList(head);
                }
                else
                {
                    printf("Node with data %d not found.\n", data);
                }
                break;

            case 5:
                printf("Enter the data of the first node: ");
                scanf("%d", &data);
                node1 = findNode(head, data);
                printf("Enter the data of the second node: ");
                scanf("%d", &data);
                node2 = findNode(head, data);
                if (node1 != NULL && node2 != NULL)
                {
                    head = deleteBetweenNodes(head, node1, node2);
                    displayList(head);
                }
                else
                {
                    printf("One or both nodes not found.\n");
                }
                break;

            case 6:
                printf("Enter the position to delete (1-indexed): ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                displayList(head);
                break;

            case 7:
                head = reverseList(head);
                displayList(head);
                break;

            case 8:
                displayList(head);
                break;

            case 9:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                displayList(head);
                break;

            case 10:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}



