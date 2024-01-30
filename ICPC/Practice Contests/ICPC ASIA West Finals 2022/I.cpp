#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    ll ans = -m;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        ans+=x;
    }
    cout<<ans;
}