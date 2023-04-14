#include<bits/stdc++.h>
using namespace std ;

vector<pair<int,int> >adj[5000];
vector<int>spl;

int mt[5000][5000];
bool dfs_flag[5000];
int level[5000];
int limit;

void addEdge(int u, int v,int w)
{
    mt[u][v]=w;
    mt[v][u]=w;
    adj[u].push_back(make_pair(v,w));
    adj[v].push_back(make_pair(u,w));
}

void dfs(int p,int s)
{
    level[s]=level[p]+mt[p][s];
    if(level[s]>limit)
    {
        level[p]=0;
        level[s]=mt[p][s];
        spl.push_back(p);
    }
    dfs_flag[s] = 1;
    for (int i = 0; i < adj[s].size(); i++)
    {
        int u = adj[s][i].first;
        if (dfs_flag[u] == 0)
        {
            dfs(s,u);
        }
    }
}

int main()
{
    cin >> limit ; /// tolerance value
    int nodes ;
    cin >> nodes ;
    int flag = 0 ;
    for(int i=1; i<nodes; i++) /// tree er edges (nodes-1) ta
    {
        int u,v,val;
        cin >> u >> v >> val ; /// u and v node duitar  mdder edge er  weight val

        addEdge(u,v,val);

        if(val>limit) /// jdi kno weight , limit cross kre then possible na
        {
            flag=1;
        }
    }
    adj[0].push_back(make_pair(1,0));
    adj[1].push_back(make_pair(0,0));

    if(flag==1)
    {
        cout << "not possible " << endl;
        return 0 ;
    }

    dfs(0,1); /// dfs ekta recursive function , 0 node 1 no node er parent
    cout << "boasters are needed at - > " << endl;
    for(int i=0;i<spl.size();i++)
    {
        cout<<spl[i]<<" ";
    }
    return 0 ;
}
