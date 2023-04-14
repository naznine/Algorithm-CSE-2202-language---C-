#include<bits/stdc++.h>
using namespace std;

int V;
int Grid[500][500];


int minDistance(int Distance[], bool sptSet[])
{
    int mn = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && Distance[v] <= mn)
        {
            mn = Distance[v];
            min_index = v;
        }
    return min_index;
}
void printSolution(int Distance[])
{
    printf("\nEnter the source matrix: 1\n\n");
    printf("\nShortest path:\n\n");
    for (int i = 0; i < V; i++)
        printf("1->%d,cost=%d\n", i+1, Distance[i]);
}

void DIJKSTRA(int src)
{
    int Distance[V];

    bool sptSet[V];
    for (int i = 0; i < V; i++)
        Distance[i] = INT_MAX, sptSet[i] = false;

    Distance[src] = 0;
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(Distance, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && Grid[u][v] && Distance[u] != INT_MAX && Distance[u] + Grid[u][v] < Distance[v])
                Distance[v] = Distance[u] + Grid[u][v];
    }
    printSolution(Distance);
}
int main()
{
    V=5;
    ifstream input;
    input.open("city-map.txt");
    cout<<"Enter the number of nodes "<<V<<endl<<endl;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            input>>Grid[i][j];
        }
    }
    cout<<"Enter the cost matrix:"<<endl<<endl;
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cout<<Grid[i][j]<<"\t";
        }
        cout<<endl;
    }
    DIJKSTRA(0);

    return 0;
}

