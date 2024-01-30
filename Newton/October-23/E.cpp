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
    int n;
    cin>>n;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vi p(n+1);
    vector<map<int,int>> m(n+1);
    for(int i=1;i<=n;++i){
        p[i] = i;
        int t;
        cin>>t;
        m[i][t] = 1;
    }
    function<int(int)> get = [&](int x){
        return x==p[x]?x:(p[x]=get(p[x]));
    };
    while(q--){
        int o,l,r;
        cin>>o>>l>>r;
        if(o==1){
            int u = get(l);
            int v = get(r);
            if(u!=v){
                if(m[u].size()>m[v].size())
                    swap(u,v);
                for(auto x:m[u])
                    m[v][x.F]+=x.S;
                p[u] = v;
            }
        }
        else{
            int u = get(l);
            cout<<m[u][r]<<"\n";
        }
    }
	return 0;
}