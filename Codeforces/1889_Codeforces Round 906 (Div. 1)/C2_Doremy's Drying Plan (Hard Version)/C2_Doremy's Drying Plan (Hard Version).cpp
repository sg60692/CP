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
int get(int i,int l,int r,int L,int R,vector<int> &seg){
    if((L<=l)&&(R>=r))return seg[i];
    int mid = (l+r)>>1;
    int z = (mid+1-l)<<1;
    int ans = 0;
    if(L<=mid)ans = max(ans,get(i+1,l,mid,L,R,seg));
    if(R>mid)ans = max(ans,get(i+z,mid+1,r,L,R,seg));
    return ans;
}
void update(int i,int l,int r,int pos,int val,vector<int> &seg){
    if(l==r)
        seg[i] = val;
    else{
        int mid = (l+r)>>1;
        int z = (mid+1-l)<<1;
        if(pos<=mid)update(i+1,l,mid,pos,val,seg);
        else update(i+z,mid+1,r,pos,val,seg);
        seg[i] = max(seg[i+1],seg[i+z]);
    }
}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> dp(n+1,vector<int>(k+1)),b(n),q(n),seg(k+1,vector<int>(n<<1));
    auto gp = dp;
    for(int i=0;i<m;++i){
        int l,r;
        cin>>l>>r;
        q[r-1].pb(l-1);
        b[l-1].pb(r-1);
    }
    multiset<int> start;
    for(int i=0;i<n;++i){
        for(int j=0;j<=k;++j)
            dp[i+1][k] = max(dp[i][k],gp[i][k]);
        int t = start.size()+b[i].size();
        if(t<=k){
            vector<int> e;
            for(auto x:start)
                e.pb(x);
            int prev = 0;
            for(int l=0;l<e.size();++l){
                if(prev!=e[l]){
                    for(int u=t;u<=k;++u){
                        gp[i+1][u] = max(
                            get(0,1,n,prev+1,e[l],seg[u-e.size()-b[i].size()+l])+1,
                            gp[i+1][u]
                        );
                    }
                    prev = e[l];
                }
            }
            for(int j=t;j<=k;++j){
                gp[i+1][j] = max(gp[i+1][j],1+get(0,1,n,prev+1,n,seg[j-b[i].size()]));
            }
            for(int j=t;j<=k;++j)
                update(0,1,n,i+1,gp[i+1][j],seg[j]);
        }
        for(int x:b[i])
            start.insert(i);
        for(int x:q[i])
            start.erase(start.find(x));
    }
    cout<<max(dp[n][k],gp[n][k])<<"\n";
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
