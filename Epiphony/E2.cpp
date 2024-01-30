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
const int mod = 1e9+7;
int powmod(int a,int p=mod-2){
    int res = 1;
    while(p){
        if(p&1)res=(res*1ll*a)%mod;
        p>>=1;
        a=(a*1ll*a)%mod;
    }
    return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vi a(n);
    vi sz(n,1),p(n),score(n),add(n);
    cin>>a;
    vi inv(max(n,m)+5,1);
    for(int i=2;i<inv.size();++i){
        inv[i] = mod-(((mod/i)*1ll*inv[mod%i])%mod);
    }
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
        int su = (a[u]*1ll*inv[sz[u]])%mod;
        int sv = (a[v]*1ll*inv[sz[v]])%mod;
        int t = powmod(su+sv);
        score[u]=(score[u]+su*1ll*t)%mod;
        score[v]=(score[v]+sv*1ll*t)%mod;
        int cur = p.size();
        g.push_back({u,v});
        sz.push_back((sz[u]+sz[v])%mod);
        a.push_back((a[u]+a[v])%mod);
        p[u] = p[v] = cur;
        p.push_back(cur);
        add.push_back(1);
        score.push_back(0);
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
            score[v]+=score[u];
            if(score[v]>=mod)
                score[v]-=mod;
            q.push(v);
        }
    }
    for(int i=0;i<n;++i){
        if(add[i])cout<<((score[i]*1ll*inv[add[i]])%mod)<<" ";
        else cout<<"-1 ";
    }cout<<"\n";
	return 0;
}
