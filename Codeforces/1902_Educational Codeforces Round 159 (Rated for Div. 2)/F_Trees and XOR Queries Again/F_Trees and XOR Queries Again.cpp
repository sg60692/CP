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
const int B = 20;
const int N = 2e5;
vector<vi> g(N),par(N,vi(B));
vector<vi> qu(N,vi(B,-1)),qv(N,vi(B,-1)),qw(N,vi(B,-1));
vector<vi> to(N,vi(B)),prevT(N,vi(B));
vector<vi> Q(N,vi(B));
vi a(N),h(N),z(N);
inline void ins(vector<int> &t,int x){
    for(int i=B-1;i>=0;--i){
        if(!((x>>i)&1))continue;
        if(t[i])x^=t[i];
        else{
            t[i] = x;
            break;
        }
    }
}
inline void combine(vi &U,vi &V){
    for(int i=0;i<B;++i){
        if(V[i])
            ins(U,V[i]);
    }
}
void dfs(int u,int p){
    par[u][0] = p;
    ins(to[u],a[u]);
    for(int i=1;i<B;++i){
        par[u][i] = par[par[u][i-1]][i-1];
    }
    h[u] = h[p]+1;
    for(auto v:g[u]){
        if(v!=p)
            dfs(v,u);
    }
}
inline void path(int u,int v,int q){
    if(u==v){
        ins(Q[q],a[u]);
        return;
    }
    if(h[u]<h[v])
        swap(u,v);
    for(int i=B-1;i>=0;--i){
        if((h[par[u][i]]>=h[v])){
            qu[q][i] = u;
            u = par[u][i];
        }
    }
    if(u==v){
        ins(Q[q],a[u]);
        return;
    }
    for(int i=B-1;i>=0;--i){
        if(par[u][i]!=par[v][i]){
            qv[q][i] = u;
            qw[q][i] = v;
            u = par[u][i];
            v = par[v][i];
        }
    }
    ins(Q[q],a[u]);
    ins(Q[q],a[v]);
    ins(Q[q],a[par[u][0]]);
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>a[i];
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0,0);
    int q;
    cin>>q;
    for(int o=0;o<q;++o){
        int x,y,k;
        cin>>x>>y>>k;
        --x;--y;
        z[o] = k;
        path(x,y,o);
    }
    for(int j=0;j<q;++j){
        if(qu[j][0]!=-1)
            combine(Q[j],to[qu[j][0]]);
        if(qv[j][0]!=-1)
            combine(Q[j],to[qv[j][0]]);
        if(qw[j][0]!=-1)
            combine(Q[j],to[qw[j][0]]);
    }
    for(int i=1;i<B;++i){
        for(int j=0;j<n;++j)
            for(int k=0;k<B;++k)
                prevT[j][k] = to[j][k];
        for(int j=0;j<n;++j){
            combine(to[j],prevT[par[j][i-1]]);
        }
        for(int j=0;j<q;++j){
            if(qu[j][i]!=-1)
                combine(Q[j],to[qu[j][i]]);
            if(qv[j][i]!=-1)
                combine(Q[j],to[qv[j][i]]);
            if(qw[j][i]!=-1)
                combine(Q[j],to[qw[j][i]]);
        }
    }
    for(int i=0;i<q;++i){
        bool ans = true;
        int k = z[i];
        vi &cur = Q[i];
        for(int j=B-1;j>=0;--j){
            if(!((k>>j)&1))continue;
            if(cur[j])k^=cur[j];
            else{
                ans = false;
                break;
            }
        }
        cout<<(ans?"YES":"NO")<<"\n";
    }
	return 0;
}
