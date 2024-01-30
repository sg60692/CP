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
    vector<int> c(n),d(n+1,n-1);
    cin>>c;
    d[n] = n;
    for(int i=n-2;i>=0;--i){
        if(c[i]<c[d[i+1]])
            d[i] = i;
        else
            d[i] = d[i+1];
    }
    int k;
    cin>>k;
    vector<pair<int,int>> g(1,make_pair(0,k));
    vector<int> ans(n);
    for(int i=d[0],j=-1;i<n;i = d[i+1]){
        int fre = 0;
        while(!g.empty()){
            auto t = g.back();
            g.pop_back();
            int cur = k/(c[i]-t.F);
            if(cur<t.S){
                k-=(cur*(c[i]-t.F));
                g.pb(make_pair(t.F,t.S-cur));
                fre+=cur;
                break;
            }
            else{
                k-=(t.S*(c[i]-t.F));
                fre+=t.S;
            }
        }
        if(fre){
            g.pb(make_pair(c[i],fre));
            for(int s=j+1;s<=i;++s){
                ans[s] = fre;
            }
            j = i;
        }
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
