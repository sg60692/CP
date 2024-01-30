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
struct node{
    int n,sum;
    map<char,int> next;
    node():n(0),sum(0){}
};
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<node> nodes(1);
    vector<string> S(n);
    cin>>S;
    ll ans = 0;
    for(int i=0;i<n;++i){
        string s = S[i];
        int u = s.length();
        int cur = 0;
        for(int j=s.length()-1;j>=0;--j,--u){
            if(nodes[cur].next.find(s[j])==nodes[cur].next.end()){
                nodes[cur].next[s[j]] = nodes.size();
                nodes.push_back(node());
            }
            int next = nodes[cur].next[s[j]];
            nodes[cur].sum+=u;
            ++nodes[cur].n;
            cur = next;
        }
        ++nodes[cur].n;
        
    }
    for(int i=0;i<n;++i){
        string s = S[i];
        int u = s.length();
        int cur = 0;
        for(int j=0;s[j]!='\0';++j,--u){
            if(nodes[cur].next.find(s[j])==nodes[cur].next.end()){
                nodes[cur].next[s[j]] = nodes.size();
                nodes.push_back(node());
            }
            // cout<<cur<<"c\n";
            int next = nodes[cur].next[s[j]];
            // cout<<u<<" "<<(nodes[cur].n-nodes[next].n)<<"hi\n";
            // cout<<(nodes[cur].sum-nodes[next].sum-nodes[next].n)<<"\n";
            ans+=(u*1ll*(nodes[cur].n-nodes[next].n));
            ans+=(nodes[cur].sum-nodes[next].sum-nodes[next].n);
            cur = next;
        }
        ans+=(nodes[cur].sum);
    }
    cout<<ans<<"\n";
	return 0;
}
