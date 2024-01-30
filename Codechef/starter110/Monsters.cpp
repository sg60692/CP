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
int N = 1e6+1;
vector<int> spf(N);
void pre(){
    vector<int> primes;
    for(int i=2;i<N;++i){
        if(!spf[i]){
            primes.pb(i);
            spf[i] = i;
        }
        for(auto p:primes){
            if((p*1ll*i)>=N)break;
            spf[p*i] = p;
            if(p==spf[i])
                break;
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    int ans = 1e9;
    if(spf[n]==n){
        cout<<"1\n";
        return;
    }
    for(int i=2,j=1;(i-1)<=n;++j,i<<=1){
        if((i-1)==n){
            ans = min(ans,j);
        }
        else if(spf[n-i+1]==(n-i+1)){
            ans = min(ans,j+1);
        }
    }
    if(ans==1e9)cout<<"-1\n";
    else cout<<ans<<"\n";
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