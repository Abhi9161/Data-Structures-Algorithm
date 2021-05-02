#include <iostream>
using namespace std;

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++) // Code for Traversal
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int indInsertion(int arr[], int size, int element, int capacity, int index)
{
    //Code for Insertion
    if (size >= capacity)
    {
        cout << "Insertion Not Successful" << endl;
        return -1;
    }
    for (int i = size - 1; i >= index; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[index] = element;
    cout << "Insertion Successful" << endl;
    return 1;
}
int main()
{
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, element = 45, index = 3;
    display(arr, size);
    indInsertion(arr, size, element, 100, index);
    size += 1;
    display(arr, size);
    return 0;
}