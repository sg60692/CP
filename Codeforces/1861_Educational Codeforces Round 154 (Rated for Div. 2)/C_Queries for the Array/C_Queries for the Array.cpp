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
    string s;
    cin>>s;
    vector<int> cur;
    for(int i=0;i<s.length();++i){
        if(s[i]=='+'){
            if(cur.empty())
                cur.push_back(1);
            else
                cur.push_back(2);
        }
        else if(s[i]=='-'){
            int val = cur.back();
            cur.pop_back();
            if(val==1){
                if(!cur.empty()){
                    if(cur.back()==2){
                        cur.back() = 1;
                    }
                    if(cur.back()==0){
                        cout<<"NO\n";
                        return;
                    }
                }
            }
        }
        else{
            int val = s[i]-'0';
            if(cur.empty()){
                if(!val){
                    cout<<"NO\n";
                    return;
                }
            }
            else{
                if(cur.back()==2)
                    cur.back()=val;
                if(cur.back()!=val){
                    cout<<"NO\n";
                    return;
                }
            }   
        }
    }
    while(!cur.empty()){
        int val = cur.back();
        cur.pop_back();
        if(val==1){
            if(!cur.empty()){
                if(cur.back()==2){
                    cur.back() = 1;
                }
                if(cur.back()==0){
                    cout<<"NO\n";
                    return;
                }
            }
        }
    }
    cout<<"YES\n";
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
