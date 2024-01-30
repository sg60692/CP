#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
void solve(){
    ll a,x,y;
    cin>>a>>x>>y;

    ll n;
    cin>>n;

    ll adv=-1,ans=-1,cur=-1;

    ll fr[n][2];
    for(ll i=0;i<n;i++)
    {
        cin>>fr[i][0]>>fr[i][1];
    }

    ll m;
    cin>>m;

    ll ap[3];

    for(ll i=0;i<m;i++)
    {
        cin>>ap[0]>>ap[1]>>ap[2];

        ll temp=x;
        if(ap[0]==2)
            temp=y;

        if(a>=ap[1] && temp+ap[2]>adv)
        {
            adv=temp+ap[2];
            ans=i+1;
            cur=-1;
        }

        //

        if(ap[0]==2 && 2*a>=ap[1])
        {
            for(ll j=0;j<n;j++)
            {
                if(2*fr[j][0]>=ap[1] && fr[j][1]+ap[2]>adv)
                {
                    adv=fr[j][1]+ap[2];
                    ans=i+1;
                    cur=j+1;
                }
            }
        }
    }

    //

    if(ans==-1)
        cout<<"Forget about apartments. Live in the dormitory.";
    else if(cur==-1)
        cout<<"You should rent the apartment #"<<ans<<" alone.";
    else
        cout<<"You should rent the apartment #"<<ans<<" with the friend #"<<cur<<".";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}