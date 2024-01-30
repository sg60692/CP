#include<iostream>
#include<stack>
#include<vector>
using namespace std;
const int N = 2e5+1;
struct node{
    int l,r,rev,n,p;
    long long a,sum;
    node():l(0),r(0),a(0),sum(0){}
}nodes[N];
void combine(int u){
    nodes[u].n = nodes[nodes[u].l].n+nodes[nodes[u].r].n+1;
    nodes[u].sum = nodes[nodes[u].l].sum+nodes[nodes[u].r].sum+nodes[u].a;
}
void splay(int u){
    int p = nodes[u].p;
    if(nodes[p].l == u){
        nodes[p].l = nodes[u].r;
        nodes[nodes[u].r].p = p;
        nodes[u].r = p;
        
    }
    else{
        nodes[p].r = nodes[u].l;
        nodes[nodes[u].l].p = p;
        nodes[u].l = p;
    }
    nodes[u].p = nodes[p].p;
    nodes[p].p = u;
    combine(p);
    combine(u);
    if(nodes[u].p){
        if(nodes[nodes[u].p].l==p)
            nodes[nodes[u].p].l = u;
        else
            nodes[nodes[u].p].r = u;
        combine(nodes[u].p);
    }
}
void flip(int u){
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
void makeRoot(int x){
    int cur = x;
    stack<int> st;
    while(cur){
        st.push(cur);
        cur = nodes[cur].p;
    }
    while(!st.empty()){
        cur = st.top();
        st.pop();
        push(cur);
    }
    while(nodes[x].p){
        int y = nodes[x].p;
        if(nodes[y].p){
            int z = nodes[y].p;
            if(nodes[y].l==x){
                if(nodes[z].l==y){
                    splay(y);
                    splay(x);
                }
                else{
                    splay(x);
                    splay(x);
                }
            }
            else{
                if(nodes[z].l==y){
                    splay(x);
                    splay(x);
                }
                else{
                    nodes[y].r = x;
                    splay(y);
                    splay(x);
                }
            }
        }
        else{
            splay(x);
        }
    }
    nodes[x].r = 0;
    combine(x);
    flip(x);
    push(x);
}
void addEdge(int u,int v){
    makeRoot(u);
    makeRoot(v);
    nodes[v].r = u;
    nodes[u].p = v;
    combine(v);
}
void remEdge(int u,int v){
    makeRoot(u);
    makeRoot(v);
    nodes[nodes[v].r].p = 0;
    nodes[v].r = 0;
    combine(v);
}
void changeVal(int p,int x){
    makeRoot(p);
    nodes[p].a += x;
    combine(p);
}
long long get(int u,int v){
    makeRoot(u);
    makeRoot(v);
    return nodes[v].sum;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>nodes[i].a;
        combine(i);
    }
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        addEdge(++u,++v);
    }
    while(q--){
        int o;
        cin>>o;
        if(o==0){
            int u,v;
            cin>>u>>v;
            remEdge(++u,++v);
            cin>>u>>v;
            addEdge(++u,++v);
        }
        else if(o==1){
            int p,x;
            cin>>p>>x;
            changeVal(++p,x);
        }
        else{
            int u,v;
            cin>>u>>v;
            cout<<get(++u,++v)<<"\n";
        }
    }
}