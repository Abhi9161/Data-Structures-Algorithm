#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    void LinkedlistTraversal(Node *head)
    {
        Node *ptr = head;
        do
        {
            cout << "Element: " << ptr->data << endl;
            ptr = ptr->next;
        } while (ptr != head);
        cout << endl;
    }

    //Case 1 Inserting the element at the first position in a Circular Linked List
    Node *insertAtFirst(Node *head, int data)
    {
        Node *ptr = new Node;
        ptr->data = data;
        Node *p = head->next;
        while (p->next != head)
        {
            p = p->next;
        }
        //At this point p points to the last node of this circular Linked List
        p->next = ptr;
        ptr->next = head;
        head = ptr;
        return head;
    }

    //Case 2 Inserting the element at the given index in a Circular Linked List
    Node *inserAtIndex(Node *head, int data, int index)
    {
        Node *ptr = new Node;
        ptr->data = data;
        Node *p = head;
        int i = 0;
        while (i != index - 1)
        {
            p = p->next;
            i++;
        }
        ptr->next = p->next;
        p->next = ptr;
        return head;
    }

    //Case 3 Inserting the element at the end in a Circular Linked List
    Node *insertAtEnd(Node *head, int data)
    {
        Node *ptr = new Node;
        ptr->data = data;
        Node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        p->next = ptr;
        ptr->next = head;
        return head;
    }

    //Case 4 Inserting the element after a node in a Circular Linked List
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
    Node *fourth;
    Node n;
    //Allocate memory for nodes in the linked list in Heap
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    //Link first and second nodes
    head->data = 7;
    head->next = second;

    //Link second and third nodes
    second->data = 11;
    second->next = third;

    //Link third node and fourth nodes
    third->data = 66;
    third->next = fourth;

    //Terminate the list at the fourth node
    fourth->data = 54;
    fourth->next = head;

    cout << "Circular Linked List before Insertion :" << endl;
    n.LinkedlistTraversal(head);
    // head = n.insertAtFirst(head, 56);
    // n.inserAtIndex(head, 45, 1);
    // n.insertAtEnd(head, 45);
    n.insertAfteraNode(head, second, 10);
    cout << "Circular Linked List after Insertion :" << endl;
    n.LinkedlistTraversal(head);
    return 0;
}