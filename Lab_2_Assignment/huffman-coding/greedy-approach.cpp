#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int counter = 0;

struct node{
    int id;
    char character;
    node * left;
    node * right;
    int freq;
};

class check{
    public:
        bool operator()(node a, node b)
        {
            return a.freq > b.freq;
        }
};

priority_queue<node,vector<node>,check> minHeap;


int main()
{
    int size;
    cout << "Enter the number of unique characters in the string:" << endl;
    cin >> size;
    node temp;
    for (int i = 0; i < size; i++)
    {
        temp.id = counter++;
        cout << "Enter the character: " << endl;
        cin >> temp.character;
        cout << "Enter the frequency of character: " << endl;
        cin >> temp.freq;
        temp.left = NULL;
        temp.right = NULL;
        minHeap.push(temp);
    }
    int index = 0;
    node ptr[size];
    while(!(minHeap.size() == 1))
    {
        ptr[index] = minHeap.top();
        index++;
        minHeap.pop();
        ptr[index] = minHeap.top();
        minHeap.pop();
        index++;
        temp.id = counter++;
        temp.character = '0';
        temp.left = &ptr[index-2];
        temp.right = &ptr[index-1];;
        temp.freq = ptr[index-2].freq + ptr[index-1].freq;
        minHeap.push(temp);
    }
    return 0;
}
