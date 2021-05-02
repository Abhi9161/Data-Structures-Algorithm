#include <iostream>
using namespace std;

class myArray
{
private:
    int total_size;
    int used_size;
    int *ptr;

public:
    void createArray(myArray *a, int tsize, int usize);
    void show(struct myArray *a);
    void setVal(struct myArray *a);
};

void myArray ::createArray(myArray *a, int tsize, int usize)
{
    a->total_size = tsize;
    a->used_size = usize;
    a->ptr = new int(tsize);
}

void myArray::show(struct myArray *a)
{
    for (int i = 0; i < a->used_size; i++)
    {
        cout << ((a->ptr)[i]) << endl;
    }
}

void myArray::setVal(struct myArray *a)
{
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        cout << "Enter the element  " << i << endl;
        cin >> n;
        a->ptr[i] = n;
    }
}
int main()
{
    myArray marks;
    marks.createArray(&marks, 10, 2);
    cout << "We are running setVal now" << endl;
    marks.setVal(&marks);
    cout << "We are running show now" << endl;
    marks.show(&marks);
    return 0;
}