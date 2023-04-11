#include <iostream>
using namespace std;

int *coloring;
int **graph;
int m, n;

void write()
{
    for (int i = 0; i < n; i++)
        cout << coloring[i] << ' ';
    cout << endl;
}

bool assignColour(int k, int i)
{
    for (int j = 0; j < k; j++)
    {
        if (graph[k][j])
        {
            if (coloring[j] == i)
                return false;
        }
    }
    coloring[k] = i;
    return true;
}

void graphColouring(int k)
{
    for (int i = 0; i < m; i++)
    {
        if (assignColour(k, i))
        {
            if (k == n - 1)
                write();
            else{
                // cout << "Node :" << k << ", Color: " << i << endl;
                graphColouring(k + 1);
            }
        }
    }
}

int main()
{
    // cout << "Enter the number of colours to be assigned:" << endl;
    // cin >> m;
    // cout << "Enter the number of nodes in graph:" << endl;
    // cin >> n;

    m = 3;
    n = 4;

    coloring = new int[n];

    for (int i = 0; i < m; i++)
        coloring[i] = -1;

    // Graph initialisation

    graph = new int *[n];
    for (int i = 0; i < n; i++)
    {
        graph[i] = new int[n];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cin >> graph[i][j];
    //     }
    // }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    graph[0][1] = 1;
    graph[0][2] = 1;
    graph[0][3] = 1;
    graph[1][2] = 1;
    graph[2][3] = 1;
    graph[1][0] = 1;
    graph[2][0] = 1;
    graph[3][0] = 1;
    graph[2][1] = 1;
    graph[3][2] = 1;

    // cout << "Graph initialised!" << endl;

    graphColouring(0);

    return 0;
}