#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int N = 2e5+5;
pair<int,int> combine(pair<int,int> a,pair<int,int> b){
    return make_pair(min(a.F,b.F),max(a.S,b.S));
}
void build(int i,int l,int r,vector<int> &a,vector<pair<int,int>> &seg){
    if(l==r){
        seg[i] = make_pair(a[l],a[r]);
    }
    else{
        int mid = (l+r)>>1;
        int z = (mid+1-l)<<1;
        build(i+1,l,mid,a,seg);
        build(i+z,mid+1,r,a,seg);
        seg[i] = combine(seg[i+1],seg[i+z]);
    }
}
pair<int,int> get(int i,int l,int r,int L,int R,vector<pair<int,int>> &seg){
    if((l==L)&&(r==R)){
        return seg[i];
    }
    else{
        int mid = (l+r)>>1;
        int z = (mid+1-l)<<1;
        if(R<=mid)
            return get(i+1,l,mid,L,R,seg);
        if(L>mid)
            return get(i+z,mid+1,r,L,R,seg);
        return combine(get(i+1,l,mid,L,mid,seg),get(i+z,mid+1,r,mid+1,R,seg));
    }
}
vector<int> solve1(vector<int> original){
    vector<int> a = original;
    a.insert(a.end(),original.begin(),original.end());
    vector<int> ans(N),prev(N,-1),first(N,-1);
    vector<pair<int,int>> seg(a.size()<<1);
    build(0,0,a.size()-1,a,seg);
    int n = original.size();
    int dummy = 0;
    for(int i=0;i<a.size();++i){
        ++dummy;
        if(first[a[i]]!=-1){
            if((i-first[a[i]])<=n){
                int l = prev[a[i]]+1;
                int r = i-1;
                if(l<=r){
                    pair<int,int> p = get(0,0,a.size()-1,l,r,seg);
                    if((p.F>a[i])||(p.S<a[i])){
                        ++ans[a[i]];
                    }
                }
                else
                    ++ans[a[i]];
            }
            prev[a[i]] = i;
        }
        else
            first[a[i]] = prev[a[i]] = i;
        ++dummy;
    }
    return ans;
}
vector<int> solve2(vector<int> original){
    vector<int> a = original;
    a.insert(a.end(),original.begin(),original.end());
    vector<int> ans(N),prev(N,-1),first(N,-1);
    int n = original.size();
    int dummy = 0;
    for(int i=0;i<a.size();++i){
        if(first[a[i]]!=-1){
            if((i-first[a[i]])<=n){
                int l = prev[a[i]]+1;
                int r = i-1;
                if(l<=r){
                    if((max(a[l],a[r])<a[i])||(min(a[l],a[r])>a[i])){
                        ++ans[a[i]];
                    }
                }
            }
            prev[a[i]] = i;
        }
        else
            first[a[i]] = prev[a[i]] = i;
    }
    return ans;
}
vector<int> solve3(vector<int> original){
    vector<int> a = original;
    a.push_back(a[0]);
    vector<int> ans(N),prev(N,-1),first(N,-1);
    int n = original.size();
    int dummy = 0;
    for(int i=1;i<a.size();++i){
        int l = min(a[i],a[i-1])+1;
        int r = max(a[i],a[i-1])-1;
        if(l<=r){
            ++ans[l];
            --ans[r+1];
        }
    }
    for(int i=1;i<N;++i)
        ans[i]+=ans[i-1];
    return ans;
}
vector<int> solve4(vector<int> original){
    vector<int> ans(N);
    for(auto x:original)
        ++ans[x];
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(auto &x:a)cin>>x;
    vector<int> ans1 = solve1(a);
    vector<int> ans2 = solve2(a);
    vector<int> ans3 = solve3(a);
    vector<int> ans4 = solve4(a);
    vector<int> ans(m+1,-1);
    int dummy = 0;
    for(int i=0;i<=m;++i){
        if(ans4[i])
            ans[i] = n-ans4[i]-ans2[i]+ans1[i]+ans3[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==a[(i+1)%n])
            ans[a[i]]--;
    }
    for(int i=1;i<=m;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
}
