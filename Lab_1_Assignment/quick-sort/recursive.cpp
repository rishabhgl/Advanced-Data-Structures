#include <iostream>
using namespace std;

int partition(int * ptr, int low, int high)
{
    int temp;
    int smallerIndex = low - 1;
    for (int i = low; i < high; i++)
    {
        if (ptr[i] < ptr[high])
        {
            smallerIndex++;
            temp = ptr[smallerIndex];
            ptr[smallerIndex] = ptr[i];
            ptr[i] = temp;
        }
    }
    temp = ptr[++smallerIndex];
    ptr[smallerIndex] = ptr[high];
    ptr[high] = temp;
    return smallerIndex;
}

void quicksort (int * ptr, int low, int high)
{
    if (low < high)
    {
        int pos = partition(ptr, low, high);
        quicksort(ptr, low, pos - 1);
        quicksort(ptr, pos + 1, high);
    }
}

int main()
{
    int size;
    cin >> size;
    int * ptr = new int [size];
    for (int i = 0; i < size; i++)
    {
        cin >> ptr[i];
    }
    quicksort(ptr,0,size-1);
    cout << "The sorted array is: " << endl;
    for (int i = 0; i  < size; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
    delete ptr;
    return 0;
}