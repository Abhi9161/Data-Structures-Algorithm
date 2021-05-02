#include <iostream>
using namespace std;

class Array
{
public:
    void display(int arr[], int size)
    {
        for (int i = 0; i < size; i++) // Code for Traversal
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int indDeletion(int arr[], int size, int capacity, int index)
    {
        //Code for Deletion
        if (index >= capacity)
        {
            cout << "Deletion Not Successful" << endl;
            return -1;
        }
        for (int i = index; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        cout << "Deletion Successful" << endl;
        return 1;
    }
};
int main()
{
    Array obj;
    int arr[100] = {7, 8, 12, 27, 88};
    int size = 5, index = 0;
    obj.display(arr, size);
    obj.indDeletion(arr, size, 100, index);
    size -= 1;
    obj.display(arr, size);
    return 0;
}