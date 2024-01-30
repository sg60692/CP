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
    int n,m;
    cin>>n>>m;
    vector<string> a(n);
    cin>>a;
    auto b = a;
    for(int i=0;i<n;++i){
        int d = 0;
        for(int j=0;j<m;++j){
            if(a[i][j]=='U'){
                b[i][j] = d?'W':'B';
                d^=1;
                b[i+1][j] = d?'W':'B';
            }
        }
        if(d){
            cout<<"-1\n";
            return;
        }
    }
    for(int i=0;i<m;++i){
        int d = 0;
        for(int j=0;j<n;++j){
            if(a[j][i]=='L'){
                b[j][i] = d?'W':'B';
                d^=1;
                b[j][i+1] = d?'W':'B';
            }
        }
        if(d){
            cout<<"-1\n";
            return;
        }
    }
    for(auto &s:b)
        cout<<s<<"\n";
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
