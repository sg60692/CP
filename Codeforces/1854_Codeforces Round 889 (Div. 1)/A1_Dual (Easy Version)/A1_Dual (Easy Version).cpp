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
    vector<int> a(n);
    cin>>a;
    pii min_neg={INT_MAX,-1},max_pos={INT_MIN,-1};
    for(int i=0;i<n;++i){
        max_pos=max(max_pos,mp(a[i],i));
        min_neg=min(min_neg,mp(a[i],i));
    }
    int count_pos = 0 ,count_neg = 0;
    for(int i=0;i<n;++i){
        if(a[i]>0)++count_pos;
        if(a[i]<0)++count_neg;
    }
    vector<pii> ans;
    auto left_to_right = [&](){
        for(int i=1;i<n;++i)ans.pb({i+1,i});
    };
    auto right_to_left = [&](){
        for(int i=n-1;i>=1;--i)ans.pb({i,i+1});
    };
    auto turn_pos_to_neg = [&](){
        for(int i=0;i<n;++i)if(a[i]>0)
            ans.pb({i+1,min_neg.S+1});
    };
    auto turn_neg_to_pos = [&](){
        for(int i=0;i<n;++i)if(a[i]<0)
            ans.pb({i+1,max_pos.S+1});
    };
    auto get_min_moves = [&](int x){
        int t = 0;
        while(abs(x)<20){
            ++t;
            x*=2;
        }
        return t;
    };
    auto solve_neg = [&](){
        if((count_pos+n-1)<32){
            turn_pos_to_neg();
            right_to_left();
        }
        else if((get_min_moves(max_pos.F)+count_neg+n-1)<32){
            for(int i=0;i<get_min_moves(max_pos.F);++i)
                ans.pb({max_pos.S+1,max_pos.S+1});
            turn_neg_to_pos();
            left_to_right();
        }
        else{
            for(int i=1;i<(n-1);++i){
                if(a[i-1]>0){
                    ans.pb({i,min_neg.S+1});
                }
            }
            for(int i=n-2;i>=1;--i)ans.pb({i,i+1});
        }
    };
    auto solve_pos = [&](){
        if((count_neg+n-1)<32){
            turn_neg_to_pos();
            left_to_right();
        }
        else if((get_min_moves(min_neg.F)+count_pos+n-1)<32){
            for(int i=0;i<get_min_moves(min_neg.F);++i)
                ans.pb({min_neg.S+1,min_neg.S+1});
            turn_pos_to_neg();
            right_to_left();
        }
        else{
            for(int i=1;i<(n-1);++i){
                if(a[i-1]<0){
                    ans.pb({i,max_pos.S+1});
                }
            }
            for(int i=2;i<n;++i)ans.pb({i,i+1});
        }
    };
    if(count_pos==0){
        right_to_left();
    }
    else if(count_neg==0){
        left_to_right();
    }
    else{
        if(abs(min_neg.F)>max_pos.F){
            solve_neg();
        }
        else if(abs(min_neg.F)<max_pos.F){
            solve_pos();
        }
        else if(count_neg>=count_pos){
            solve_neg();
        }
        else{
            solve_pos();
        }
    }
    cout<<ans.size()<<"\n";
    for(auto x:ans)cout<<x<<"\n";
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
