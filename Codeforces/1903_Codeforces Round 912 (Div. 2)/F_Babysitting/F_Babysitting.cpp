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
vector<vi> g;
vi top,visit;
int n,m,cnt;
void gdfs(int,int,int,int);
void dfs(int);
void gdfs(int cur,int l,int r,int L,int R){
    if(l==r){
        if(!visit[(l<<1)|1])
            dfs((l<<1)|1);
    }
    else{
        if(visit[cur]&&(L<=l)&&(R>=r))return;
        if((L<=l)&&(R>=r))visit[cur] = 1;
        int mid = (l+r)>>1;
        if(L<=mid)gdfs(cur+1,l,mid,L,R);
        if(R>mid)gdfs(cur+mid-l+1,mid+1,r,L,R);
        
    }
}
void dfs(int u){
    visit[u] = cnt;
    for(auto v:g[u]){
        if(!visit[v])
            dfs(v);
    }
    if(!(u&1)){
        int id = u>>1;
        int l = max(id-m+1,0), r = id-1;
        if(l<=r){
            gdfs(g.size(),0,n-1,l,r);
        }
        l = id+1, r = min(n,id+m)-1;
        if(l<=r){
            gdfs(g.size(),0,n-1,l,r);
        }
    }
    top.pb(u);
}
bool check(){
    top.clear();
    visit.clear();
    visit.resize(g.size()+n);
    cnt = 1;
    for(int i=0;i<(n<<1);++i)
        if(!visit[i])
            dfs(i);
    visit.clear();
    visit.resize(g.size()+n);
    cnt = 0;
    vi temp = top;
    top.clear();
    while(!temp.empty()){
        int u = temp.back();
        temp.pop_back();
        if(visit[u^1]){
            if(visit[u^1]==visit[u])
                return false;
            continue;
        }
        ++cnt;
        dfs(u^1);
    }
    return true;
}
void solve()
{
    cin>>n>>m;
    g.clear();
    g.resize(n<<1);
    for(int i=0;i<m;++i){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[(u<<1)|1].pb(v<<1);
        g[(v<<1)|1].pb(u<<1);
    }
    int l = 2, r = n, f=1;
    while(l<=r){
        m = (l+r)>>1;
        if(check()){
            f = m;
            l = m+1;
        }
        else{
            r = m-1;
        }
    }
    cout<<f<<"\n";
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
