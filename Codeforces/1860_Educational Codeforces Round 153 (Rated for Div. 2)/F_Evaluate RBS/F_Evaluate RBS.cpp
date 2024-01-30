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

void solve()
{
    int n;
    cin>>n;
    vector<pair<pair<int,int>,char>> elem(n<<1);
    cin>>elem;
    sort(elem.begin(),elem.end());
    int m = n<<1;
    vector<int> ind(m),cur_order;
    iota(ind.begin(),ind.end(),0);
    cur_order = ind;
    Log("check"<<endl);
    vector<pair<pair<int,int>,pair<int,int>>> angles;
    for(int i=0;i<m;++i){
        for(int j=0;j<i;++j){
            int x = -(elem[i].F.second-elem[j].F.second);
            int y = elem[i].F.first-elem[j].F.first;
            if(y!=0){
                if(y<0){
                    y*=-1;
                    x*=-1;
                }
                if(x>0){
                    int h = __gcd(x,y);
                    x/=h;
                    y/=h;
                    angles.pb(mp(mp(x,y),mp(i,j)));
                }
            }
        }
    }
    sort(angles.begin(),angles.end(),[](auto a,auto b){
        return (a.first.first*1ll*b.first.second)>(a.first.second*1ll*b.first.first);
    });
    Log("check2"<<endl);
    int neg = 0;
    vector<int> pre(m+1);
    for(int i=1;i<=m;++i){
        pre[i] = pre[i-1]+(elem[cur_order[i-1]].S=='('?1:-1);
        if(pre[i]<0)
            ++neg;
    }
    Log("check3"<<endl);
    if(neg==0){
        cout<<"YES\n";
        return;
    }
    Log(neg<<endl);
    Log(angles<<endl);
    for(int i=0,j=0;i<angles.size();i=j){
        vector<pair<int,int>> cur;
        while((j<angles.size())&&(angles[i].F==angles[j].F)){
            cur.push_back(mp(ind[angles[j].S.S],ind[angles[j].S.F]));
            ++j;
        }
        sort(cur.begin(),cur.end());
        vector<pair<int,int>> resolve;
        Log(cur<<endl);
        for(int u=0,v=0;u<cur.size();u=v){
            int curR = cur[u].S;
            while((v<cur.size())&&(cur[v].F<=curR)){
                curR = max(curR,cur[v++].S);
            }
            resolve.push_back(mp(cur[u].F,curR));
        }
        for(auto p:resolve){
            for(int u=p.F;u<p.S;++u){
                if(pre[u+1]<0)
                    --neg;
            }
        }
        if(neg==0){
            cout<<"YES\n";
            return;
        }
        for(auto p:resolve){
            reverse(cur_order.begin()+p.F,cur_order.begin()+p.S+1);
            for(int u=p.F,v=p.F;u<=p.S;u=v){
                while((v<=p.S)&&(elem[cur_order[v]].F==elem[cur_order[u]].F))
                    ++v;
                reverse(cur_order.begin()+u,cur_order.begin()+v);
            }
            for(int u=p.F;u<p.S;++u){
                pre[u+1] = pre[u]+(elem[cur_order[u]].S=='('?1:-1);
                ind[cur_order[u]]=u;
                if(pre[u+1]<0)
                    ++neg;
            }
            ind[cur_order[p.S]] = p.S;
        }
    }
    
    cout<<"NO\n";
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)solve();
	return 0;
}