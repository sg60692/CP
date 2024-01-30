#include<bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin>>n;
    vector<vector<vector<int>>> check(
        n,vector<vector<int>> (n,vector<int>(n))
        );
    auto what = check;
    vector<vector<int>> a(n,vector<int> (n));
    for(auto &x:a)
        for(auto &y:x)
            cin>>y;
    for(int k=13;k>=0;--k){
        vector<vector<vector<pair<bool,bool>>>> visit(k<<1);
        queue<pair<int,pair<int,int>>> q;
        q.push(make_pair(0,make_pair(0,0)));
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            int i = t.first;
            int l = t.second.first;
            int r = t.second.second;
            if(l==r){
                
            }
        }
    }
}