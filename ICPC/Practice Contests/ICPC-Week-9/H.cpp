#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
using namespace std;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int x = 0;
    stack<int> st;
    vector<int> ans((n<<1),-1);
    vector<int> ord((n<<1));
    for(int i=0;i<(n<<1);++i){
        if((s[i]>='a')&&(s[i]<='z'))
            ord[i] = ++x;
    }
    for(int i=0;i<(n<<1);++i){
        char c = s[i];
        char d;
        if((c<='Z')&&(c>='A')){
            d = c-'A'+'a';
            if(st.empty()||(s[st.top()]!=d))
                st.push(i);
            else{
                ans[i] = ord[st.top()];
                st.pop();
            }
        }
        else{
            d = c-'a'+'A';
            if(st.empty()||(s[st.top()]!=d))
                st.push(i);
            else{
                ans[st.top()] = ord[i];
                st.pop();
            }
        }
    }
    if(st.empty()){
        for(int i=0;i<(n<<1);++i){
            if(ans[i]!=-1)
                cout<<(ans[i])<<" ";
        }
        cout<<"\n";
    }
    else cout<<"Impossible\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}