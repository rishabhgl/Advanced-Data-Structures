#include <iostream>
using namespace std;

int * sol = NULL;
int n = 0;
int count = 0;

void write(){
    for (int i = 0; i < n; i++)
        cout << sol[i] << ' ';
    cout << endl;
    count++;
}

int abs(int in)
{
    if (in < 0)
        return in * -1;
    else return in;
}

bool place(int k, int i)
{
    for (int j = 0; j < k; j++)
    {
        if (sol[j] == i || abs(k - j) == abs(i - sol[j]) )
            return false;
    }
    sol[k] = i;
    return true;
}

void nqueen(int k)
{
    for (int i = 0; i < n; i++)
    {
        if (place(k,i)){
            if (k == n - 1)
                write();
            else
                nqueen(k+1);
        }
    }
}


int main()
{
    cout << "Enter the size of the chessboard:" << endl;
    cin >> n;
    sol = new int[n];
    nqueen(0);
    return 0;
}