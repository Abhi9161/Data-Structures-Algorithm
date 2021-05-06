#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void LinkedlistTraversal(Node *ptr)
    {
        while (ptr != NULL)
        {
            cout << "Element: " << ptr->data << endl;
            ptr = ptr->next;
        }
        cout << endl;
    }

    //Case 1 Inserting the element at the first position in a Singly Linked List
    Node *insertAtFirst(Node *head, int data)
    {
        Node *ptr = new Node;
        ptr->next = head;
        ptr->data = data;
        return ptr;
    }

    //Case 2 Inserting the element at the given Index in a Singly Linked List
    Node *inserAtIndex(Node *head, int data, int index)
    {
        Node *ptr = new Node;
        Node *p = head;
        int i = 0;
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        ptr->data = data;
        ptr->next = p->next;
        p->next = ptr;
        return head;
    }

    //Case 3 Inserting the element at the end in a Singly Linked List
    Node *insertAtEnd(Node *head, int data)
    {
        Node *ptr = new Node;
        ptr->data = data;
        Node *p = head;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = NULL;
        return head;
    }

    //Case 4 Inserting the element after a node value in a Singly Linked List
    Node *insertAfteraNode(Node *head, Node *prevNode, int data)
    {
        Node *ptr = new Node;
        ptr->data = data;
        ptr->next = prevNode->next;
        prevNode->next = ptr;
        return head;
    }
};
int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node n;
    //Allocate memory for nodes in the linked list in Heap
    head = new Node;
    second = new Node;
    third = new Node;

    //Link first and second nodes
    head->data = 7;
    head->next = second;

    //Link second and third nodes
    second->data = 11;
    second->next = third;

    //Terminate the list at the third node
    third->data = 66;
    third->next = NULL;

    cout << "Linked List before Insertion :" << endl;
    n.LinkedlistTraversal(head);
    // head = n.insertAtFirst(head, 56);
    // n.inserAtIndex(head, 45, 1);
    // n.insertAtEnd(head, 45);
    n.insertAfteraNode(head, second, 10);
    cout << "Linked List after Insertion :" << endl;
    n.LinkedlistTraversal(head);
    return 0;
}