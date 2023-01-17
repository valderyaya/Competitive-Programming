#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
#define mkp make_pair
 
int n,m;
vector<int> v[100005],ans;
bitset<100001> vis;
void dfs(int x){
    vis[x]=1;
    for(auto &i:v[x]) if(!vis[i]) dfs(i);
}
signed main(){Rosario
    cin>>n>>m;
    for(int x,y;m--;) cin>>x>>y,v[x].em(y),v[y].em(x);
    REP1(i,1,n) if(!vis[i]){
        ans.em(i);
        dfs(i);
    }
    cout<<ans.size()-1<<"\n";
    REP(i,ans.size()-1) cout<<ans[i]<<' '<<ans[i+1]<<"\n";
}
