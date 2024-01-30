#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define MOD 1000000007
using namespace std;
void solve(){
    int n,a,b;
    cin>>n>>a>>b;

    int dpa[n+1]={},dpb[n+1]={};

    dpa[0]=1;
    dpb[0]=1;

    for(int i=1;i<=n;i++)
    {
        for(int j=i-1;j>=max(0,i-a);j--)
            dpa[i]=(dpa[i]+dpb[j])%MOD;

        for(int j=i-1;j>=max(0,i-b);j--)
            dpb[i]=(dpb[i]+dpa[j])%MOD;
    }

    cout<<(dpa[n]+dpb[n])%MOD;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}