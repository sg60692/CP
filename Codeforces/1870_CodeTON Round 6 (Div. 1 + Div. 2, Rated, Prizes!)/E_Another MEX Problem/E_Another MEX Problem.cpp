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
const int A = 1<<13;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n);
    cin>>a;
    vector<bitset<A>> dp(n+1);
    dp[0][0] = 1;
    for(int i=1;i<=n;++i){
        dp[i] = dp[i-1];
        vector<int> fre(n+2),exisit(A);
        int mex = 0;
        vector<int> ind;
        for(int j=0;j<A;++j){
            if(!dp[i][j])
                ind.pb(j);
        }
        for(int j=i-1;j>=0;--j){
            ++fre[a[j]];
            if(fre[a[i-1]]==2)
                break;
            while(fre[mex])
                ++mex;
            if((mex>a[i-1])&&(!exisit[mex])){
                exisit[mex]=1;
                vector<int> newInd;
                for(int s:ind){
                    if(dp[j][s^mex])
                        dp[i][s] = 1;
                    else
                        newInd.pb(s);
                }
                ind = newInd;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<A;++i){
        if(dp[n][i])
            ans = i;
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
