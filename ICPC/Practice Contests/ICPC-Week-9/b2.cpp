#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;

vector<vector<ll>> adj,rev;
vector<ll> x,typ,vis1,vis2,v;

void dfs(ll cur,vector<ll> &vis,ll curtyp)
{
    if(vis[cur])
    {
        if(typ[cur]!=curtyp)
            v.push_back(cur);
    }
    else if(x[cur]==0)
    {
        vis[cur]=1;
        typ[cur]=curtyp;

        for(auto child:adj[cur])
            dfs(child,vis1,curtyp);
    }
}

void dfs2(ll cur,vector<ll> &vis)
{
    if(vis[cur])
        return;

    vis[cur]=1;
    typ[cur]=-2;

    for(auto child:adj[cur])
        if(x[child]==0 && !vis[child])
            dfs2(child,vis);
}

void solve(){
    ll n;
    cin>>n;

    adj.assign(n+1,{});
    rev.assign(n+1,{});
    x.assign(n+1,0);
    typ.assign(n+1,-1);

    for(ll i=1;i<=n;i++)
    {
        cin>>x[i];

        ll temp;
        cin>>temp;

        for(ll j=0;j<temp;j++)
        {
            ll v2;
            cin>>v2;

            adj[i].push_back(v2);
            rev[v2].push_back(i);
        }
    }

    vis1.assign(n+1,0);
    vis2.assign(n+1,0);

    if(x[1]==0)
        dfs(1,vis1,0);

    for(ll i=1;i<=n;i++)
    {
        if(x[i])
        {
            typ[i]=x[i];
            for(auto child:adj[i])
                dfs(child,vis1,x[i]);
        }
    }

    //

    // for(ll i=1;i<=n;i++)
    //     cout<<i<<" "<<typ[i]<<"\n";

    //

    for(auto cur:v)
    {
        dfs2(cur,vis2);
    }

    //

    for(ll i=1;i<=n;i++)
    {
        

        
        if(ans==0)
            cout<<"unknown ";
        else if(cur==-1 || cur==0)
            cout<<"sober ";
        else
            cout<<cur<<" ";

        //

        if(typ[i]>0)
            cout<<typ[i]<<"\n";
        else if(typ[i]==-2)
            cout<<"unknown\n";
        else
            cout<<"sober\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}