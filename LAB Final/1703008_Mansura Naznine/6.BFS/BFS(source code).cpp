/// BFS method
/// Author: 1703008_Mansura Naznine


#include<bits/stdc++.h>
using namespace std;

vector<int> adj[500];
bool bfs_flag[500];

void addEdge(int u, int v)
{
    adj[u].push_back(v);
}

void BFS(int source)
{
    priority_queue<int, vector<int>, greater<int> > Q;
    Q.push(source);
    bfs_flag[source] = true;

    cout << "The node which are reachable are: " <<endl;
    while (!Q.empty())
    {
        int u = Q.top();
        Q.pop();
        if(u!=source)
            cout<< u <<"\t";

        for (int i = 0; i < adj[u].size(); i++)
        {
            int x = adj[u][i];
            if (bfs_flag[x] == false)
            {
                Q.push(x);
                bfs_flag[x] = true;
            }
        }
    }
}

int main()
{
    ifstream infile;
    infile.open("input.txt");

    cout<<"Enter the number of vertices : ";
    int n,mat[500][500],startingVertex;
    infile>>n;
    cout<<n<<endl<<endl;
    cout<<"Enter graph data in matrix form: "<<endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            infile>>mat[i][j];
            cout<<"\t"<<mat[i][j];
            if(mat[i][j]==1)
            {
                addEdge(i,j);
            }
        }
        cout<<endl;
    }

    cout<<endl<<"Enter the starting vertex: ";
    infile>>startingVertex;
    cout<<startingVertex<<endl<<endl;
    BFS(startingVertex);
    cout<<endl;
}

