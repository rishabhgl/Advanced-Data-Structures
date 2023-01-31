#include <iostream>
using namespace std;

int main()
{
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ptr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int low = 0;
    int high = 7;
    int sum;
    int maxSum = INT_MIN;
    for (int subSize = 1; subSize <= high + 1; subSize++)
    {
        for (int i = low; i + subSize - 1 < high + 1; i++)
        {
            sum = 0;
            for (int j = i; j < i + subSize; j++)
            {
                sum += ptr[j];
            }
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    cout << "The maximum sum is: " << maxSum << endl;
    return 0;
}