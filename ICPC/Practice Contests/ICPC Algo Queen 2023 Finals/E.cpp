#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    int ans = 0;
    while(n--){
        int x;
        cin>>x;
        if(x>q)++ans;
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