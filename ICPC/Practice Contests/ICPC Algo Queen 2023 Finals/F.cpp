#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    vector<ll> pre(n);
    vector<int> till(n);
    for(int i=0;i<n;++i){
        till[i] = i?(till[i-1]+(pre[i-1]==0)):0;
        pre[i] = a[i]+(i?pre[i-1]:0);
    }
    unordered_map<ll,int> cnt;
    int ans = 0, cur_max = 0;
    for(int i=n-1;i>=0;--i){
        cur_max = max(cur_max, ++cnt[pre[i]]);
        ans = max(ans,till[i]+cur_max);
    }
    cout<<ans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}