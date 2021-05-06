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
            cout << "Element: "<< ptr->data<<endl;
            ptr = ptr->next;
        }
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

    n.LinkedlistTraversal(head);
    return 0;
}