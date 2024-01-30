#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    int ans=0,cur=0;

    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;

        int temp=2;

        if(s[0]=='A' || s[0]=='O' || s[0]=='P' || s[0]=='R')
            temp=0;
        else if(s[0]=='B' || s[0]=='M' || s[0]=='S')
            temp=1;

        ans+=abs(temp-cur);
        cur=temp;
    }

    cout<<ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}