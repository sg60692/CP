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
void fsolve(int u,vector<int> &ans,deque<char> &s){
    if(s.empty())return;
    if(s[0]!=s.back()){
        s.pop_back();
        s.pop_front();
        fsolve(u+1,ans,s);
    }
    else{
        if(s[0]=='0'){
            ans.push_back(s.size()+u);
            s.push_back('0');
            s.pop_front();
            fsolve(u+1,ans,s);
        }
        else{
            ans.push_back(u);
            s.pop_back();
            s.push_front('1');
            fsolve(u+1,ans,s);
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int x = 0;
    for(int i=0;i<n;++i){
        if(s[i]=='0')++x;
        else --x;
    }
    if(x!=0)cout<<"-1\n";
    else{
        vector<int> ans;
        deque<char> S;
        for(int i=0;i<n;++i)
            S.push_back(s[i]);
        fsolve(0,and,S);
        cout<<ans.size()<<"\n";
        for(auto x:ans)
            cout<<x<<" ";
        cout<<"\n";
    }
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
