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
const int mod = 998244353;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vll a(n);
    vi sz(n,1),p(n),add(n);
    cin>>a;
    iota(p.begin(),p.end(),0);
    vector<vector<int>> g(n);
    function<int(int)> get = [&](int u){
        return (u==p[u])?u:p[u]=get(p[u]);
    };
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        --u;--v;
        u = get(u);
        v = get(v);
        if(u==v)continue;
        long long su = a[u]/sz[u];
        long long sv = a[v]/sz[v];
        if(su>sv){
            ++add[u];
        }
        if(sv>su){
            ++add[v];
        }
        int cur = p.size();
        g.push_back({u,v});
        sz.push_back(sz[u]+sz[v]);
        a.push_back(a[u]+a[v]);
        p[u] = p[v] = cur;
        p.push_back(cur);
        add.push_back(0);
    }
    queue<int> q;
    for(int i=0;i<p.size();++i){
        if(p[i]==i){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:g[u]){
            add[v]+=add[u];
            q.push(v);
        }
    }
    for(int i=0;i<n;++i)cout<<add[i]<<" ";cout<<"\n";
	return 0;
}
