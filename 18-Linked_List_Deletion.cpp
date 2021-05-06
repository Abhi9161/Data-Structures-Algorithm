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

    //Case 1 Deleting the element at the first position
    Node *deleteAtFirst(Node *head)
    {
        Node *ptr = head;
        head = head->next;
        free(ptr);
        return head;
    }

    //Case 2 Deleting the element at a given index
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

    //Case 3 Deleting the element at the end
    Node *DeleteAtEnd(Node *head)
    {

        Node *p = head;
        Node *q = head->next;
        while (q->next != NULL)
        {
            p = p->next;
            q = q->next;
        }
        p->next = NULL;
        free(q);
        return head;
    }

    //Case 4 Deleting the element with a given value from the Linked List
    Node *DeleteAfteraNode(Node *head, int value)
    {
        Node *p = head;
        Node *q = head->next;
        while (q->data != value && q->next != NULL)
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

    cout << "Linked List before Deletion :" << endl;
    n.LinkedlistTraversal(head);
    // head = n.deleteAtFirst(head); //For deleting First Element of the Linked List
    // head = n.deleteAtIndex(head, 1);
    // head = n.DeleteAtEnd(head);
    n.DeleteAfteraNode(head, 11);
    cout << "Linked List after Deletion :" << endl;
    n.LinkedlistTraversal(head);
    return 0;
}