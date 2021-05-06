#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prevnode;
    Node *next;
    void LinkedListTraversal(Node *head)
    {
        Node *ptr = head;
        do
        {
            cout << "Element: " << ptr->data << endl;
            ptr = ptr->next;
        } while (ptr != NULL);
        cout << endl;
    }

    void OpLinkedListTraversal(Node *head)
    {

        Node *ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        while (ptr != NULL)
        {
            cout << "Elements: " << ptr->data << endl;
            ptr = ptr->prevnode;
        }
        cout << endl;
    }

    //Case 1 Inserting the element at the first position in a Doubly Linked List
    Node *insertAtFirst(Node *head, int data)
    {
        Node *ptr = new Node;
        ptr->data = data;
        ptr->next = head;
        ptr->prevnode = NULL;
        return ptr;
    }

    //Case 2 Inserting the element at the given index in a Doubly Linked List
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
        p->next->prevnode = ptr;
        ptr->prevnode = p;
        p->next = ptr;
        return head;

        //Vivek's code
        // Node *ptr = new Node;
        // ptr->data = data;
        // Node *p = head;
        // int i = 1;
        // while (i < index)
        // {
        //     p = p->next;
        //     i += 1;
        // }
        // ptr->next = p;
        // ptr->prevnode = p->prevnode;
        // p->prevnode->next = ptr;
        // p->prevnode = ptr;
        // return head;
    }

    //Case 3 Inserting the element at the end in a Doubly Linked List
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
        ptr->prevnode = p;
        ptr->next = NULL;
        return head;
    }

    //Case 4 Inserting the element after a node in a Doubly Linked List
    Node *insertAfteraNode(Node *head, Node *previousNode, int data)
    {
        Node *ptr = new Node;
        ptr->data = data;
        ptr->next = previousNode->next;
        previousNode->next->prevnode = ptr;
        ptr->prevnode = previousNode;
        previousNode->next = ptr;
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
    //Allocate memory for nodes in the Doubly linked list in Heap
    head = new Node;
    second = new Node;
    third = new Node;
    fourth = new Node;

    //Link first and second nodes
    head->prevnode = NULL;
    head->data = 7;
    head->next = second;
    second->prevnode = head;

    //Link second and third nodes
    second->data = 11;
    second->next = third;
    third->prevnode = second;

    //Link third node and fourth nodes
    third->data = 66;
    third->next = fourth;
    fourth->prevnode = third;

    //Terminate the list at the fourth node
    fourth->data = 54;
    fourth->next = NULL;

    cout << "Doubly Linked List before Insertion :" << endl;
    //n.LinkedListTraversal(head);
    n.OpLinkedListTraversal(head);
    // head = n.insertAtFirst(head, 56);
    // n.inserAtIndex(head, 45, 2);
    // n.insertAtEnd(head, 45);
    n.insertAfteraNode(head, second, 10);
    cout << "Doubly Linked List after Insertion :" << endl;
    //n.LinkedListTraversal(head);
    n.OpLinkedListTraversal(head);
    return 0;
}