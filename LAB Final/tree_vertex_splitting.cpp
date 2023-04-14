#include<bits/stdc++.h>
using namespace std ;
int edges[1000][1000];
int limit ;
int lvl[1000];
void dfs(int p,int c) /// p for parent , c for child
{
    lvl[c]=lvl[p]+edges[p][c]; /// lvl[c] means voltage drop from root to node c so far
    if(lvl[c]>limit)
    {
        /// we need boaster here
        lvl[p]=0; /// ager voltage drop zero kre dei
        lvl[c]=edges[p][c]; /// so child er voltage update kra lagbe
        cout << p << endl; /// p te boaster boshaisi
    }
    for(int i=1;i<=1000;i++)
    {
        if(edges[c][i]>0 && i!=p) /// c theke i te jaoya jae naki check krtesi
                                  /// and i kintu parent hte parbe na cos naile abar
                                  /// ager path a chole jabe
        {
            dfs(c,i);
        }
    }
}
int main()
{
    cin >> limit ; /// tolerance value
    int nodes ;
    cin >> nodes ;
    int flag = 0 ;
    for(int i=1;i<nodes;i++) /// tree er edges (nodes-1) ta
    {
        int u,v,val;
        cin >> u >> v >> val ; /// u and v node duitar  mdder edge er  weight val

        edges[u][v]= val ;
        edges[v][u]= val ;

        if(val>limit) /// jdi kno weight , limit cross kre then possible na
        {
            flag=1;
        }
    }

    if(flag==1){cout << "not possible " << endl; return 0 ;}
    cout << "boasters are needed at - > " << endl;

    dfs(0,1); /// dfs ekta recursive function , 0 node 1 no node er parent

    return 0 ;
}
