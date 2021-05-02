#include <iostream>
using namespace std;
class Array
{
public:
    int LinearSearch(int arr[], int size, int element)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == element)
                return i;
        }
        return -1;
    }

    int binarySearch(int arr[], int size, int element)
    {
        int low, mid, high;
        low = 0;
        high = size - 1;
        //Keep Searching until low <= high
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (arr[mid] == element)
            {
                return mid;
            }
            if (arr[mid] < element)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        //Searching Ends
        return -1;
    }
};

int main()
{
    Array a;
    //Unsorted Array for Linear Search
    // int arr[100] = {1, 2, 3, 4, 5, 34, 726, 23};
    // int size = sizeof(arr) / sizeof(int);

    //Sorted Array for Binary Search
    int arr[] = {1, 3, 5, 56, 64, 73, 123, 225, 444};
    int size = sizeof(arr) / sizeof(int);
    int element = 5;
    int searchIndex = a.binarySearch(arr, size, element);
    cout << "The element " << element << " was found at index " << searchIndex << endl;
    return 0;
}