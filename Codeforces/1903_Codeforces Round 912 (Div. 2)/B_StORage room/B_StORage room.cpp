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
    vector<vi> a(n,vi(n));
    cin>>a;
    vi b(n);
    for(int i=0;i<n;++i){
        for(int k=0;k<30;++k){
            int cnt = 0;
            for(int j=0;j<n;++j){
                cnt+=((a[i][j]>>k)&1);
                cnt+=((a[j][i]>>k)&1);
            }
            if(cnt==((n-1)<<1))
                b[i]|=(1<<k);
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(i==j)continue;
            if((a[i][j]!=(b[i]|b[j]))){
                cout<<"NO\n";
                return;
            }
        }
    }
    cout<<"YES\n";
    cout<<b<<"\n";
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
