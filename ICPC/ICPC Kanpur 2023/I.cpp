#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
#include<bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
bool isSorted(vector<int> a){
    int ans = 1;
    ordered_multiset m;
    for(int i=a.size()-1;i>=0;--i){
        ans^=(m.order_of_key(a[i])&1);
        m.insert(a[i]);
    }
    return ans;
}
long long fsolve(vector<int> a){
    long long ans = 0;
    priority_queue<int> q;
    for(int i=0;i<a.size();++i){
        q.push(a[i]);
        q.push(a[i]);
        ans+=(q.top()-a[i]);
        q.pop();
    }
    return ans;
}
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(auto &x:a)
        cin>>x;
    if(k==1){
        cout<<fsolve(a)<<"\n";
    }
    else if(k==n){
        long long ans = fsolve(a);
        for(int i=1;i<n;++i){
            a.push_back(a[0]);
            reverse(a.begin(),a.end());
            a.pop_back();
            reverse(a.begin(),a.end());
            ans = min(ans,fsolve(a));
        }
        cout<<ans<<"\n";
    }
    else if(k&1){
        if(isSorted(a)){
            cout<<"0\n";
        }
        else{
            sort(a.begin(),a.end());
            int ans = a[1]-a[0];
            for(int i=1;i<n;++i){
                ans = min(ans,a[i]-a[i-1]);
            }
            cout<<ans<<"\n";
        }
    }
    else cout<<"0\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}