#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t,arr[100005],p=0,n=0,z=0,cnt=0,ans;
    vector<ll>v;
    scanf("%lld",&t);
    for(ll i=1; i<=t; i++)
    {
        scanf("%lld",&arr[i]);
        if(arr[i]==0)
            z=z+1;
        else if(arr[i]%2==0)
            p=p+1;
        else
            n=n+1;
    }
    v.push_back(p);
    v.push_back(p);
    v.push_back(p);
    sort(v.begin(),v.end());

    cnt=cnt+v[1];
    v[2]=v[2]-v[1];
    v[1]=0;
    if(v[2]<=v[0])
    {
        cnt=cnt+v[2];
        if(v[0]!=0)
        {
            ans=cnt;
        }
        else
        {
            ans=cnt-1;
        }
    }
    else
    {
        cnt=cnt+v[0];
        if(v[2]!=0)
        {
            ans=cnt;
        }
        else
        {
            ans=cnt-1;
        }
    }
    cout<<ans<<endl;
}
