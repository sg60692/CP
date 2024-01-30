#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
void dfs(int u,int p,vector<int> *g,vector<int> &in,vector<int> &out,vector<int> &depth,vector<int> &euler){
    in[u] = euler.size();
    euler.pb(u);
    for(auto v:g[u]){
        if(v!=p){
            depth[v] = depth[u]+1;
            dfs(v,u,g,in,out,depth,euler);
        }
    }
    out[u] = euler.size()-1;
}
void update(int ind,int val,vector<ll> &fen){
    while(ind<fen.size()){
        fen[ind]+=val;
        ind+=(ind&(-ind));
    }
}
ll get(int ind,vector<ll> &fen){
    ll ans = 0;
    while(ind){
        ans+=fen[ind];
        ind-=(ind&(-ind));
    }
    return ans;
}
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> g[n],in(n),out(n),depth(n),euler,a(n);
    vector<ll> fen(n+1),ans(q);
    vector<pair<int,int>> inQueries[n],outQueries[n];
    for(auto &x:a)cin>>x;
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    depth[0] = 1;
    dfs(0,0,g,in,out,depth,euler);
    for(int i=0;i<q;++i){
        int x,d;
        cin>>x>>d;
        --x;++d;
        inQueries[in[x]].pb({d,i});
        outQueries[out[x]].pb({d,i});
    }
    for(int i=0;i<n;++i){
        for(auto w:inQueries[i]){
            ans[w.second] -= get(w.first,fen);
        }
        int u = euler[i];
        update(depth[u],a[u],fen);
        for(auto w:outQueries[i]){
            ans[w.second] += get(w.first,fen);
        }
    }
    for(auto x:ans)cout<<x<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}