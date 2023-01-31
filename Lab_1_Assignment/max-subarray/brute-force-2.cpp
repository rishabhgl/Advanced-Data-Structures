#include <iostream>
using namespace std;

int main()
{
    int low = 0;
    int ptr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int size = 8;
    // int ptr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // int size = 7;
    int sum;
    int maxSum = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        sum = 0;
        for (int subSize = 1; subSize <= size - i; subSize++)
        {
            sum += ptr[i+subSize-1];
            if (sum > maxSum)
                maxSum = sum;
        }
    }
    cout << "The maximum sum is: " << maxSum << endl;
    return 0;
}