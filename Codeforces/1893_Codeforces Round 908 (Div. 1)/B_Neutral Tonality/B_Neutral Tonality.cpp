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
    int n,m;
    cin>>n>>m;
    vi a(n),b(m);
    cin>>a>>b;
    vector<int> d(n+1,1e9+1);
    stack<pair<int,int>> st;
    stack<int> len;
    len.push(0);
    d[0] = 0;
    vector<int> ans(n+m);
    int ind = n+m,f=0;
    for(int i=0;i<n;++i){
        int s = lower_bound(d.begin(),d.end(),a[i])-d.begin();
        if(d[s]>1e9){
            len.push(s);
        }
        else
            len.push(len.top());
        st.push(mp(s,d[s]));
        d[s] = a[i];
    }
    int k = len.top();
    sort(b.begin(),b.end());
    reverse(b.begin(),b.end());
    for(int i=n-1;i>=0;--i){
        while((!b.empty())&&(
            (d[len.top()]>=b.back())||(len.top()<k)
        )){
            ans[--ind] = b.back();
            b.pop_back();
        }
        ans[--ind] = a[i];
        len.pop();
        //cout<<st.size()<<endl;
        d[st.top().F] = st.top().S;
        st.pop();
    }
    while(!b.empty()){
        ans[--ind] = b.back();
        b.pop_back();
    }
    cout<<ans<<"\n";
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
