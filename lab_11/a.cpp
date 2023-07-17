#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pip pair<int,pii>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
vector <pip> v;
int par[200005];
bool mark[200005];
int n,m;
bool comp(pip a,pip b)
{
    if(a.fi!=b.fi)
        return a.fi<b.fi;
    return a.se.fi<b.se.fi;
}
int find(int x)
{
    if(par[x]==x)
        return x;
    return par[x]=find(par[x]);
}
void merge(int x,int y)
{
    int a=find(x);
    int b=find(y);
    par[a]=b;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        par[i]=i;
    for(int i=0;i<m;i++)
    {
        int l,r,c;
        cin>>l>>r>>c;
        v.pb(mp(c,mp(l,r)));
    }
    sort(v.begin(),v.end(),comp);
    ll ans=0;
    for(int i=0;i<m;i++)
    {
        int c=v[i].fi;
        int l=v[i].se.fi;
        int r=v[i].se.se;
        for(int j=l;j<r;)
        {
            if(find(j)==j)
            {
                ans+=c;
                merge(j,r);
                mark[j]=1;
                j++;
            }
            else
                j=find(j);
        }
    }
    cout<<ans<<'\n';
    return 0;
}