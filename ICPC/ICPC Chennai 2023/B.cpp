#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const ull B = 1ull<<63;
struct num{
    vector<ull> n;
    num(int x=0):n(1,x){}
    void add(int k = 0){
        bool c = 1;
        for(int i=k;(i<n.size())&&c;++i){
            ++n[i];
            if(n[i]==B){
                n[i] = 0;
            }
            else{
                c = 0;
            }
        }
        if(c){
            n.push_back(1);
        }
    }
    num& operator+=(const num& other){
        bool c = 0;
        for(int i=0;i<other.n.size();++i){
            n[i]+=(other.n[i]+c);
            if(n[i]>=B){
                n[i]-=B;
                c = 1;
            }
            else{
                c = 0;
            }
        }
        if(c)
            add(other.n.size());
        return *this;
    }
    num& operator ++(){
        add();
        return *this;
    }
    bool operator < (const num& other)const{
        if(n.size()!=other.n.size())return n.size()<other.n.size();
        for(int i=n.size()-1;i>=0;--i){
            if(n[i]!=other.n[i])return n[i]<other.n[i];
        }
        return false;
    }
    bool operator == (const num& other)const{
        if(n.size()!=other.n.size())return false;
        return n==other.n;
    }
};
const int mod = 998244353;
struct node{
    int base, digit, gcur, gadd;
    num cur,add;
    node(int _base):
        base(_base),
        digit(1),
        gcur(1),
        gadd(1),
        cur(1),
        add(1){}
    node& operator ++(){
        ++digit;
        cur+=add;
        gcur+=gadd;
        if(gcur>=mod){
            gcur-=mod;
        }
        if(digit==base){
            digit = 1;
            ++cur;
            add = cur;
            ++gcur;
            if(gcur==mod)gcur=0;
            gadd = gcur;
        }
        return *this;
    }
    bool operator < (const node& other)const{
        return other.cur<cur;
    }
};
template<int max_base>
class solve{
    public:
        constexpr static vector<int> init_pre(){
            priority_queue<node> q;
            for(int i=2;i<=16;++i){
                q.push(node(i));
            }
            vector<int> pre(1+max_base);
            num cur;
            for(int i=1;i<=max_base;++i){
                auto t = q.top();
                q.pop();
                if(t.cur==cur){
                    --i;
                }
                else{
                    cur = t.cur;
                    pre[i] = pre[i-1]+t.gcur;
                    if(pre[i]>=mod)pre[i]-=mod;
                }
                ++t;
                q.push(t);
            }
            return pre;
        }
        static const vector<int> pre;
};
template<int max_base>const vector<int> solve<max_base>::pre = init_pre();
const int K = 1e6;
int get(int k1,int k2){
    int x = solve<K>::pre[k2]-solve<K>::pre[k1-1]+mod;
    if(x>=mod)x-=mod;
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int k1,k2;
        cin>>k1>>k2;
        cout<<get(k1,k2)<<"\n";
    }
    return 0;
}