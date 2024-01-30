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
long long setBitNumber(long long n)
{
    // Below steps set bits after
    // MSB (including MSB)
 
    // Suppose n is 273 (binary
    // is 100010001). It does following
    // 100010001 | 010001000 = 110011001
    n |= n >> 1;
 
    // This makes sure 4 bits
    // (From MSB and including MSB)
    // are set. It does following
    // 110011001 | 001100110 = 111111111
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n |= n >> 32; 
    return (n+1)>>1;
}
void solve()
{
    int n;
    cin>>n;
    vector<long long> a(n);
    cin>>a;
    vector<long long> hBit(n);
    vector<int> always(n);
    string ans;
    for(int i=0;i<n;++i){
        long long cur = 0;
        for(int j=i;j<n;++j)
            cur^=a[j];
        bool curAlways = false;
        long long pos = 0;
        for(int j=n-1;j>=i;--j){
            if(
                always[j]
                ||
                (cur&hBit[j])
                ||
                (curAlways)
                ||
                (cur&pos)
                ||
                ((i==0)&&(j==(n-1)))
            )
            {
                hBit[j]|=setBitNumber(cur);
                pos|=setBitNumber(cur);
                if(j==i)
                    ans+='1';
            }
            else if(j==i){
                ans+='0';
            }
            cur^=a[j];
        }
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
