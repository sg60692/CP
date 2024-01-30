#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<deque>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
using namespace std;
typedef long long ll;
const double pi = acos(-1.0);
const ll mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
const int maxn = 1e5 + 50;
int a[maxn];
vector<int> ve[maxn];
int zt[maxn];
int n;
void dfs(int pos, int y)
{
    if(zt[pos] == -2) return ;
    if(!zt[pos]) zt[pos] = y;
    else zt[pos] = -2;
    if(a[pos]) y = a[pos];
    for(auto it : ve[pos])
    {
        if(zt[it] != y) dfs(it, y);
    }
}
int main()
{
    memset(zt, 0, sizeof(zt));
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        int x;
        cin >> x;
        for(int j=0; j<x; j++)
        {
            int y;
            cin >> y;
            ve[i].push_back(y);
        }
    }
    dfs(1, -1);
    for(int i=1; i<=n; i++)
    {
        if(zt[i] == -1) cout << "sober ";
        else if(zt[i] == -2) cout << "unknown ";
        else cout << zt[i] << ' ';
        if(a[i] > 0) cout << a[i] << endl;
        else
        {
            if(zt[i] == -1) cout << "sober" << endl;
            else if(zt[i] == -2) cout << "unknown" << endl;
            else cout << zt[i] << endl;
        }
    }
    return 0;
}