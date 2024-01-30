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
#define int          long long
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
void dfs(int u,int p,vector<int> *g,vector<int> &h,vector<int> &par,vector<int> &rep,vector<int> &sz,vector<pair<pair<int,int>,int>> *S){
    int s = -1;
    rep[u] = u;
    sz[u] = 1;
    for(auto v:g[u]){
        if(v!=p){
            h[v] = h[u]+1;
            par[v] = u;
            dfs(v,u,g,h,par,rep,sz,S);
            sz[u]+=sz[v];
            if((s==-1)||(sz[s]<sz[v]))
                s=v;
        }
    }
    if(s!=-1){
        auto t = S[s][0];
        rep[s] = u;
        S[u].pb(make_pair(make_pair(h[u],t.F.S),0)); 
    }
    else{
        S[u].pb(make_pair(make_pair(h[u],h[u]),0)); 
    }
}
int get(int u,vector<int> &rep){
    return u==rep[u]?u:(rep[u]=get(rep[u],rep));
}
inline int add(int x,int k){
    return x+k;
}
inline int Xor(int x,int k){
    return x^k;
}
inline int sub(int x,int k){
    return x>=k?(x-k):x;
}
inline long long rangeAdd(long long x,long long y,int l,int r,int k){
    assert(k==-1);
    return x+(y*(r-l+1));
}
inline long long rangeXor(long long x,long long y,int l,int r,int k){
    assert(k==-1);
    return x^(((r-l)&1)?0:y);
}
inline long long rangeMax(long long x,long long y,int l,int r,int k){
    assert(k==-1);
    return max(x,y);
}
inline long long rangeMin(long long x,long long y,int l,int r,int k){
    assert(k==-1);
    return min(x,y);
}
inline long long rangeAbsSub(long long x,long long y,int l,int r,int k){
    return min(x,abs(y-k));
}
inline long long pairAdd(long long x,long long y){
    return x+y;
}
inline long long pairXor(long long x,long long y){
    return x^y;
}
inline long long pairMax(long long x,long long y){
    return max(x,y);
}
inline long long pairMin(long long x,long long y){
    return min(x,y);
}
void transform(vector<pair<pair<int,int>,int>> &S,int L,int R,int k,function<int(int,int)> f){
    vector<pair<pair<int,int>,int>> vec;
    for(auto x:S){
        if((x.F.S<L)||(x.F.F>R))
            vec.pb(x);
        else if(x.F.F>=L){
            if(x.F.S<=R)
                vec.push_back(make_pair(x.F,f(x.S,k)));
            else{
                vec.push_back(make_pair(make_pair(x.F.F,R),f(x.S,k)));
                vec.push_back(make_pair(make_pair(R+1,x.F.S),x.S));
            }
        }
        else if(x.F.S<=R){
            vec.push_back(make_pair(make_pair(x.F.F,L-1),x.S));
            vec.push_back(make_pair(make_pair(L,x.F.S),f(x.S,k)));
        }
        else{
            vec.pb(make_pair(make_pair(x.F.F,L-1),x.S));
            vec.pb(make_pair(make_pair(L,R),f(x.S,k)));
            vec.pb(make_pair(make_pair(R+1,x.F.S),x.S));
        }
    }
    int checkRange = 0;
    for(auto v:vec)
        checkRange+=(v.F.S-v.F.F+1);
    for(auto v:S)
        checkRange-=(v.F.S-v.F.F+1);
    for(int i=1;i<vec.size();++i)
        assert((vec[i-1].F.S+1)==vec[i].F.F);
    assert(checkRange==0);
    assert(S[0].F.F==vec[0].F.F);
    assert(vec.back().F.S==S.back().F.S);
    S = vec;
}
long long getFrom(vector<pair<pair<int,int>,int>> &S,int L,int R,int k,int defaultValue,function<long long(long long,long long,int,int,int)> f){
    long long ans = defaultValue;
    for(auto x:S){
        if((x.F.S>=L)&&(x.F.F<=R))
            ans = f(ans,x.S,max(x.F.F,L),min(x.F.S,R),k);
    }
    return ans;
}

void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> g[n],h(n),p(n),rep(n),sz(n);
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        --u;--v;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<pair<pair<int,int>,int>> S[n];
    dfs(0,0,g,h,p,rep,sz,S);
    auto pathUpdate = [&](int u,int v,int k,function<int(int,int)> f){
        while(get(u,rep)!=get(v,rep)){
            if(h[u]<h[v])
                swap(u,v);
            int t = get(u,rep);
            transform(S[t],h[t],h[u],k,f);
            u = p[t];
        }
        if(h[u]<h[v])
            swap(u,v);
        int t = get(u,rep);
        assert(get(u,rep)==get(v,rep));
        transform(S[t],h[v],h[u],k,f);
    };
    auto pathGet = [&](int u,int v,int k,int defaultValue,function<long long(long long,long long,int,int,int)> f,function<long long(long long,long long)> g){
        long long ans = defaultValue;
        while(get(u,rep)!=get(v,rep)){
            if(h[u]<h[v])
                swap(u,v);
            int t = get(u,rep);
            ans = g(ans,getFrom(S[t],h[t],h[u],k,defaultValue,f));
            u = p[t];
        }
        if(h[u]<h[v])
            swap(u,v);
        int t = get(u,rep);
        assert(get(u,rep)==get(v,rep));
        return g(ans,getFrom(S[t],h[v],h[u],k,defaultValue,f));
    };
    for(int i=0;i<m;++i){
        int o,u,v,k;
        cin>>o>>u>>v;
        --u;--v;
        cout<<o<<" "<<u<<" "<<v<<endl;
        if(o==1){
            cin>>k;
            pathUpdate(u,v,k,add);
        }
        if(o==2){
            cin>>k;
            pathUpdate(u,v,k,Xor);
        }
        if(o==3){
            cin>>k;
            pathUpdate(u,v,k,sub);
        }
        if(o==4){
            cout<<pathGet(u,v,-1,0,rangeAdd,pairAdd)<<"\n";
        }
        if(o==5){
            cout<<pathGet(u,v,-1,0,rangeXor,pairXor)<<"\n";
        }
        if(o==6){
            cout<<(pathGet(u,v,-1,INT_MIN,rangeMax,pairMax)-pathGet(u,v,-1,INT_MAX,rangeMin,pairMin))<<"\n";
        }
        if(o==7){
            cin>>k;
            cout<<pathGet(u,v,k,INT_MAX,rangeAbsSub,pairMin)<<"\n";
        }
    }
}
int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}
