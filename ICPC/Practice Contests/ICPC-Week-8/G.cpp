#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#include<bits/stdc++.h>
using namespace std;
void inline reduce(vector<int> &c){
    long long g = __gcd(c[0],c[1]);
    c[0]/=g;
    c[1]/=g;
    if(c[1]<0){
        c[1]=-c[1];
        c[0]=-c[0];
    }
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> segs(n,vector<int>(3));
    for(auto &seg:segs)
        for(auto &p:seg)
            cin>>p;
    for(auto &seg:segs){
        if(seg[0]>seg[1])
            swap(seg[0],seg[1]);
        seg[2] = -seg[2];
    }
    long long fans = 0;
    for(int i=0;i<n;++i){
        vector<vector<int>> cur;
        for(int j=0;j<n;++j){
            if(segs[i][2]<segs[j][2]){
                int x1 = segs[j][0]-segs[i][0];
                int x2 = segs[j][1]-segs[i][0];
                int y = segs[j][2]-segs[i][2];
                vector<int> c1 = {x1,y,x2-x1};
                vector<int> c2 = {x2,y,x1-x2};
                reduce(c1);
                reduce(c2);
                cur.push_back(c1);
                cur.push_back(c2);
            }
            if(segs[i][2]>segs[j][2]){
                int x1 = segs[j][0]-segs[i][0];
                int x2 = segs[j][1]-segs[i][0];
                int y = segs[j][2]-segs[i][2];
                vector<int> c1 = {x1,y,x1-x2};
                vector<int> c2 = {x2,y,x2-x1};
                reduce(c1);
                reduce(c2);
                cur.push_back(c1);
                cur.push_back(c2);
            }
        }
        sort(cur.begin(),cur.end(),[](auto &a,auto &b){
            if((a[0]<0)&&(b[0]>0))return true;
            if((a[0]>0)&&(b[0]<0))return false;
            return (a[0]*1ll*b[1])<(a[1]*1ll*b[0]);
        });
        long long cur_ans = segs[i][1]-segs[i][0];
        fans = max(cur_ans,fans);
        for(int lc=0,rc=0;lc<cur.size();lc=rc){
            long long pos = 0 ,neg = 0;
            while((rc<cur.size())&&(cur[lc][0]==cur[rc][0])&&(cur[lc][1]==cur[rc][1])){
                if(cur[rc][2]>0)pos+=cur[rc][2];
                else neg+=cur[rc][2];
                ++rc;
            }
            fans = max(fans,cur_ans+pos);
            cur_ans+=(pos+neg);
        }
    }
    cout<<fans<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}