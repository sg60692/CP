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

const int d = 26;
const int k = d*d;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int Q;
    cin>>Q;
    vector<pair<int,int>> queries(Q);
    cin>>queries;
    int n = s.length();
    int m = n-1;
    vector<int> ans(Q,n);
    vector<vector<int> > store(k, vector<int>());
    for(int i=1;i<n;++i){
        int cur = (s[i-1]-'a')*d+s[i]-'a';
        store[cur].pb(i-1);
    }
    for(int i=0;i<k;++i){
        queue<int> q;
        vector<int> res(m,n);
        vector<bool> store_visit(k);
        for(auto x:store[i]){
            q.push(x);
            res[x] = 1;
        }
        while(!q.empty()){
            int u = q.front();
            q.pop();
            {
                int v = u-1;
                if((v>=0)&&(v<m)&&(res[v]==n)){
                    res[v] = res[u]+1;
                    q.push(v);
                }
            }
            {
                int v = u+1;
                if((v>=0)&&(v<m)&&(res[v]==n)){
                    res[v] = res[u]+1;
                    q.push(v);
                }
            }
            int cur = (s[u]-'a')*d+s[u+1]-'a';
            if(!store_visit[cur]){
                store_visit[cur] = true;
                for(auto v:store[cur]){
                    if((v>=0)&&(v<m)&&(res[v]==n)){
                        res[v] = res[u]+1;
                        q.push(v);
                    }
                }
            }
        }
        for(int j=0;j<Q;++j)
            ans[j] = min(ans[j],res[queries[j].F-1]+res[queries[j].S-1]-1);
    }    
    for(int i=0;i<Q;++i){
        cout<<min(ans[i],abs(queries[i].F-queries[i].S))<<"\n";
    }
	return 0;
}
