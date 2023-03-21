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
    int size1, size2;
    cout << "Enter the size of the first sequence: " << endl;
    cin >> size1;
    char seq1[size1 + 1];
    cout << "Enter the first sequence character by character:" << endl;
    for (int i = 1; i <= size1; i++)
    {
        cin >> seq1[i];
    }
    cout << "Enter the size of the second sequence: " << endl;
    cin >> size2;
    char seq2[size2 + 2];
    cout << "Enter the second sequence character by character:" << endl;
    for (int i = 1; i <= size2; i++)
    {
        cin >> seq2[i];
    }
    node ** lcs = new node*[size1+1];
    for (int i = 0; i <= size2 ; i++)
    {
        lcs[i] = new node[size2 + 1];
    }
    for (int i = 0; i <= size1; i++)
    {
        // First sequence as rows
        lcs[i][0].sol = 0;
    }
    for (int i = 0; i <= size2; i++)
    {
        // Second sequence as columns
        lcs[0][i].sol = 0;
    }

    for (int i = 1; i <= size1; i++)
    {
        for (int j = 1; j <= size2; j++)
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

    cout << "The length of the longest common sequence is: " << lcs[size1][size2].sol << endl;
    cout << "The longest common subsequence is reversed is: " << endl;
    printLCS(lcs,size1,size2,seq1);
    return 0;
}
    // for (int i = 0; i <= size1; i++)
    // {
    //     for (int j = 0; j <= size2; j++)
    //     {
    //         cout << lcs[i][j].sol << ' ';
    //     }
    //     cout << endl;
    // }