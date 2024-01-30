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
    int n,q;
    cin>>n>>q;
    vector<int> X(n+1),Y(n+1);
    map<pair<int,int>,int> minInd,maxInd;
    for(int i=1;i<=n;++i){
        char c;
        cin>>c;
        X[i] = X[i-1];
        Y[i] = Y[i-1];
        if(c=='U')++Y[i];
        else if(c=='D')--Y[i];
        else if(c=='L')--X[i];
        else ++X[i];
    }
    for(int i=0;i<=n;++i){
        maxInd[make_pair(X[i],Y[i])] = i;
    }
    for(int i=n;i>=0;--i){
        minInd[make_pair(X[i],Y[i])] = i;
    }
    vector<pair<int,int>> queries(q),coords(q),tcoords(q);
    vector<bool> ans(q);
    vector<vi> Q(n+1);
    for(int i=0;i<q;++i){
        cin>>coords[i]>>queries[i];
        if(minInd.find(coords[i])!=minInd.end()){
            if((minInd[coords[i]]<queries[i].F)||(maxInd[coords[i]]>queries[i].S))
                ans[i] = true;
        }
        ll nX = X[queries[i].S]+X[queries[i].F-1]-coords[i].F;
        ll nY = Y[queries[i].S]+Y[queries[i].F-1]-coords[i].S;
        tcoords[i] = mp(nX,nY);
        //cout<<tcoords[i]<<"\n";
        Q[queries[i].S].pb(i);
    }
    map<pair<int,int>,int> w;
    for(int i=0;i<=n;++i){
        for(int e:Q[i]){
            if(w.find(tcoords[e])!=w.end()){
                if(w[tcoords[e]]>=(queries[e].F-1))
                    ans[e] = true;
            }
        }
        w[mp(X[i],Y[i])] = i;
    }
    //cout<<"hi"<<q<<endl;
    for(int i=0;i<q;++i)
        cout<<(ans[i]?"YES":"NO")<<"\n";
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
