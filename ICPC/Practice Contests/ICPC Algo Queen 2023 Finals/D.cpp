#include<bits/stdc++.h>
#define pb push_back
#define ll long long
using namespace std;
void fix(int i,int l,int r,int ind,int val,vector<int> &segMin,vector<int> &lazy,vector<int> &count){
    if(lazy[i]!=0){
        if(l!=r){
            lazy[i<<1]+=lazy[i];
            lazy[(i<<1)|1]+=lazy[i];
        }
        segMin[i]+=lazy[i];
        lazy[i]=0;
    }
    ++count[i];
    if(l==r)segMin[i]=val-1;
    else{
        int mid = (l+r)>>1;
        if(ind>mid)fix((i<<1)|1,mid+1,r,ind,val-count[i<<1],segMin,lazy,count);
        else{
            --lazy[(i<<1)|1];
            fix(i<<1,l,mid,ind,val,segMin,lazy,count);
        }
        segMin[i] = min(segMin[i<<1]+lazy[i<<1],segMin[(i<<1)|1]+lazy[(i<<1)|1]);
    }
}
void del(int i,int l,int r,int ind,vector<int> &segMin,vector<int> &lazy,vector<int> &count){
    if(lazy[i]!=0){
        if(l!=r){
            lazy[i<<1]+=lazy[i];
            lazy[(i<<1)|1]+=lazy[i];
        }
        segMin[i]+=lazy[i];
        lazy[i]=0;
    }
    --count[i];
    if(l==r)segMin[i]=segMin.size();
    else{
        int mid = (l+r)>>1;
        if(ind>mid)del((i<<1)|1,mid+1,r,ind,segMin,lazy,count);
        else{
            ++lazy[(i<<1)|1];
            del(i<<1,l,mid,ind,segMin,lazy,count);
        }
        segMin[i] = min(segMin[i<<1]+lazy[i<<1],segMin[(i<<1)|1]+lazy[(i<<1)|1]);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> a(n),l(n);
    multiset<int> g;
    for(auto &x:a)cin>>x;
    vector<pair<int,int>> b;
    for(int i=0;i<n;++i)b.pb({a[i],i});
    vector<int> ind(n);
    sort(b.begin(),b.end());
    for(int i=0;i<n;++i)ind[b[i].second]=i;
    vector<int> segMin(n<<2,n<<1),count(n<<2),lazy(n<<2);
    for(int i=0,p=0,k=1;i<n;++i){
        fix(1,0,n-1,ind[i],a[i],segMin,lazy,count);
        while(segMin[1]+lazy[0]<0){
            del(1,0,n-1,ind[p++],segMin,lazy,count);
        }
        l[i] = p;
    }
    int q;
    cin>>q;
    while(q--){
        int L,R;
        cin>>L>>R;
        if((L-1)>=l[R-1])cout<<"YES\n";
        else cout<<"NO\n";
    }
}