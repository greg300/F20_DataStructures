#include <stdio.h>
#include <stdlib.h>

// A Linked List node to hold integers.
struct Node {
    int data;
    struct Node *next;
};

// Create a new node at the front of the Linked List referenced by front.
struct Node *addToFront(struct Node *front, int newData)
{
    // Create the new node, and allocate space for it in memory.
    struct Node *newNode = malloc(sizeof(struct Node));
    
    // Insert the data into the new node.
    newNode -> data = newData;
    
    // Set the new node's next to be the current front.
    newNode -> next = front;
    
    // Set the front to be the new node.
    return newNode;
}

// Remove first occurrence of a specified node from the Linked List referenced by front.
struct Node *removeNode(struct Node *front, int target)
{
    struct Node *current = front;
    struct Node *prev = NULL;
    
    // If front contains the target, delete it and return the next node as the new front.
    if (current != NULL && current -> data == target)
    {
        front = front -> next;
        free(current);
        return front;
    }
    
    // Otherwise, search for the target among the rest of the nodes.
    // Keep a reference to the previous.
    while (current != NULL && current -> data != target)
    {
        prev = current;
        current = current -> next;
    }
    
    // If key was not present in the Linked List:
    if (current == NULL)
        return front;
        
    // Otherwise, unlink the node from the Linked List and free the memory.
    prev -> next = current -> next;
    free(current);
    
    return front;
}

// Traverse the Linked List referenced by front.
void printList(struct Node *front)
{
    struct Node *current = front;
    while (current != NULL)
    {
        // Print the current node's data.
        printf("%d ", current -> data);
        
        // Advance to the next node.
        current = current -> next;
    }
    printf("\n");
}


int main()
{
    // Create a new Linked List.
    struct Node *front = addToFront(front, 3);
    front = addToFront(front, 6);
    front = addToFront(front, 8);
    
    printList(front);
    
    front = removeNode(front, 3);
    printList(front);
    
    front = removeNode(front, 8);
    printList(front);
    
    front = removeNode(front, 2);
    printList(front);
    
    front = removeNode(front, 6);
    printList(front);

    return 0;
}