#include <iostream>
using namespace std;

//Returning the maximum sum from contiguous sub-arrays of a given array.

int maxCrossSubArray(int * ptr, int low, int mid, int high)
{
    int leftSum = INT_MIN;
    int rightSum = INT_MIN;
    int sum = 0;
    for (int i = mid; i >=low; i--)
    {
        sum += ptr[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    sum = 0;
    for (int i = mid+1; i <= high; i++)
    {
        sum += ptr[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    return leftSum + rightSum;
}

int maxSubArray(int * ptr, int low, int high){
    if (low == high)
    {
        return ptr[low];
    }
    int mid = (low+high)/2;
    int leftSum = maxSubArray(ptr,low,mid);
    int rightSum = maxSubArray(ptr,mid+ 1,high);
    int crossSum = maxCrossSubArray(ptr,low,mid,high);
    if (leftSum >= rightSum && leftSum >= crossSum)
        return leftSum;
    else if (rightSum >= leftSum && rightSum >= crossSum)
        return rightSum;
    else 
        return crossSum;
}

int main(){

    int ptr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int low = 0;
    int high = 8;
    int maxSum = maxSubArray(ptr,low,high);
    cout << "The maximum sum is: " << maxSum << endl;
    return 0;
}