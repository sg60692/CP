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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    cin>>a;
    vector<int> fre(n+1);
    for(auto x:a)
        if(x<=n)
            ++fre[x];
    int mx = 0, cur = 0;
    while(fre[mx])
        ++mx;
    cur = mx;
    for(int i=0;i<n;++i){
        if(a[i]<=n)
            --fre[a[i]];
        int prev = a[i];
        a[i] = cur;
        ++fre[cur];
        if((prev<mx)&&(fre[prev]==0)){
            cur = prev;
        }
        else{
            while(fre[mx])
                ++mx;
            cur = mx;
        }
    }
    a.push_back(cur);
    for(int i=0;i<n;++i){
        int j = (i-(k-1))%(n+1);
        if(j<0)
            j+=(n+1);
        cout<<a[j]<<" ";
    }
    cout<<"\n";
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
