#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
void dfs(int u,vector<int> *g,vector<int> &visit,vector<int> &a,vector<int> &b){
    a.push_back(u);
    visit[u] = 1;
    for(auto v:g[u]){
        if(!visit[v]){
            dfs(v,g,visit,b,a);
        }
    }
}
void solve(){
    int n;
    cin>>n;
    vector<set<int>> g(n);
    vector<string> s(n);
    for(int i=0;i<n;++i){
        cin>>s[i];
        g[i].insert(i);
        int k;
        cin>>k;
        while(k--){
            int u;
            cin>>u;
            g[i].insert(u-1);
        }
    }
    vector<int> h[n];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            if(s[i]!=s[j]){
                bool should = false;
                for(auto x:g[i]){
                    if(g[j].find(x)!=g[j].end())
                        should = true;
                }
                if(should)
                    h[i].push_back(j);
            }
        }
    }
    vector<int> visit(n);
    vector<int> ans;
    for(int i=0;i<n;++i){
        if(!visit[i]){
            vector<int> u,v;
            dfs(i,h,visit,u,v);
            if(u.size()>v.size())
                swap(u,v);
            ans.insert(ans.end(),u.begin(),u.end());
        }
    }
    if(ans.empty())
        ans.push_back(0);
    cout<<ans.size()<<"\n";
    for(auto x:ans)
        cout<<(x+1)<<" ";
        cout<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}