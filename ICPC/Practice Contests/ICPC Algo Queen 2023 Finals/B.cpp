#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
int get(int x,vector<int> &p,vector<int> &a){
    return a[x]?(p[x]=get(p[x],p,a)):x;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    vector<int> R(n+2),L(n+2),A(n+2);
    for(int i=0;i<=n;++i){
        R[i] = i+1;
        L[i+1] = i;
    }
    while(q--){
        int o,i;
        cin>>o>>i;
        if(o==1){
            A[i] = 1;
        }
        else{
            int r = get(i,R,A);
            int l = get(i,L,A);
            int ans = n;
            if((((r-i)<(i-l))&&(r<=n))||(l<1))cout<<r<<"\n";
            else cout<<l<<"\n";
        }
    }
}