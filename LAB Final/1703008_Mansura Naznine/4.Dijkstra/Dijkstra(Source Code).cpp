/// Finding shortest paths using Dijkstra's algorithm
/// Author: 1703008_Mansura Naznine


#include<bits/stdc++.h>
using namespace std;

int V,step=0;
int Grid[500][500];


int minDistance(int Distance[], bool sptSet[])
{
    step+=1;
    int mn = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
    {
        step+=1;
        if (sptSet[v] == false && Distance[v] <= mn)
        {
            step+=2;
            mn = Distance[v];
            min_index = v;
        }
    }
    return min_index;
}
void printSolution(int Distance[])
{
    printf("\nEnter the source matrix: 1\n\n");
    printf("\nShortest path:\n\n");
    for (int i = 0; i < V; i++)
        printf("1->%d,cost=%d\n", i+1, Distance[i]);

    printf("\nRequired steps: %d\n",step);
}

void DIJKSTRA(int src)
{
    step+=1;
    int Distance[V+5];

    bool sptSet[V+5];
    for (int i = 0; i < V; i++)
    {
        Distance[i] = INT_MAX;
        sptSet[i] = false;
        step+=2;
    }

    Distance[src] = 0;
    step+=1;
    for (int it = 0; it < V - 1; it++)
    {
        step+=2;
        int u = minDistance(Distance, sptSet);
        sptSet[u] = true;
        for (int v = 0; v < V; v++)
        {
            step+=1;
            if (!sptSet[v] && Grid[u][v] && Distance[u] != INT_MAX && Distance[u] + Grid[u][v] < Distance[v])
            {
                step+=1;
                Distance[v] = Distance[u] + Grid[u][v];
            }
        }
    }
    printSolution(Distance);
}
int main()
{
    ifstream input;
    input.open("graph.txt");

    for(int cs=5; cs<=7; cs++)
    {
        cout<<"---------------------CASE-"<<cs-4<<"---------------------"<<endl;
        V=cs;
        step=0;
        cout<<"Enter the number of nodes "<<V<<endl<<endl;
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                input>>Grid[i][j];
            }
        }
        cout<<"Enter the cost matrix:"<<endl<<endl;
        for(int i=0; i<V; i++)
        {
            for(int j=0; j<V; j++)
            {
                cout<<Grid[i][j]<<"\t";
            }
            cout<<endl;
        }
        DIJKSTRA(0);
        cout<<endl<<endl;
    }

    return 0;
}

