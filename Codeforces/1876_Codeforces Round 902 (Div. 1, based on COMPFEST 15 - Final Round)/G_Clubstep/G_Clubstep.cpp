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
const int mod = 998244353, N = 1e5+1;
void solve()
{
    int n;
    cin>>n;
    vector<int> f(N+1);
    vector<int> p(n+1,1);
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        ++f[x];
    }
    for(int i=1;i<=n;++i){
        p[i] = p[i-1]<<1;
        if(p[i]>=mod)
            p[i]-=mod;
    }
    ll ans = 0;
    for(int i=N-1;i>0;--i){
        int r  = 0;
        for(int y=1;(y*1ll*y)<=i;++y){
            if(!(i%y)){
                r+=f[y];
                int z = i/y;
                if(z!=y)
                r+=f[z];
            }
        }
        ans = (ans+(r*1ll*(mod+p[n]-p[n-r])))%mod;
        n-=r;
    }
    cout<<ans<<"\n";
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
