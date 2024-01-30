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
vector<pair<int,ll>> merge(vector<pair<int,ll>> a,vector<pair<int,ll>> b){
    vector<pair<int,ll>> res;
    ll left = 0;
    ll right = 0;
    int i = 0;
    int j = 0;
    while((i<a.size())&&(j<b.size())){
        if(a[i].F<b[j].F){
            left = a[i].S;
            res.pb(make_pair(a[i].F,left+right));
            ++i;
        }
        else if(a[i].F>b[j].F){
            right = b[j].S;
            res.pb(make_pair(b[j].F,left+right));
            ++j;
        }
        else{
            left = a[i].S;
            right = b[j].S;
            res.pb(make_pair(a[i].F,left+right));
            ++i;++j;
        }
    }
    while((i<a.size())){
        left = a[i].S;
        res.pb(make_pair(a[i].F,left+right));
        ++i;
    }
    while((j<b.size())){
        right = b[j].S;
        res.pb(make_pair(b[j].F,left+right));
        ++j;
    }
    return res;
}
bool comp(vector<pair<int,long long>> a,vector<pair<int,long long>> b){
    ll left = 0;
    ll right = 0;
    int i = 0;
    int j = 0;
    while((i<a.size())&&(j<b.size())){
        if(a[i].F<b[j].F){
            left = a[i].S;
            ++i;
        }
        else if(a[i].F>b[j].F){
            right = b[j].S;
            ++j;
        }
        else{
            left = a[i].S;
            right = b[j].S;
            ++i;++j;
        }
        if(left!=right)
            return left<right;
    }
    while((i<a.size())){
        left = a[i].S;
        ++i;
        if(left!=right)
            return left<right;
    }
    while((j<b.size())){
        right = b[j].S;
        if(left!=right)
            return left<right;
        ++j;
    }
    return left<right;
}
pair<
    vector<pair<int,long long>>,
    vector<pair<int,long long>>> 
fsolve(int l,int r,vector<vector<int>> &q){
    if(l==r){
        vector<pair<int,ll>> res;
        vector<pair<int,ll>> pos(1,make_pair(1,0ll));
        if(q[l][0]>1){
            res.pb(make_pair(1,0ll));
        }
        res.pb(make_pair(q[l][0],q[l][2]));
        res.pb(make_pair(q[l][1]+1,0ll));
        if(comp(res,pos)){
            return make_pair(res,res);
        }
        return make_pair(pos,res);
    }
    else{
        int mid = (l+r)>>1;
        auto left = fsolve(l,mid,q);
        auto right = fsolve(mid+1,r,q);
        auto net = merge(left.S,right.S);
        auto to = merge(left.S,right.F);
        comp(to,left.F);
        if(comp(to,left.F))
            return make_pair(to,net);
        return make_pair(left.F,net);
    }
}
void solve()
{
    int n;
    cin>>n;
    vll a(n);
    cin>>a;
    int q;
    cin>>q;
    if(!q){
        cout<<a<<"\n";
        return;
    }
    vector<vector<int>> qu(q,vector<int>(3));
    cin>>qu;
    auto m = fsolve(0,q-1,qu).F;
    m.push_back(make_pair(n+2,0ll));
    //cout<<m<<endl;
    for(int i=1;i<m.size();++i){
        for(int j=m[i-1].F;j<min(n+1,m[i].F);++j){
            a[j-1]+=m[i-1].S;
        }
    }
    cout<<a<<endl;
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
