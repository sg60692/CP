#include<iostream>
#include<vector>
using namespace std;
const int N = 1e4+1;
struct node{
    int l,r,rev,p;
    int pCost,pMax;
    node():l(0),r(0),rev(0),pMax(0),pCost(0){}
}nodes[N];
void pull(int u){
    nodes[u].pMax = max(
                        max(nodes[nodes[u].l].pMax, nodes[nodes[u].l].pCost),
                        max(nodes[nodes[u].r].pMax, nodes[nodes[u].r].pCost)
                    );
}
void push(int u){
    if(nodes[u].rev){
        swap(nodes[u].l,nodes[u].r);
        nodes[nodes[u].l].rev^=1;
        nodes[nodes[u].r].rev^=1;
        nodes[u].rev = 0;
    }
}
void splay(int u){
    int p = nodes[u].p;
    if(nodes[p].l == u){
        if(nodes[u].r){
            swap(nodes[nodes[u].r].pCost,nodes[u].pCost);
            nodes[nodes[u].r].p = p;
        }
        nodes[p].l = nodes[u].r;
        nodes[u].r = p;
    }
    else{
        if(nodes[u].l){
            swap(nodes[nodes[u].l].pCost,nodes[u].pCost);
            nodes[nodes[u].l].p = p;
        }
        nodes[p].r = nodes[u].l;
        nodes[u].l = p;
    }
    
    nodes[u].p = nodes[p].p;
    nodes[p].p = u;
    swap(nodes[u].pCost, nodes[p].pCost);
    if(nodes[nodes[u].p].l==p){
        nodes[nodes[u].p].l = u;
    }
    else if(nodes[nodes[u].p].r==p){
        nodes[nodes[u].p].r = u;
    }
}
void splayTop(int x){
    push(x);
    while((nodes[nodes[x].p].l==x)||(nodes[nodes[x].p].r==x)){
        int y = nodes[x].p;
        int z = nodes[y].p;
        if((nodes[z].l==y)||(nodes[z].r==y)){
            push(z);push(y);push(x);
            if(
                ((nodes[z].l==y)&&(nodes[y].l==x))
                ||
                ((nodes[z].r==y)&&(nodes[y].r==x))
            ){
                splay(y);
                splay(x);
            }
            else{
                splay(x);
                splay(x);
            }
            pull(z);pull(y);pull(x);
        }
        else{
            push(y);push(x);
            splay(x);
            pull(y);pull(x);
        }
    }
}
void access(int x){
    int u = x, v = 0;
    //cout<<"Enter: "<<x<<endl;
    //cout<<nodes[u].p<<" "<<nodes[u].l<<" "<<nodes[u].r<<endl;
    while(u){
        splayTop(u);
        nodes[u].r = v;
        pull(u);
        v = u;
        u = nodes[u].p;
    }
    splayTop(x);
}
void makeRoot(int u){
    access(u);
    nodes[u].rev^=1;
    push(u);
}
void dfs(int u,int p,vector<pair<int,int>> *g,vector<int> &h){
    nodes[u] = nodes[0];
    for(auto v:g[u]){
        if(v.first!=p){ 
            h[v.first] = h[u]+1;
            dfs(v.first,u,g,h);
            nodes[v.first].p = u;
            nodes[v.first].pCost = v.second;
        }
    }
}
void solve(){
	nodes[0].rev = 0;
    int n;
    cin>>n;
    vector<pair<int,int> > edges(n);
    vector<pair<int,int> > g[n+1];
    vector<int> h(n+1);
    for(int i=1;i<n;++i){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
        edges[i] = make_pair(u,v);
    }
    dfs(1,0,g,h);
    //cout<<"check: "<<nodes[0].p<<endl;
    string s;
    while(true){
        cin>>s;
        if(s=="DONE"){
            break;
        }
        int x,y;
        cin>>x>>y;
        if(s=="CHANGE"){
            int u = edges[x].first;
            int v = edges[x].second;
            makeRoot(u);
            access(v);
            nodes[nodes[v].l].pCost = y;
            pull(v);
        }
        else{
            makeRoot(y);
            access(x);
            cout<<max(nodes[nodes[x].l].pCost, nodes[nodes[x].l].pMax)<<"\n";
        }

        //cout<<"check: "<<nodes[0].p<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        solve();
}