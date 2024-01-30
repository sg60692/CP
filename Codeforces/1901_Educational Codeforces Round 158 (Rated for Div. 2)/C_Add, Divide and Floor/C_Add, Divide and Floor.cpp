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
    vi b = a;
    ll r = 1;
    int ans = 0;
    ll x=0;
    auto check = [&](){
        for(int i=1;i<n;++i)
            if(a[i]!=a[i-1])
                return false;
        return true;
    };
    if(check()){
        cout<<"0\n";
        return;
    }
    auto check2 = [&](){
        ll k = r;
        r = (r<<1)|r;
        for(auto &x:a)
            x>>=1;
        int u = 0;
        int v = 1;
        while((v<n)&&(a[u]==a[v]))
            ++v;
        if(v==n)
            return true;
        if(a[u]>a[v])
            swap(u,v);
        if((a[u]+1)!=a[v])
            return false;
        ll zL = INT_MIN, zR = INT_MAX;
        for(int i=0;i<n;++i){
            if((a[i]!=a[u])&&(a[i]!=a[v]))
                return false;
            int cur = b[i]&k;
            if(a[i]==a[u]){
                zL = max(zL,k+1-cur);
            }
            else{
                zR = min(zR,k-cur);
            }
        }
        if(zL>k)
            return false;
        if(zL<=zR){
            x = zL;
            return true;
        }
        return false;
    };
    ans = 1;
    while(!check2()){
        ++ans;
    }
    cout<<ans<<"\n";
    if(ans<=n){
        cout<<x<<" ";
        for(int i=1;i<ans;++i)
            cout<<"0 ";
        cout<<"\n";
    }
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
