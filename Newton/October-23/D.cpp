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
void build(int i,int l,int r,string &s,vector<pair<ll,ll>> &seg){
    if(l==r){
        if(s[l-1]=='0')
            seg[i] = mp(0ll,(l*1ll*l));
        else
            seg[i] = mp(l*1ll*l,0ll);
    }
    else{
        int mid = (l+r)>>1;
        int z = (mid+1-l)<<1;
        build(i+1,l,mid,s,seg);
        build(i+z,mid+1,r,s,seg);
        seg[i].F = seg[i+1].F+seg[i+z].F;
        seg[i].S = seg[i+1].S+seg[i+z].S;
    }
}
void build2(int i,int l,int r,string &s,vector<pair<ll,ll>> &seg){
    if(l==r){
        if(s[l-1]=='0')
            seg[i] = mp(0ll,(l*1ll));
        else
            seg[i] = mp(l*1ll,0ll);
    }
    else{
        int mid = (l+r)>>1;
        int z = (mid+1-l)<<1;
        build2(i+1,l,mid,s,seg);
        build2(i+z,mid+1,r,s,seg);
        seg[i].F = seg[i+1].F+seg[i+z].F;
        seg[i].S = seg[i+1].S+seg[i+z].S;
    }
}
void build3(int i,int l,int r,string &s,vector<pair<ll,ll>> &seg){
    if(l==r){
        if(s[l-1]=='0')
            seg[i] = mp(0ll,1ll);
        else
            seg[i] = mp(1ll,0ll);
    }
    else{
        int mid = (l+r)>>1;
        int z = (mid+1-l)<<1;
        build3(i+1,l,mid,s,seg);
        build3(i+z,mid+1,r,s,seg);
        seg[i].F = seg[i+1].F+seg[i+z].F;
        seg[i].S = seg[i+1].S+seg[i+z].S;
    }
}
void update(int i,int l,int r,int L,int R,vector<pair<ll,ll>> &seg,vector<int> &lazy){
    if((L<=l)&&(R>=r)){
        swap(seg[i].F,seg[i].S);
        lazy[i]^=1;
    }
    else{
        int mid = (l+r)>>1;
        int z = (mid+1-l)<<1;
        if(lazy[i]){
            swap(seg[i+1].F,seg[i+1].S);
            swap(seg[i+z].F,seg[i+z].S);
            lazy[i+1]^=1;
            lazy[i+z]^=1;
            lazy[i] = 0;
        }
        if(L<=mid)update(i+1,l,mid,L,R,seg,lazy);
        if(R>mid)update(i+z,mid+1,r,L,R,seg,lazy);
        seg[i].F = seg[i+1].F+seg[i+z].F;
        seg[i].S = seg[i+1].S+seg[i+z].S;
    }
}
ll get(int i,int l,int r,int L,int R,vector<pair<ll,ll>> &seg,vector<int> &lazy){
    if((L<=l)&&(R>=r)){
        return seg[i].F;
    }
    else{
        int mid = (l+r)>>1;
        int z = (mid+1-l)<<1;
        if(lazy[i]){
            swap(seg[i+1].F,seg[i+1].S);
            swap(seg[i+z].F,seg[i+z].S);
            lazy[i+1]^=1;
            lazy[i+z]^=1;
            lazy[i] = 0;
        }
        ll ans = 0;
        if(L<=mid)
            ans+=get(i+1,l,mid,L,R,seg,lazy);
        if(R>mid)
            ans+=get(i+z,mid+1,r,L,R,seg,lazy);
        return ans;
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<pair<ll,ll>> seg(n<<1),s2(n<<1),s3(n<<1);
    vector<int> lazy(n<<1),l2(n<<1),l3(n<<1);
    build(0,1,n,s,seg);
    build2(0,1,n,s,s2);
    build3(0,1,n,s,s3);
    int q;
    cin>>q;
    while(q--){
        int o,l,r;
        cin>>o>>l>>r;
        if(o==1){
            update(0,1,n,l,r,seg,lazy);
            update(0,1,n,l,r,s2,l2);
            update(0,1,n,l,r,s3,l3);
        }
        else{
            ll k = l-1;
            ll ans = get(0,1,n,l,r,seg,lazy)+(k*k*get(0,1,n,l,r,s3,l3))-(2*k*get(0,1,n,l,r,s2,l2));
            cout<<ans<<"\n";
        }
    }
	return 0;
}