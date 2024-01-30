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
    vi a(n);
    cin>>a;
    sort(a.begin(),a.end());
    if(a[0]==a.back()){
        cout<<"1\n";
        return;
    }
    unordered_set<ll> S;
    int u = a.back()-a[0];
    for(int i=1;i<n;++i){
        S.insert(a[i-1]);
        if(a[i-1]!=a.back())
            u = __gcd(u,a.back()-a[i-1]);
    }
    ll ans = 0;
    for(int i=1;i<n;++i){
        ans+=((a.back()-a[i-1])/u);
    }
    int e = 1;
    while(S.find(a.back()-(e*1ll*u))!=S.end())
        ++e;
    cout<<(ans+e)<<"\n";
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
