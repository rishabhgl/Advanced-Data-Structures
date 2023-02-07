#include <iostream>
using namespace std;

struct item{
    int id;
    float profit;
    int weight;
    float ratio;
    void getItem(){
        cout << id << ' ';
        cout << weight << ' ';
        cout << profit << ' ';
        cout << ratio << ' ';
    }
};

int main()
{
    int size = 6;
    int capacity;
    int curWeight = 0;
    item * knapsack;
    item choice[] = {
        {1, 40, 100}, {2, 35, 50}, {3, 18, 45}, {4, 4, 20}, {5, 10, 10}, {6, 2, 5}
    };
    cout << "Enter capacity of knapsack: " << endl;
    cin >> capacity;
    knapsack = new item[capacity];
    for (int i = 0; i < size; i++)
    {
        choice[i].ratio = choice[i].profit/choice[i].weight;
    }
    item temp;
    int max;
    for (int i = 0; i < size - 1; i++)
    {
        max = i;
        for (int j = i + 1; j < size; j++)
        {
            if (choice[max].ratio < choice[j].ratio)
                max = j;
        }
        if (max != i)
        {
                temp = choice[max];
                choice[max] = choice[i];
                choice[i] = temp;
        }
    }
    int i = 0;
    while(curWeight < capacity)
    {
        if (choice[i].weight <= capacity - curWeight)
        {
            knapsack[i] = choice[i];
            curWeight += knapsack[i].weight;
            cout << curWeight << endl;
            i++;
        }
        else{
            temp.id = choice[i].id;
            temp.ratio = choice[i].ratio;
            temp.weight = capacity - curWeight;
            temp.profit = (float(temp.weight)/choice[i].weight) * choice[i].profit;
            knapsack[i] = temp;
            curWeight = capacity;
            i++;
        }
    }
    int totalProfit = 0;
    cout << "Current state of knapsack: "<< endl;
    for (int j = 0; j < i; j++)
    {
        knapsack[j].getItem();
        cout << endl;
        totalProfit += knapsack[j].profit;
    }
    cout << "Total profit is: " << totalProfit << endl;
    return 0;
}