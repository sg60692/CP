#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n),c(n);
    for(auto &x:a)cin>>x;
    for(auto &x:b)cin>>x;
    map<int,vector<int>> A,B;
    for(int i=0;i<n;++i)A[a[i]].pb(i);
    for(int i=0;i<n;++i)B[b[i]].pb(i);
    unordered_set<int> available
    for(auto x:B){

    }
    for(auto x:B)qB.push({x.second.size(),x.first});
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}