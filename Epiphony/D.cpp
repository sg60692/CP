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
long long gcdExtended(long long a, long long b, long long *x, long long *y) 
{ 
    // Base Case 
    if (a == 0) 
    { 
        *x = 0; 
        *y = 1; 
        return b; 
    } 
 
    long long x1, y1; // To store results of recursive call 
    long long gcd = gcdExtended(b%a, a, &x1, &y1); 
 
    // Update x and y using results of 
    // recursive call 
    *x = y1 - (b/a) * x1; 
    *y = x1; 
 
    return gcd; 
} 
void solve()
{
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long u = b-a;
    long long g = __gcd(c,d);
    if(u%g){
        cout<<"-1\n";
        return;
    }
    u/=g;
    c/=g;
    d/=g;
    long long k,l;
    gcdExtended(c,d,&k,&l);
    k = ((k+d)%d);
    k = (k*u)%d;
    if((c*k)<u){
        long long e = u-(c*k);
        long long l = c*d;
        long long r = (e+l-1)/l;
        k = (k+r*d);
    }
    cout<<((c*g*k)+a)<<"\n";
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
