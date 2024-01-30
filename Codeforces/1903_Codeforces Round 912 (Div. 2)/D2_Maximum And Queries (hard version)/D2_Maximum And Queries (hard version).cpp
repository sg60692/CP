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
const int B = 19;
struct node{
    int n;
    ll sum;
    node():n(0),sum(0){}
};
void build(int cur,vpii &a,int h,vector<node> &nodes){
    vpii b;
    vpii c;
    for(int i=0;i<a.size();++i){
        if((a[i].F>>h)&1){
            c.pb(mp(a[i].F^(1<<h),a[i].S));
        }
        else{
            nodes[cur].n+=a[i].S;
            nodes[cur].sum+=(a[i].S*((1ll<<h)-a[i].F));
            b.pb(a[i]);
        }
    }
    if(!h)return;
    vpii d;
    int u = 0, v = 0;
    while((u<b.size())&&(v<c.size())){
        if(b[u].F<c[v].F){
            d.pb(b[u++]);
        }
        else if(b[u].F>c[v].F){
            d.pb(c[v++]);
        }
        else{
            d.pb(mp(b[u].F,b[u].S+c[v].S));
            ++u;++v;
        }
    }
    while(u<b.size())
        d.pb(b[u++]);
    while(v<c.size())
        d.pb(c[v++]);
    build(cur+1,c,h-1,nodes);
    build(cur+(1<<h),d,h-1,nodes);
}
void solve()
{
    int n,q;
    cin>>n>>q;
    vpii a(n);
    int m = 0;
    ll sum = 0;
    for(int i=0;i<n;++i){
        cin>>a[i].F;
        a[i].S = 1;
        m = max(a[i].F,m);
        sum+=a[i].F;   
    }
    vector<node> nodes(1<<(B+1));
    sum = (m*1ll*n)-sum;
    sort(a.begin(),a.end());
    vpii b;
    for(int i=0,j=0;i<n;i=j){
        while((j<n)&&(a[i]==a[j]))++j;
        b.pb(mp(a[i].F,j-i));
    }
    build(0,b,B,nodes);
    while(q--){
        ll k;
        cin>>k;
        if(k>=sum){
            cout<<(m+((k-sum)/n))<<"\n";
        }
        else{
            int ans = 0, cur = 0;
            ll cnt = 0;
            for(int h=B;h>=0;--h){
                if(k>=((cnt<<h)+nodes[cur].sum)){
                    k-=((cnt<<h)+nodes[cur].sum);
                    ans|=(1<<h);
                    cnt+=nodes[cur].n;
                    cur = cur+1;
                }
                else{
                    cur = cur+(1<<h);
                }
            }
            cout<<ans<<"\n";
        }
    }
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
