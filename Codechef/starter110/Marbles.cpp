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
void solve()
{
    int a,b;
    cin>>a>>b;
    int n = (a+b);
    int ans = n;
    for(int i=1;(i*i)<=n;++i){
        if(!(n%i)){
            int y = n/i;
            if(y>1){
                ans = min(ans,abs(b-i));
            }
            if(i>1){
                ans = min(ans,abs(b-y));
            }
        }
    }
    cout<<ans<<"\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
	return 0;
}