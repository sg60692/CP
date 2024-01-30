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
const int N = 1e5+5;
const int mod = 1e9+7;
vector<int> odd(N),even(N);
void pre(){
    even[0] = 1;
    for(int i=1;i<N;++i){
        for(int j=2;(j<=4)&&(j<=i);++j){
            even[i]+=even[i-j];
            if(even[i]>=mod)
                even[i]-=mod;
            odd[i]+=odd[i-j];
            if(odd[i]>=mod)
                odd[i]-=mod;
        }
        even[i]+=odd[i-1];
        if(even[i]>=mod)
            even[i]-=mod;
        odd[i]+=even[i-1];
        if(odd[i]>=mod)
            odd[i]-=mod;
    }
}
void solve()
{
    int n;
    cin>>n;
    int ans = 0;
    for(int i=max(n-4,0);i<n;++i){
        ans+=even[i];
        if(ans>=mod)
            ans-=mod;
    }
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    pre();
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}