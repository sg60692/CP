#include<bits/stdc++.h>
#define F first
#define S second
#define ll long long
#define ld long double
using namespace std;
pair<bool,pair<ld,ld>> solver(ld a,ld b, ld c,ld val){
    if(((-(b*b/(4*a)))+c)<val)
        return make_pair(false,make_pair(0,0));
    long long d = sqrt(b*b-(4*a*c));
    return make_pair(true,make_pair((-b-d)/(2*a),(-b+d)/(2*a))); 
}
pair<bool,pair<ld,ld>> intersect(pair<long double> i1,pair<long double> i2){

}
void solve(){
    int n;
    cin>>n;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1;
    // cin>>t;
    while(t--)
        solve();
}