#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define ll           long long
#define pb           push_back
#define F            first
#define S            second
#define mp           make_pair
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define vi           vector<int>
#define vll          vector<ll>
#define vN           vector<node>
#define vT           vector<T>
#define vpii         vector<pii>
#define vpll         vector<pll>
#define all(x)       x.begin(),x.end()
#define u32          uint32_t
#define u64          uint64_t
#ifndef ONLINE_JUDGE
    #define Log(x)  cerr<<"Debug: "<<x
#else
    #define Log(x)  0
#endif
using namespace std;
template<typename T>istream & operator >> (istream &in, vector<T> &a){for(auto &x:a)in>>x;return in;}
template<typename T>ostream & operator << (ostream &out, vector<T> &a){for(auto &x:a)out<<x<<" ";return out;}
template<typename T,typename K>istream & operator >> (istream &in,  pair<T,K> &a){in>>a.F>>a.S;return in;}
template<typename T,typename K>ostream & operator << (ostream &out, pair<T,K> &a){out<<a.F<<" "<<a.S;return out;}
long long dfs(int u,int p,vector<vi> &g,vll &a,ll &ans){
    ll s = a[u];
    ll d = 0;
    ll f = a[u];
    vector<ll> costs;
    for(auto v:g[u]){
        if(v!=p){
            costs.pb(dfs(v,u,g,a,ans));
        }
    }
    sort(costs.begin(),costs.end());
    if(costs.empty()){
        ans = max(ans,a[u]);
        return a[u];
    }
    if(costs.size()==1){
        ans = max(ans,a[u]+max(0ll,costs.back()));
        return max(a[u],costs.back());
    }
    else if(costs.size()==2){
        ans = max(ans,a[u]+max(0ll,costs.back()));
        ans = max(ans,costs[0]+costs[1]);
        return max(max(a[u],costs.back()),a[u]+costs[0]+costs[1]);
    }
    else{
        ans = max(ans,a[u]+max(0ll,costs.back()));;
        ans = max(ans,costs[costs.size()-1]+costs[costs.size()-2]);
        ll cur = a[u]+costs[costs.size()-1]+costs[costs.size()-2]+costs[costs.size()-3];
        for(int i=costs.size()-4;i>=0;--i)
            if(costs[i]>=0)
                cur+=costs[i];
        ans = max(ans,cur);
        cur = a[u]+costs[costs.size()-1]+costs[costs.size()-2];
        for(int i=costs.size()-3;i>=0;--i)
            if(costs[i]>=0)
                cur+=costs[i];
        return max(max(a[u],costs.back()),cur);
    }
}
void solve()
{
    int n;
    cin>>n;
    vll a(n);
    cin>>a;
    vector<vi> g(n);
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll ans = 0;
    dfs(0,0,g,a,ans);
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
	return 0;
}
