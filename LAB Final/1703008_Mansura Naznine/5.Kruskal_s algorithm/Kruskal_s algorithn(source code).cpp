/// Kruskal's algorithm
/// Author: 1703008_Mansura Naznine

#include<bits/stdc++.h>
using namespace std;

int mat[500][500];

struct KGraph
{
    int Vertices, Edges;
    vector< pair<int, pair<int,int> > > adj;
    KGraph(int Vertices, int Edges)
    {
        this->Vertices = Vertices;
        this->Edges = Edges;
    }
    void addEdge(int u, int v, int w)
    {
        adj.push_back({w, {u, v}});
    }
    int MST();
};

struct DisjointSets
{
    int *parent, *rnk;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n+1];
        rnk = new int[n+1];
        for (int i = 0; i <= n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

int KGraph::MST()
{
    int wt = 0,i=1;
    sort(adj.begin(), adj.end());

    DisjointSets ds(Vertices);
    vector< pair<int, pair<int,int> > >::iterator it;
    for (it=adj.begin(); it!=adj.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);
        if (set_u != set_v)
        {
            cout <<i<<" edge (" <<u << "," << v<<") = " <<mat[u][v]<< endl<<endl;
            wt += it->first;
            i+=1;
            ds.merge(set_u, set_v);
        }
    }

    return wt;
}

int main()
{
    ifstream input;
    input.open("kgraph.txt");
    cout<<"           Implementation of Kruskal's Algorithm"<<endl<<endl;
    int Vertices,value;
    cout<<"Enter the number of vertices: "<<endl;
    input>>Vertices;
    cout<<Vertices<<endl;
    KGraph g(1000, 1000);
    cout<<"Enter the cost adjacency matrix: "<<endl;
    for(int i=1; i<=Vertices; i++)
    {
        for(int j=1; j<=Vertices; j++)
        {
            input>>mat[i][j];
            g.addEdge(i,j,mat[i][j]);
            cout<<"\t"<<mat[i][j]<<" ";
        }
        cout<<endl;
    }

    cout << "The edges of Minimum Cost Spanning Tree are \n\n";
    int wt = g.MST();

    cout << "\n\tMinimum cost: " << wt<<endl;

    return 0;
}
