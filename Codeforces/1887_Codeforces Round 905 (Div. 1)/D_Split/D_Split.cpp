#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
#define ll           long long
#define pb           push_back
#define F            first
#define S            second
#define mp           make_pair
#define pii          pair<int,int>
#define pll          pair<ll,ll>
#define vi           vector<int>
#define vll          vector<ll>
#define vN           vector<node>
#define vT           vector<T>
#define vpii         vector<pii>
#define vpll         vector<pll>
#define all(x)       x.begin(),x.end()
#define u32          uint32_t
#define u64          uint64_t
#ifndef ONLINE_JUDGE
    #define Log(x)  cerr<<"Debug: "<<x
#else
    #define Log(x)  0
#endif
using namespace std;
template<typename T>istream & operator >> (istream &in, vector<T> &a){for(auto &x:a)in>>x;return in;}
template<typename T>ostream & operator << (ostream &out, vector<T> &a){for(auto &x:a)out<<x<<" ";return out;}
template<typename T,typename K>istream & operator >> (istream &in,  pair<T,K> &a){in>>a.F>>a.S;return in;}
template<typename T,typename K>ostream & operator << (ostream &out, pair<T,K> &a){out<<a.F<<" "<<a.S;return out;}
vector<int> lg(2);
void update(int i,int l,int r,int L,int R,int val,vector<int> &seg){
    if((L<=l)&&(R>=r)){
        seg[i]+=val;
    }
    else{
        int mid = (l+r)>>1;
        int z = (mid+1-l)<<1;
        if(L<=mid)
            update(i+1,l,mid,L,R,val,seg);
        if(R>mid)
            update(i+z,mid+1,r,L,R,val,seg);
    }
}
int get(int i,int l,int r,int v,vector<int> &seg){
    if(l==r){
        return seg[i];
    }
    else{
        int mid = (l+r)>>1;
        int z = (mid+1-l)<<1;
        if(v<=mid)
            return seg[i]+get(i+1,l,mid,v,seg);
        return seg[i]+get(i+z,mid+1,r,v,seg);
    }
}
void solve()
{
    int n;
    cin>>n;
    while(lg.size()<=n)
        lg.pb(lg[lg.size()>>1]+1);
    vector<vector<int>> p(20,vector<int>(n));
    cin>>p[0];
    for(int i=1;i<20;++i){
        for(int j=0;(j+(1<<i))<=n;++j){
            p[i][j] = max(p[i-1][j],p[i-1][j+(1<<(i-1))]);
        }
    }
    function<int(int,int)> getMax = [&](int l,int r){
        int k = lg[r-l+1];
        return max(p[k][l],p[k][r-(1<<k)+1]);
    };
    int q;
    cin>>q;
    vector<int> ans(q);
    vector<vector<pair<int,int>>> qu(n);
    for(int i=0;i<q;++i){
        int l,r;
        cin>>l>>r;
        if(l!=r){
            qu[r-1].pb(mp(i,l));
        }
    }
    stack<int> st;
    stack<pair<int,int>> up;
    vi seg((n+1)<<1);
    for(int i=0;i<n;++i){
        while((!st.empty())&&(p[0][st.top()]>=p[0][i])){
            update(0,0,n,up.top().F,up.top().S,-1,seg); 
            up.pop();
            st.pop();
        }
        if(!st.empty()){
            int L = 0, R = st.top()-1, f = st.top();
            while(L<=R){
                int mid = (L+R)>>1;
                if(getMax(mid,st.top())<p[0][i]){
                    f = mid;
                    R = mid-1;
                }
                else
                    L = mid+1;
            }
            up.push(mp(f+1,st.top()+1));
        }
        else
            up.push(mp(0,0));
        update(0,0,n,up.top().F,up.top().S,1,seg);
        for(auto w:qu[i]){
            if(get(0,0,n,w.S,seg))
                ans[w.F] = 1;
        }
        st.push(i);
    }
    for(auto x:ans)
        cout<<(x?"Yes":"No")<<"\n";
}
void pre(){

}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    //cin>>t;
    while(t--)solve();
	return 0;
}
