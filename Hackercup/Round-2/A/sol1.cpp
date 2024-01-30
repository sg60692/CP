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

void solve()
{
    int r,c;
    cin>>r>>c;
    vector<string> arr(r);
    cin>>arr;
    vector<vector<int>> visit(r,vector<int> (c));
    auto ans = visit;
    vector<int> d = {1,0,-1,0,1};
    vector<pair<int,int>> cur;
    int sz = 0;
    function<void(int,int)> dfs = [&](int i,int j){
        visit[i][j] = 1;
        ++sz;
        for(int k=0;k<4;++k){
            int ni = i+d[k];
            int nj = j+d[k+1];
            if((ni>=0)&&(ni<r)&&(nj>=0)&&(nj<c)){
                if(arr[ni][nj]=='.'){
                    if(cur.empty()||(cur.back()!=make_pair(ni,nj)))
                        cur.push_back(make_pair(ni,nj));
                }
                else if(arr[ni][nj]=='W'){
                    if(!visit[ni][nj])
                        dfs(ni,nj);
                }
            }
        }
    };
    for(int i=0;i<r;++i){
        for(int j=0;j<c;++j){
            if(visit[i][j]||(arr[i][j]!='W'))
                continue;
            cur.clear();
            sz = 0;
            dfs(i,j);
            if(cur.size()==1){
                ans[cur[0].F][cur[0].S]+=sz;
            }
        }
    }
    int fans = 0;
    for(auto x:ans)
        for(auto y:x)
            fans = max(fans,y);
    if(fans)cout<<"YES\n";
    else cout<<"NO\n";
}
int main()
{
    
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int i=1;i<=t;++i){
        cout<<"Case #"<<i<<": ";
        solve();
    }
	return 0;
}
