#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
void solve(){
    string a,b;
    cin>>a>>b;

    ll x=0,y=0,n=a.size(),m=b.size();

    ll ans=0;

    while(x!=n || y!=m)
    {
        if(x==n)
        {
            ans+=m-y;
            y=m;
        }
        else if(y==m)
        {
            ans+=n-x;
            x=n;
        }
        else
        {
            if(a[x]=='L' && b[y]!='L')
            {
                y++;
                ans++;
            }
            else if(a[x]!='L' && b[y]=='L')
            {
                x++;
                ans++;
            }
            else
            {
                x++;
                y++;
                ans++;
            }
        }

        //cout<<x<<' '<<y<<" "<<ans<<"\n";
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