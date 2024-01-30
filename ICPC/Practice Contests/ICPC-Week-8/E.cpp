#include<bits/stdc++.h>
using namespace std;
long long find(long long a,long long b,long long c,long long y){
    long long l = 1e6+1;
    long long r = 1e18;
    y-=a;
    while(l<=r){
        __int128 mid = (l+r)>>1;
        __int128 x = (b*mid)+(c*mid*mid);
        if(x==y)return mid;
        if(x<y){
            l = mid+1;
        }
        else
            r = mid-1;
    }
    return -1;
}
long long check(long long base,long long y){
    long long ans = 0;
    long long k = 1;
    while(y){
        long long d = y%base;
        if(d>=10)
            return -1;
        ans += (d*k);
        k*=10;
        y/=base;
    }
    return ans;
}
void solve(){
    long long y,l;
    cin>>y>>l;
    long long base = 10;
    for(int i=11;i<=1e6;++i){
        if(check(i,y)>=l)
            base = max(i*1ll,base);
    }
    for(int a=0;a<10;++a){
        for(int b=0;b<10;++b){
            for(int c=0+(b==0);c<10;++c){
                long long t = find(a,b,c,y);
                if((t!=-1)&&((a+b*10+c*100)>=l)){
                    base = max(base,t);
                }
            }
        }
    }
    cout<<base<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}