#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK: 1000000000")
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
const int N = pow(3,41/3)*2+1;
const int mx = 42;
int check;
vector<vector<int>> ans(N,vector<int>(mx,-1)),par(N,vector<int>(mx,-1));
void pre(){
    for(int i=0;i<mx;++i){
        ans[1][i] = i;
        par[1][i] = 1;
    }
    for(int i=1;i<N;++i){
        for(int j=1+(i==1);((i*1ll*j)<N)&&(j<mx);++j){
            for(int k=0;(k+j)<mx;++k){
                if(ans[i][k]==-1)
                    continue;
                if((ans[i*j][k+j]==-1)||(ans[i*j][k+j]>(ans[i][k]+1))){
                    par[i*j][k+j] = j;
                    ans[i*j][k+j] = ans[i][k]+1;
                }
            }
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    if((n>=N)||(par[n][mx-1]==-1)){
        cout<<"-1\n";
    }
    else{
        cout<<ans[n][mx-1]<<" ";
        int x = ans[n][mx-1];
        int sum = mx-1;
        while(x--){
            int e = par[n][sum];
            cout<<e<<" ";
            sum-=e;
            n/=e;
        }
        cout<<"\n";
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        cout<<"Case #"<<i<<": ";
        solve();
    }
	return 0;
}
