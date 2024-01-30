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
const int mod = 998244353;
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n),p(n+1,1);
    cin>>a;
    for(int i=1;i<=n;++i){
        p[i] = p[i-1]<<1;
        if(p[i]>=mod)
            p[i]-=mod;
    }
    unordered_set<int> s;
    unordered_set<int> present;
    unordered_map<int,int> rep;
    deque<int> arr;
    for(auto x:a)
        s.insert(x);
    int dist = s.size();
    int ans = p[s.size()-1];
    bool check = true;
    int rans = (mod+1)>>1;
    int ind = 0;
    function<int(int)> get = [&](int x){
        return (x==rep[x])?x:(rep[x]=get(rep[x]));
    };
    for(int i=0;i<n;++i){
        if(present.find(a[i])==present.end()){
            present.insert(a[i]);
            arr.pb(a[i]);
            if(rep.find(a[i])==rep.end())
                rep[a[i]] = a[i];
        }
        else{
            present.erase(a[i]);
            if(arr[ind]!=a[i]){
                check = false;
                break;
            }
            ++ind;
            if(arr.size()==ind){
                bool cur_check = true;
                for(int j=1;j<ind;++j){
                    int u = get(arr[j-1]);
                    int v = get(arr[j]);
                    if(u!=v)
                        rep[u] = v;
                }
                arr.clear();
                ind = 0;
            }
        }
    }
    for(auto e:rep){
        if(e.F==e.S){
            rans <<= 1;
            if(rans>=mod)
                rans-=mod;
        }
    }
    if(check&&arr.empty())
        ans = (ans+mod-rans)%mod;
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin>>t;
    while(t--)solve();
	return 0;
}
