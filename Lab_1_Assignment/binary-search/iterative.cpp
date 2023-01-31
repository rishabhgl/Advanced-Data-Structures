#include <iostream>
using namespace std;

int main()
{
    int ptr[] = {-15, -1, 0, 3, 4, 5, 9, 11, 43};
    int num;
    cin >> num;
    int low = 0;
    int high = 8;
    int mid = (low + high)/2;
    bool flag = false;
    while (low <= high)
    {
        if (num == ptr[mid])
        {
            flag = true;
            break;
        } 
        else if (num < ptr[mid])
        {
            high = mid - 1;
            mid = (low + high)/2;
        }
        else
        {
            low = mid + 1;
            mid = (low + high)/2;
        }
    }
    if (flag)
        cout << "The specified number is present at index: " << mid << endl;
    else    
        cout << "The number could not be found in the set array." << endl;
    return 0;
}