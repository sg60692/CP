#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;

    vector<pair<ll,ll>> a(n),b(n);
    ll s1=0,s2=0;

    for(ll i=0;i<n;i++)
    {
        cin>>a[i].first;
        a[i].second=i+1;
        s1+=a[i].first;
    }
    
    for(ll i=0;i<n;i++)
    {
        cin>>b[i].first;
        b[i].second=i+1;
        s2+=b[i].first;
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    if(s1<s2)
        reverse(a.begin(),a.end());
    else
        reverse(b.begin(),b.end());

    for(ll i=0;i<n;i++)
        cout<<a[i].second<<" "<<b[i].second<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}