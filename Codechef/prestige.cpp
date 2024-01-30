#include<iostream>
using namespace std;
const int N = 2e5+1;
struct node{
    int l,r,rev,n,p;
    long long fa,fb,va,vb;
    node():l(0),r(0),fa(0),fb(0),va(0),vb(0){}
}nodes[N];
void combine(int u){
    nodes[u].n = nodes[nodes[u].l].n+nodes[nodes[u].r].n+1;
    nodes[u].fa = nodes[nodes[u].l].fa+nodes[nodes[u].r].fa+nodes[u].va;
    nodes[u].fb = nodes[nodes[u].l].fb+nodes[nodes[u].r].fb+nodes[u].vb;
}
void splay(int u){
    int p = nodes[u].p;
    if(nodes[p].r == u){
        nodes[p].r = nodes[u].l;
        nodes[nodes[u].l].p = p;
        nodes[u].l = p;
    }
    else{
        nodes[p].l = nodes[u].r;
        nodes[nodes[u].r].p = p;
        nodes[u].r = p;
    }
    if(nodes[nodes[p].p].r == p)
        nodes[nodes[p].p].r = u;
    else
        nodes[nodes[p].p].l = u;
    nodes[u].p = nodes[p].p;
    nodes[p].p = u;
    combine(p);
    combine(u);
}
void flip(int u){
    swap(nodes[u].fa,nodes[u].fb);
    swap(nodes[u].va,nodes[u].vb);
    swap(nodes[u].l,nodes[u].r);
    nodes[u].rev^=1;
}
void push(int u){
    if(nodes[u].rev){
        nodes[u].rev = 0;
        flip(nodes[u].l);
        flip(nodes[u].r);
    }
}
int find(int root,int l){
    int cur = root;
    while(l){
        push(cur);
        if(nodes[nodes[cur].l].n>=l)
            cur = nodes[cur].l;
        else{
            l -= nodes[nodes[cur].l].n;
            --l;
            if(l)
                cur = nodes[cur].r;
        }
    }
    if(cur==root)
        return cur;
    while(true){
        int y = nodes[cur].p;
        if(y==root){
            splay(cur);
            break;
        }
        else{
            int z = nodes[y].p;
            if(
                ((nodes[z].l==y)&&(nodes[y].l==cur))
                ||
                ((nodes[z].r==y)&&(nodes[y].r==cur))
            ){
                splay(y);
                splay(cur);
            }
            else{
                splay(cur);
                splay(cur);
            }
            if(z==root)
                break;
        }
    }
    return cur;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>nodes[i].va;
    for(int i=1;i<=n;++i)
        cin>>nodes[i].vb;
    for(int i=1;i<=n;++i){
        nodes[i+1].p = i;
        nodes[i].r = i+1;
    }
    nodes[n+2].r = 1;
    nodes[1].p = n+2;
    nodes[n+3].r = n+2;
    nodes[n+2].p = n+3;
    int root = n+2;
    for(int i=n+1;i>=1;--i)
        combine(i);
    combine(n+2);
    int p = 0;
    while(m--){
        int o;
        cin>>o;
        if(o==1){
            int l,r;
            cin>>l>>r;
            root = find(root,l);
            int more = find(nodes[root].r,r-l+2);
            flip(nodes[more].l);
            combine(more);
            combine(root);
        }
        else if(o==2){
            int k;
            cin>>k;
            p = k-p;
        }
        else{
            int a,b,c,d;
            cin>>a>>b>>c>>d;
            root = find(root, a);
            int more = find(nodes[root].r,b-a+2);
            long long ans = nodes[nodes[more].l].fa;
            if(p>=d){
                ans = -ans;
            }
            else if(p>=c){
                more = find(more,p-c+2);
                ans-=((nodes[nodes[more].l].fa)<<1);
            }
            cout<<ans<<"\n";
        }
    }
}