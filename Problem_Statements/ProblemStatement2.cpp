#include <iostream>
using namespace std;

int inv = 0;

void merge(int * ptr, int low, int mid, int high){
    int * newPtr = new int[high - low + 1];
    int ind = 0;
    int leftInd = low;
    int rightInd = mid + 1;
    while (leftInd != mid + 1 && rightInd != high+1)
    {
        if (ptr[leftInd] < ptr[rightInd])
        {
            newPtr[ind] = ptr[leftInd];
            leftInd++;
            // cout << "No inversion" << endl;
            ind++;
        }
        else{
            inv += mid + 1 -leftInd;
            newPtr[ind] = ptr[rightInd];
            // cout << "Inversion present " << low << endl;
            rightInd++;
            ind++;
        }
    }
    if (leftInd == mid + 1)
    {
        while (rightInd != high+1)
        {
            newPtr[ind] = ptr[rightInd];
            rightInd++;
            ind++;
        }
    }
    else{
        while (leftInd != mid + 1)
        {
            newPtr[ind] = ptr[leftInd];
            leftInd++;
            ind++;
        }
    }
    for (int i = low; i <= high; i++)
    {
        ptr[i] = newPtr[i-low];
    }
}

void mergeSort(int * ptr,int low, int high)
{
    if (low < high) {
        int mid = (low + high)/2;
        mergeSort(ptr,low,mid);
        mergeSort(ptr,mid+1,high);
        merge(ptr,low,mid,high);
    }
}

int main() {
    int ptr[] = {5,3,1,4,2,6};
    int best[] = {1,2,3,4,5,6};
    int worst[] = {6,5,4,3,2,1};
    mergeSort(worst,0,5);

    for (int i = 0; i < 6; i++)
    {
        cout << worst[i] << " ";
    }
    cout << endl << "The number of inversions in the array is " << inv << endl;
}