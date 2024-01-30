#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(long long cap,vector<pair<int,int>> a){
    multiset<pair<int,int>> diff,all;
    for(auto x:a){
        diff.insert(make_pair(x.first-x.second,x.second));
        all.insert(x);
    }
    while(!all.empty()){
        while((!all.empty())&&(cap-(diff.begin()->first))>=(all.rbegin()->first)){
            cap-=diff.begin()->first;
            all.erase(
                all.find(
                    make_pair(
                        diff.begin()->first+diff.begin()->second,diff.begin()->second
                    )
                ));
            diff.erase(diff.begin());
        }
        if(all.empty())return true;
        if(cap<(all.rbegin()->first))
            return false;
        cap-=(all.rbegin()->first-all.rbegin()->second);
        diff.erase(
            diff.find(
                make_pair(
                    all.rbegin()->first-all.rbegin()->second,
                    all.rbegin()->second
                )
            ));
        all.erase(all.find(*all.rbegin()));
    }
    return true;
}
bool check1(long long cap,vector<pair<int,int>> a){
    for(auto x:a){
        if(cap<x.second)return false;
        cap+=(x.first-x.second);
    }
    return cap>=0;
}
long long fsolve(vector<pair<int,int>> a){
    sort(a.begin(),a.end());
    auto b =a;
    auto c = a;
    for(auto &x:c)swap(x.first,x.second);
    reverse(b.begin(),b.end());
    long long l=0,r=1e15,f=15;
    while(l<=r){
        long long mid = (l+r)>>1;
        if(check1(mid,a)||(check1(mid,b)))
            f = mid, r = mid-1;
        else
            l = mid+1;
    }
    return f;
}
void solve(){
    int n;
    cin>>n;

    vector<pair<int,int>> v1,v2;
    for(int i=0;i<n;i++)
    {
        int x1,y1;
        cin>>x1>>y1;

        if(x1<y1)
            v1.push_back({x1,y1});
        else
            v2.push_back({y1,x1});
    }

    sort(v1.begin(),v1.end());
    ll ans=0,cur=0;

    for(auto v:v1)
    {
        if(v.first>cur)
        {
            ans+=v.first-cur;
            cur=v.second;
        }
        else
        {
            cur+=(v.second-v.first);
        }
    }

    cout<<(ans+max(fsolve(v2)-cur,0ll))<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();

    return 0;
}