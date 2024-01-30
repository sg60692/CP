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

void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<ll> h(n),in(n),out(n);
    cin>>h;
    vector<long long> act(n,0);
    vector<int> g[n],rev[n];
    for(int i=0;i<m;++i){
        int a,b;
        cin>>a>>b;
        --a;--b;
        ++in[b],++out[a];
        g[a].pb(b);
        rev[b].pb(a);
    }
    queue<int> q;
    for(int i=0;i<n;++i){
        if(out[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        auto u = q.front();
        q.pop();
        for(auto v:rev[u]){
            --out[v];
            if(h[v]<=h[u]){
                act[v] = max(act[v],act[u]+h[u]-h[v]);
            }
            else{
                act[v] = max(act[v],act[u]+k-h[v]+h[u]);
            }
            act[v] = max(act[v],act[u]);
            if(!out[v])
                q.push(v);
        }
    }
    vector<pair<int,long long>> d;
    for(int i=0;i<n;++i){
        if(in[i]==0){
            //cout<<i<<" "<<h[i]<<" "<<act[i]<<"\n";
            d.pb(make_pair(h[i],act[i]));
        }
    }
    sort(d.begin(),d.end());
    vector<long long> suff(d.size()),pref(d.size());
    for(int i=d.size()-1;i>=0;--i){
        if(i==(d.size()-1))
            suff[i] = d[i].F+d[i].S;
        else{
            suff[i] = max(d[i].S+d[i].F,suff[i+1]);
        }
    }
    long long fans = 1ll<<60;
    for(int i=0;i<d.size();++i){
        if(i){
            fans = min(fans,max(suff[i],pref[i-1]+k)-d[i].F);
            pref[i] = max(pref[i-1],d[i].F+d[i].S);
        }
        else{
            fans = min(fans,suff[0]-d[0].F);
            pref[i] = d[i].S+d[i].F;  
        }
    }
    cout<<(fans)<<"\n";
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
