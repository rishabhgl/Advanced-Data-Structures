#include <iostream>
using namespace std;

//https://www.hackerearth.com/practice/algorithms/sorting/merge-sort/practice-problems/algorithm/median-game-june-easy-19-3722be60/

void sort(int *ptr, int n)
{
    int min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ptr[min] > ptr[j])
                min = j;
        }
        if (min != i)
        {
            temp = ptr[min];
            ptr[min] = ptr[i];
            ptr[i] = temp;
        }
    }
}

void deleteMedian(int *ptr, int num, int size)
{
    int index = -1;
    for (int i = 0; i < size; i++)
    {
        if (ptr[i] == num)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        for (int i = index+1; i < size; i++)
        {
            ptr[i-1] = ptr[i]; 
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int median[n - 2];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    while (n > 2)
    {
        for (int subSize = 3; subSize <= n; subSize += 2)
        {
            for (int i = 0; i + subSize <= n; i++)
            {
                int *ptr = new int[subSize];
                for (int j = 0; j < subSize; j++)
                {
                    ptr[j] = arr[j + i];
                }
                sort(ptr, subSize);
                median[i] = ptr[(subSize - 1) / 2];
                delete ptr;
            }
            sort(median, n - subSize + 1);
            deleteMedian(arr, median[0], n);
            n--;
            if (subSize == n-1 || subSize == n)
                break;
        }
    }
    cout << arr[0] + arr[1] << endl;
}