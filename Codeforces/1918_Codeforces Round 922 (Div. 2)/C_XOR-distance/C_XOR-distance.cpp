#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define ll           long long int
#define pb           push_back
#define F            first
#define S            second
#define mk           make_pair
using namespace std;
template<typename T>istream & operator >> (istream &in, vector<T> &a){for(auto &x:a)in>>x;return in;}
template<typename T>ostream & operator << (ostream &out, vector<T> &a){for(auto &x:a)out<<x<<" ";return out;}
template<typename T,typename K>istream & operator >> (istream &in,  pair<T,K> &a){in>>a.F>>a.S;return in;}
template<typename T,typename K>ostream & operator << (ostream &out, pair<T,K> &a){out<<a.F<<" "<<a.S;return out;}

void solve(){
    ll a,b,r;
    cin>>a>>b>>r;
    if(a==b){
        cout<<0<<"\n";
    }
    else{
        if(a<b)swap(a,b);
        ll s = 1ll<<60;
        while((a&s)==(b&s))s>>=1;
        ll g = 0;
        for(ll e=s>>1;e;e>>=1){
            if((g+e)>r)continue;
            if(((e&a)==e)&&((e&b)==0)){
                g+=e;
            }
        }
        cout<<((a^g)-(b^g))<<"\n";
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
