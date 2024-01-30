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
    int sx,sy;
    cin>>sx>>sy;
    int s = (sx&1)^(sy&1);
    vector<int> a(n);
    set<int> one,zero;
    for(int i=0;i<n;++i){
        int x,y;
        cin>>x>>y;
        a[i] = (x&1)^(y&1);
        if(a[i])one.insert(i+1);
        else zero.insert(i+1);
    }
    int cnt=0;
    auto moveSelf = [](set<int> &s,set<int> &e){
        if(s.empty()){
            cout<<(*e.begin())<<endl;
            e.erase(e.begin());
        }
        else{
            cout<<(*s.begin())<<endl;
            s.erase(s.begin());
        }
    };
    if(s==0){
        if(zero.size()>=one.size()){
            cout<<"First"<<endl;
            int cnt = 0;
            while(cnt<n){
                if(cnt&1){
                    int x;
                    cin>>x;
                    if(a[x-1])one.erase(x);
                    else zero.erase(x);
                }
                else moveSelf(one,zero);
                ++cnt;
            }
        }
        else{
            cout<<"Second"<<endl;
            int cnt = 1;
            while(cnt<=n){
                if(cnt&1){
                    int x;
                    cin>>x;
                    if(a[x-1])one.erase(x);
                    else zero.erase(x);
                }
                else moveSelf(zero,one);
                ++cnt;
            }
        }
    }
    else{
        if(one.size()>=zero.size()){
            cout<<"First"<<endl;
            int cnt = 0;
            while(cnt<n){
                if(cnt&1){
                    int x;
                    cin>>x;
                    if(a[x-1])one.erase(x);
                    else zero.erase(x);
                }
                else moveSelf(zero,one);
                ++cnt;
            }
        }
        else{
            cout<<"Second"<<endl;
            int cnt = 1;
            while(cnt<=n){
                if(cnt&1){
                    int x;
                    cin>>x;
                    if(a[x-1])one.erase(x);
                    else zero.erase(x);
                }
                else moveSelf(one,zero);
                ++cnt;
            }
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
