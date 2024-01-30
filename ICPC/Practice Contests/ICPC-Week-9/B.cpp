#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define pb push_back
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> g[n],h[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
        int k;
        cin>>k;
        while(k--){
            int u;
            cin>>u;
            --u;
            if((i!=u)||a[u]){
                g[i].pb(u);
                h[u].pb(i);
            }
        }
    }
    vector<int> visit(n),ex(n),en(n),d(n);
    for(int i=0;i<n;++i)
        d[i] = h[i].size();
    priority_queue<pair<int,int>> q;
    for(int i=0;i<n;++i){
        if(!a[i])
            q.push(make_pair(-d[i],i));
        else
            ex[i] = a[i];
    }
    auto push = [&](int u){
        if(visit[u])return;
        visit[u] = 1;
        for(auto v:g[u]){
            if(!a[v]){
                --d[v];
                q.push(make_pair(d[v],v));
                if(ex[u]!=-1){
                    if(ex[v]){
                        if(ex[u]!=ex[v])
                            ex[v] = -1;
                    }
                    else ex[v] = ex[u];
                }
            }
        }
    };
    for(int i=0;i<n;++i){
        if(a[i])
            push(i);
    }
    while(!q.empty()){
        auto t = q.top();
        q.pop();
        push(t.S);
    }
    for(int i=0;i<n;++i){
        int u = -1;
        for(auto v:h[i]){
            if(ex[v]==-1)
                continue;
            if(u==-1)
                u = ex[v];
            else if(u!=ex[v])
                u = -2;
        }
        if(u==-2)
            en[i] = -1;
        else if(u==-1)
            en[i] = 0;
        else
            en[i] = u;
    }
    auto print = [](int x){
        if(x==-1)cout<<"unknown ";
        else if(x==0) cout<<"sober ";
        else cout<<x<<" ";
    };
    for(int i=0;i<n;++i){
        print(en[i]);
        print(ex[i]);
        cout<<"\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}