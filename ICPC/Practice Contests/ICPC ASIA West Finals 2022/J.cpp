#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    int x = 0;
    for(int i=0;i<n;++i){
        int y;
        cin>>y;
        if(y>1)++x;
    }
    if(x==0){
        if((n%3)==1)cout<<"Sprague\n";
        else cout<<"Grundy\n";
    }
    else if(x==1){
        if(((n-1)%3)==1)cout<<"Grundy\n";
        else cout<<"Sprague\n";
    }
    else cout<<"Grundy\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
}