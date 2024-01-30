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
    int m;
    cin>>m;
    vector<vector<ll>> a(m),c(m);
    vector<ll> l(m),r(m),t(m);
    for(int i=0;i<m;++i){
        int n;
        cin>>n>>l[i]>>r[i];
        a[i].resize(n);
        c[i].resize(n);
        cin>>a[i]>>c[i];
        for(auto x:c[i])
            t[i]+=x;
    }
    ll L = 0, R = 0;
    for(int i=0;i<m;++i){
        L+=l[i];
        R+=r[i];
        if(R>1e17){
            cout<<"0\n";
            return;
        }
    }
    map<ll,ll> fixed,tot;
    for(int i=0;i<m;++i){
        for(int j=0;j<a[i].size();++j){
            if((t[i]-c[i][j])<r[i]){
                tot[a[i][j]] += r[i]-t[i]+c[i][j];
            }
            if((t[i]-c[i][j])<l[i]){
                fixed[a[i][j]] += l[i]-t[i]+c[i][j];
            }
        }
    }
    ll ans = 1e17;
    while(L<=R){
        ll cur = fixed[L];
        if((R-tot[L])<(L-fixed[L]))
            cur+=((L-fixed[L])-(R-tot[L]));
        ans = min(ans,cur);
        if(ans==0)
            break;
        ++L;
    }
    cout<<ans<<"\n";
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
