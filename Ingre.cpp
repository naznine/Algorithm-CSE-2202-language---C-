#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    ll t,n;
    scanf("%lld",&t);
    while(t--)
    {

        ll a[105],b[105];
        vector<pair<ll,ll> >v;
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(ll i=1;i<=n;i++)
        {
            scanf("%lld",&b[i]);
        }
        ll ex=0,fl=0;
        for(ll i=n;i>=1;i--)
        {
            if(i==n)
            {
                if(a[i]>b[i])
                {
                    fl=1;
                    break;
                }
                else
                {
                    ex=ex+b[i]-a[i];
                }
            }
            else
            {
                if(a[i]<=b[i])
                {
                    ex=ex+b[i]-a[i];
                }
                else
                {
                    if(a[i]<=b[i]+ex)
                    {
                        ex=ex+b[i]-a[i];
                    }
                    else
                    {
                        fl=1;
                        break;
                    }
                }
            }
        }
        if(fl==1)
            printf("No\n");
        else
            printf("Yes\n");
    }
}
