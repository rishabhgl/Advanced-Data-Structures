#include <iostream>
using namespace std;

struct job
{
    int id;
    int profit;
    int deadline;

    void get(){
        cout << id << " ";
        cout << profit << " ";
        cout << deadline << " ";
        cout << endl;
    }
};

void sort(job *list, int size)
{
    job temp;
    for (int i = 0; i < size - 1; i++)
    {
        int max = i;
        for (int j = i + 1; j < size; j++)
        {
            if (list[max].profit < list[j].profit)
                max = j;
        }
        cout << max << endl;
        if (max != i)
        {
            temp = list[i];
            list[i] = list[max];
            list[max] = temp;
        }
    }
}

int main()
{
    int maxDeadline = 3;
    int sizeList = 5;
    job null = {0, 0, 0};
    job list[] = {{1, 100, 2},
                  {2, 19, 1},
                  {3, 27, 2},
                  {4, 25, 1},
                  {5, 15, 3}};
    sort(list, sizeList);
    job seq[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
    {
        seq[i] = null;
    }
    int index = 0, count;
    while (index < sizeList)
    {
        job temp = list[index];
        
            for (int i = temp.deadline - 1; i > -1; i--)
            {
                if (seq[i].deadline == 0)
                {
                    seq[i] = temp;
                    count++;
                    break;
                }
            }
        index++;
    }
    for (int i = 0; i < count; i++)
    {
        seq[i].get();
    }
    return 0;
}