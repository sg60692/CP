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

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int n = s.length();
    int cnt1 = 0, cnt0 = 0;
    for(int i=0;i<n;++i){
        if(s[i]=='1')
            ++cnt1;
        else
            ++cnt0;
    }
    int need = ((n*(n-1))-(cnt1*(cnt1-1))-(cnt0*(cnt0-1)))>>2;
    vector<vector<int> > dp(cnt1+1,vector<int> (need+1,n+1));
    dp[0][0] = 0;
    for(int i=1;i<=n;++i){
        for(int j=min(cnt1,i);j>=0;--j){
            for(int k=0;k<=need;++k){
                dp[j][k] += (s[i-1]=='1');
                if((j>0)&&(k>=(i-j)))
                    dp[j][k] = min(dp[j][k],dp[j-1][k-(i-j)]);
            }
        }
    }
    cout<<dp[cnt1][need]<<"\n";
	return 0;
}
