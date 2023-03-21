#include <iostream>
using namespace std;

struct node
{
    int sub; // if 0, subproblem lies diagonally from current node. If 1, subproblem lies above, else it lies to the left.
    int sol;
};

void printLCS(node **lcs, int i, int j, char *seq)
{
    if (lcs[i][j].sol == 0)
        exit(0);
    if (lcs[i][j].sub == 0)
    {
        cout << seq[i] << ' ';
        printLCS(lcs, i - 1, j - 1, seq);
    }
    else if(lcs[i][j].sub == 1){
        printLCS(lcs,i-1,j,seq);
    }
    else{
        printLCS(lcs,i,j-1,seq);
    }
}

int main()
{
    int size;
    cout << "Enter the size of the sequence: " << endl;
    cin >> size;
    char seq1[size + 1];
    char seq2[size + 2];
    cout << "Enter the first sequence character by character:" << endl;
    for (int i = 1; i <= size; i++)
    {
        cin >> seq1[i];
    }
    for (int i = 1; i <= size; i++)
    {
        seq2[i] = seq1[size - i + 1];
    }
    node ** lcs = new node*[size+1];
    for (int i = 0; i <= size; i++)
    {
        lcs[i] = new node[size+1];
    }
    // node lcs[size + 1][size + 1];
    for (int i = 0; i <= size; i++)
    {
        // First sequence as rows
        lcs[i][0].sol = 0;
        lcs[i][0].sub = 0;
    }
    for (int i = 0; i <= size; i++)
    {
        // Second sequence as columns
        lcs[0][i].sol = 0;
        lcs[0][i].sub = 0;
    }

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            if (seq1[i] == seq2[j])
            {
                lcs[i][j].sol = 1 + lcs[i - 1][j - 1].sol;
                lcs[i][j].sub = 0;
            }
            else if (lcs[i - 1][j].sol >= lcs[i][j - 1].sol)
            {
                lcs[i][j].sol = lcs[i - 1][j].sol;
                lcs[i][j].sub = 1;
            }
            else
            {
                lcs[i][j].sol = lcs[i][j - 1].sol;
                lcs[i][j].sub = 2;
            }
        }
    }

    cout << "The length of the longest palindrome sequence is: " << lcs[size][size].sol << endl;
    printLCS(lcs,size, size, seq1);
    return 0;
}



    // for (int i = 0; i <= size; i++)
    // {
    //     for (int j = 0; j <= size; j++)
    //     {
    //         cout << lcs[i][j].sub << ' ';
    //     }
    //     cout << endl;
    // }