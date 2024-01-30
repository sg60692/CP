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
const int mod = 1e9+7;
struct node{
    bool flip;
    pair<pair<int,int>,pair<int,int>> val;
    node(int _val,int _ind):
        flip(false),
        val(
            make_pair(
                make_pair(_val,-_ind),
                make_pair(mod-_val,-_ind)
            )
        ){}
    node(){}
};
vector<node> nodes;
inline void push(int i){
    if(nodes[i].flip){
        swap(nodes[i].val.F,nodes[i].val.S);
        if((i<<1)<nodes.size())
            nodes[i<<1].flip^=1;
        if(((i<<1)|1)<nodes.size())
            nodes[(i<<1)|1].flip^=1;
        nodes[i].flip = 0;
    }
}
inline void pull(int i){
    push(i<<1);
    push((i<<1)|1);
    nodes[i].val.F = max(nodes[i<<1].val.F,nodes[(i<<1)|1].val.F);
    nodes[i].val.S = max(nodes[i<<1].val.S,nodes[(i<<1)|1].val.S);
}

void build(int i,int l,int r,vector<int> &a){
    if(l==r){
        nodes[i] = node(a[l],l);
    }
    else{
        int mid = (l+r)>>1;
        build(i<<1,l,mid,a);
        build((i<<1)|1,mid+1,r,a);
        nodes[i].flip = 0;
        pull(i);
    }
}
void update(int i,int l,int r,int L,int R){
    if((l==L)&&(r==R)){
        nodes[i].flip^=1;
    }
    else{
        push(i);
        int mid = (l+r)>>1;
        if(L<=mid)
            update(i<<1,l,mid,L,min(mid,R));
        if(R>mid)
            update((i<<1)|1,mid+1,r,max(mid+1,L),R);
        pull(i);
    }
}
void solve()
{
    int n;
    cin>>n;
    vector<int> a(n+1);
    nodes.resize((n<<2)+5);
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    build(1,1,n,a);
    int q;
    cin>>q;
    ll sum = 0;
    while(q--){
        int l,r;
        cin>>l>>r;
        update(1,1,n,l,r);
        push(1);
        sum-=nodes[1].val.F.S;
    }
    cout<<sum<<"\n";
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
