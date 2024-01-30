#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
vector<int> djktras(int s,vector<vector<pair<int,int>>> g){
    int n = g.size();
    vector<int> dist(n,-1);
    priority_queue<
        pair<int,int>,
        vector<pair<int,int>>,
        greater<pair<int,int>>
    > q;
    q.push(make_pair(0,s));
    while(!q.empty()){
        auto [d,u] = q.top();
        q.pop();
        if(dist[u]!=-1)
            continue;
        dist[u] = d;
        for(auto e:g[u]){
            q.push(make_pair(d+e.second,e.first));
        }
    }
    return dist;
}
void solve(){
    int n,b,s,r;
    cin>>n>>b>>s>>r;
    vector<vector<pair<int,int>>> g(n+1),h(n+1);
    while(r--){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w));
        h[v].push_back(make_pair(u,w));
    }
    vector<int> d1 = djktras(b+1,g);
    vector<int> d2 = djktras(b+1,h);
    vector<int> cost;
    for(int i=1;i<=b;++i)
        cost.push_back(d1[i]+d2[i]);
    sort(cost.begin(),cost.end());
    vector<long long> pre(b+1);
    for(int i=1;i<=b;++i)
        pre[i] = pre[i-1]+cost[i-1];
    vector<vector<long long>> dp(b+1,vector<long long>(b+1));
    auto cur = dp;
    for(int i=1;i<=b;++i){
        for(int j=1+(i==1);j<=i;++j)
            cur[1][j] = 1ll<<60;
        for(int j=1;j<i;++j){
            for(int u=1;(u*j)<i;++u){
                cur[1][u+1] = min(cur[1][u+1],dp[j][u]);
            }
        }
        for(int j=2;j<=i;++j){
            for(int k=1;(k*j)<=i;++k){
                cur[j][k] = cost[i-1]*1ll*(j-2)+pre[i]-pre[i-j]+dp[j-1][k];
            }
        }
        swap(dp,cur);
    }
    long long fans = 1ll<<60;
    for(int j=1;j<=b;++j){
        if((j*s)<=b)
            fans = min(fans,dp[j][s]);
    }
    cout<<fans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}