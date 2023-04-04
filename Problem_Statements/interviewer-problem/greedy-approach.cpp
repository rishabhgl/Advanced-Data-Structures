#include <iostream>
using namespace std;

struct interview{
    int cid;
    float start;
    float end;
};

void swap(interview node1, interview node2)
{
    
}

void sort(interview * ptr, int size)
{
    interview temp;
    for ( int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; i < size; i++)
        {
            if (ptr[min].end > ptr[j].end)
                min = j;
        }
        if (min != i)
        {

        }
    }
}

int main()
{
    int size;
    cout << "Enter the number of interviews to be conducted during the day: " << endl;
    cin >> size;

    interview schedule[] = {
        {1, 9.10, 10.10},
        {2, 11.00, 11.20},
        {3, 10.30, 10.45},
        {4, 12.00, 12.30},
        {5, 11.20, 11.55},
        {6, 10.10, 10.30},
        {7, 10.45, 11.15},
        {8, 11.30, 12.10},
        {9, 9.00, 10.00},
        {10, 12.40, 13.00},
        {11, 10.10, 11.00},
        {12, 9.55, 10.30},
        {13, 11.05, 11.35},
        {14, 11.35, 12.00}
    };



}