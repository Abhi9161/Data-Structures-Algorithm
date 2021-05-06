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

    //Case 1 Deleting the element at the first position in a Circular Linked List
    Node *deleteAtFirst(Node *head)
    {

        Node *p = head->next;
        while (p->next != head)
        {
            p = p->next;
        }
        Node *ptr = head;
        head = head->next;
        p->next = head;
        free(ptr);
        return head;
    }

    //Case 2 Deleting the element at the given index in a Circular Linked List
    Node *deleteAtIndex(Node *head, int index)
    {
        Node *p = head;
        Node *q = head->next;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
        return head;
    }

    //Case 3 Deleting the element at the end in a Circular Linked List
    Node *deleteAtEnd(Node *head)
    {
        Node *p = head;
        Node *q = head->next;
        while (q->next != head)
        {
            p = p->next;
            q = q->next;
        }
        p->next = q->next;
        free(q);
        return head;
    }

    //Case 4 Deleting the element after a node in a Circular Linked List
    Node *deleteAfteraNode(Node *head, int value)
    {

        Node *p = head;
        Node *q = head->next;
        while (q->data != value && q->next != head)
        {
            p = p->next;
            q = q->next;
        }
        if (q->data == value)
        {
            p->next = q->next;
            free(q);
        }
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

    cout << "Circular Linked List before Deletion :" << endl;
    n.LinkedlistTraversal(head);
    head = n.deleteAtFirst(head);
    // n.deleteAtIndex(head, 1);
    // n.deleteAtEnd(head);
    // n.deleteAfteraNode(head, 11);
    cout << "Circular Linked List after Deletion :" << endl;
    n.LinkedlistTraversal(head);
    return 0;
}