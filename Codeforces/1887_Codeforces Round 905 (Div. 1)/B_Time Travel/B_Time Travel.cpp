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
    int n,t;
    cin>>n>>t;
    unordered_map<int,unordered_map<int,unordered_set<int>>> edges;
    unordered_set<int> reach;
    unordered_map<int,unordered_set<int>> activeTimeToVertex,activeVertexToTime;
    for(int i=1;i<=t;++i){
        int m;
        cin>>m;
        while(m--){
            int u,v;
            cin>>u>>v;
            edges[i][u].insert(v);
            edges[i][v].insert(u);
            activeVertexToTime[u].insert(i);
            activeVertexToTime[v].insert(i);
        }
    }
    int k;
    cin>>k;
    vector<int> a(k);
    cin>>a;
    function<void(int)> add = [&](int x){
        if(reach.find(x)!=reach.end())return;
        reach.insert(x);
        for(auto t:activeVertexToTime[x]){
            activeTimeToVertex[t].insert(x);
        }
    };
    add(1);
    for(int i=0;i<k;++i){
        vector<int> to;
        for(auto u:activeTimeToVertex[a[i]]){
            for(auto v:edges[a[i]][u]){
                to.pb(v);
            }
        }
        activeTimeToVertex[a[i]].clear();
        for(auto v:to)
            add(v);
        if(reach.find(n)!=reach.end()){
            cout<<(i+1)<<"\n";
            return;
        }
    }
    cout<<"-1\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)solve();
	return 0;
}
