#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n,k;
    cin>>n>>k;
    set<vector<int>> s;
    while(n--){
        map<int,int> cur;
        for(int i=0;i<k;++i){
            int x;
            cin>>x;
            int u = 1;
            while(cur.find(u)!=cur.end()){
                if(cur[u]<x){
                    u = (u<<1)|1;
                }
                else 
                    u<<=1;
            }
            // cout<<u<<" p "<<x<<"\n";
            cur[u] = x;
        }
        vector<int> e;
        for(auto x:cur){
            e.push_back(x.first);
            // cout<<x.first<<" ";
        }
        // cout<<"\n";
        s.insert(e);
    }
    cout<<s.size()<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}