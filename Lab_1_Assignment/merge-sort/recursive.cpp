#include <iostream>
using namespace std;

void merge(int * ptr, int low, int mid, int high)
{
    int * temp = new int[high - low + 1];
    int left = low;
    int right = mid + 1;
    int ind = 0;
    while (left != mid+1 && right != high + 1)
    {
        if (ptr[left] <= ptr[right])
        {
            temp[ind] = ptr[left];
            left++;
            ind++;
        }
        else
        {
            temp[ind] = ptr[right];
            right++;
            ind++;
        }
    }
    if (left < mid+1)
    {
        while (left != mid + 1)
        {
            temp[ind] = ptr[left];
            left++;
            ind++;
        }
    }
    else{
        while (right != high + 1)
        {
            temp[ind] = ptr[right];
            right++;
            ind++;
        }
    }
    for (int i = 0; i < high - low + 1; i++)
    {
        ptr[i + low] = temp[i];
    }
    delete temp;
}

void mergeSort(int * ptr, int low, int high)
{
    if (low < high)
    {
        int mid = (low + high)/2 ;
        mergeSort(ptr,low,mid);
        mergeSort(ptr,mid+1,high);
        merge(ptr,low,mid,high);
    }
}


int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;
    int ptr[size];
    cout << "Enter the array to be sorted: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> ptr[i];
    }
    mergeSort(ptr,0,size-1);
    cout << "The sorted array is: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << ptr[i] << " ";
    }
    cout << endl;
}