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
    vector<pair<int,int>> a(n+1);
    map<int,int> cnt;
    for(int i=1;i<=n;++i){
        cin>>a[i].F;
        ++cnt[a[i].F];
        a[i].S=i;
    }
    queue<int> q;
    vector<int> arr(n+1);
    for(int i=1;i<=n;++i){
        if(!cnt[i]){
            q.push(i);
        }
    }
    while(!q.empty()){
        auto t = q.front();
        q.pop();
        arr[t] = 1;
        int ind = a[t].F;
        if(arr[ind]==1){
            cout<<"-1\n";
            return;
        }
        if(arr[ind]==0){
            arr[ind] = 2;
            int next = a[ind].F;
            --cnt[next];
            if((next<=n)&&(next>=1)&&(!cnt[next]))
                q.push(next);
        }
    }
    vector<int> visit(n+1);
    for(int i=1;i<=n;++i){
        if(visit[i]||arr[i])
            continue;
        int x = a[i].F;
        vector<int> cyc(1,i);
        while(x!=i){
            cyc.push_back(x);
            x = a[x].F;
        }
        if(cyc.size()&1){
            cout<<"-1\n";
            return;
        }
        for(int j=0;j<cyc.size();j+=2){
            visit[cyc[j]] = visit[cyc[j+1]] = 1;
            arr[cyc[j]] = 1;
            arr[cyc[j+1]] = 2; 
        }
    }
    vector<int> ans;
    for(int i=1;i<=n;++i){
        if(arr[i]==1){
            ans.push_back(a[i].F);
        }
    }
    cout<<ans.size()<<"\n";
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
