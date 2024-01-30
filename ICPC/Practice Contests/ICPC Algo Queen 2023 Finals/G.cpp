#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;

void solve(){
    int n,q;
    cin>>n>>q;
    if(q&1){
        cout<<(n-(q>>1))<<"\n";
    }
    else{
        cout<<(q>>1)<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}