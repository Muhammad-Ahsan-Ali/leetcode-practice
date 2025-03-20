#include <iostream>
using namespace std;

// Definition for a Node.

class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;
};

void sol(Node *curr, Node *&newLstNode)
{

    if (curr == NULL)
    {
        return;
    }

    // Save the next node

    Node *nextNode = curr->next;

    newLstNode->next = curr;
    curr->prev = newLstNode;
    newLstNode = newLstNode->next;

    if (curr->child != NULL)
    {
        sol(curr->child, newLstNode);
        curr->child = NULL;
    }

    sol(nextNode, newLstNode);
}

Node *flatten(Node *head)
{

    Node *newLstNode = head;

    sol(head, newLstNode);

    return head;
}

void sol(Node *curr, Node *&newLstNode)
{
    if (curr == NULL)
    {
        return;
    }

    // Save the next node
    Node *nextNode = curr->next;

    // Connect the current node to the new flattened list
    newLstNode->next = curr;
    curr->prev = newLstNode;

    // Move the newLstNode pointer to the current node
    newLstNode = newLstNode->next;

    // If the current node has a child, recursively flatten the child list
    if (curr->child != NULL)
    {
        sol(curr->child, newLstNode);
        curr->child = NULL; // Set child to NULL after processing
    }

    // Continue flattening with the next node
    sol(nextNode, newLstNode);
}

Node *flatten(Node *head)
{
    if (head == NULL)
        return NULL; // Check for an empty list

    Node *newLstNode = new Node(); // Create a dummy node
    Node *headPtr = newLstNode;    // Save the head of the new list

    sol(head, newLstNode); // Start the flattening process

    headPtr->next->prev = NULL; // The head of the new list should have no prev

    // Clean up dummy node
    Node *flattenedHead = headPtr->next;
    delete headPtr; // Delete the dummy node

    return flattenedHead; // Return the head of the flattened list
}

int main()
{
    return 0;
}