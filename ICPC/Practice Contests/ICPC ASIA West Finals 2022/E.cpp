#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int u = 1;
    while((u<n)&&(s[u]==s[u-1]))++u;
    if(u==n){
        cout<<"-1\n";
        return;
    }
    int v = u+2;
    while((v<n)&&((s[v]!=s[u-1])||(s[v-1]!=s[u])))++v;
    if(v<n){
        if(s[u]=='0')cout<<(u+1)<<" "<<v<<" "<<u<<" "<<(v+1)<<"\n";
        else cout<<(v+1)<<" "<<u<<" "<<v<<" "<<(u+1)<<"\n";
    }
    else{
        ++u;
        while((u<n)&&(s[u]==s[u-1]))++u;
        if(u>=n){
            cout<<"-1\n";
            return;
        }
        int v = u+2;
        while((v<n)&&((s[v]!=s[u-1])||(s[v-1]!=s[u])))++v;
        if(v<n){
            if(s[u]=='0')cout<<(u+1)<<" "<<v<<" "<<u<<" "<<(v+1)<<"\n";
            else cout<<(v+1)<<" "<<u<<" "<<v<<" "<<(u+1)<<"\n";
        }
        else cout<<"-1\n";
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}