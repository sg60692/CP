#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
void update(int i,int l,int r,int L,int R,int val,vector<long long> &seg,vector<long long> &lazy){
    if((L<=l)&&(R>=r)){
        seg[i]+=val;
        lazy[i]+=val;
    }
    else{
        int mid = (l+r)>>1;
        int z = (mid+1-l)<<1;
        if(lazy[i]){
            seg[i+1]+=lazy[i];
            seg[i+z]+=lazy[i];
            lazy[i+1]+=lazy[i];
            lazy[i+z]+=lazy[i];
            lazy[i] = 0;
        }
        if(L<=mid)
            update(i+1,l,mid,L,R,val,seg,lazy);
        if(R>mid)
            update(i+z,mid+1,r,L,R,val,seg,lazy);
        seg[i] = min(seg[i+1],seg[i+z]);
    }
}
void solve(){
    int n;
    cin>>n;
    long long curDep = 0;
    set<string> S;
    map<string,int> m;
    vector<pair<string,int>> arr(n);
    for(int i=0;i<n;++i){
        char ch;
        int d;
        string a,b;
        cin>>ch>>d>>a>>b;
        swap(a[0],a[3]);
        swap(a[1],a[4]);
        a+=b;
        S.insert(a);
        if(ch=='-')
            d = -d;
        arr[i] = make_pair(a,d);
    }
    int cnt = -1;
    for(auto x:S){
        m[x] = ++cnt;
    }
    vector<long long> seg((cnt+1)<<1),lazy((cnt+1)<<1);
    for(int i=0;i<n;++i){
        int idx = m[arr[i].F];
        update(0,0,cnt,idx,cnt,arr[i].S,seg,lazy);
        cout<<min(seg[0],0ll)<<"\n";
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