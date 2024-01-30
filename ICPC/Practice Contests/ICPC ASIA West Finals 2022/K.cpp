#include<bits/stdc++.h>
#define ll long long
using namespace std;
int get(int k,int d){
    int i = 1;
    while((k*i)%d)++i;
    return k*i;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int u = get(1,m);
    int v = get(1<<6,m);
    int w = get(1<<12,m);
    for(int i=0;i<n;++i)
        cout<<u<<" "<<v<<" "<<w<<" "<<(u+v)<<" "<<(v+w)<<" "<<(u+w)<<"\n";
}