#include <iostream>
using namespace std;

struct activity{
    int id;
    int start;
    int finish;
};

int main()
{
    int size = 11;
    activity subset[size];

    //choice already sorted by finish order ascending
    activity choice[] = {
        {1,1,4},
        {2,3,5},
        {3,0,6},
        {4,5,7},
        {5,3,8},
        {6,5,9},
        {7,6,10},
        {8,8,11},
        {9,8,12},
        {10,2,13},
        {11,12,14}
    };

    subset[0] = choice[0]; 
    int index = 1;

    int j = 0;
    for (int i = 1; i < size; i++)
    {
        if (choice[i].start >= choice[j].finish)
        {
            subset[index++] = choice[i];
            j = i;
        }
    }

    for(int i = 0; i < index; i++)
    {
        cout << subset[i].id << " ";
    }
    return 0;
}