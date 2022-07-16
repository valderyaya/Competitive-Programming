//#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

#define int ll
const int z=3e5+5,inf=1e18;
int n,d[z],dp[2][z];
vector<pll> v[z];
void dfs(int x,int p){
    vector<int> ve;
    for(auto &[i,w]:v[x]){
        if(i==p) continue;
        dfs(i,x);
        ve.em(dp[0][i]+w-dp[1][i]);
        dp[0][x]+=dp[1][i], dp[1][x]+=dp[1][i];
    }
    sort(ve.rbegin(), ve.rend());
    for(int i=0;i<ve.size();++i){
        if(ve[i]<=0) break;
        if(i<d[x]) dp[1][x]+=ve[i];
        if(i+1<d[x]) dp[0][x]+=ve[i];
    }
    if(!d[x]) dp[0][x]=-inf;
}
signed main(){StarBurstStream
    cin>>n;
    for(int i=1;i<=n;++i) cin>>d[i];
    for(int x,y,w,i=1;i<n;++i){
        cin>>x>>y>>w;
        v[x].em(y,w);
        v[y].em(x,w);
    }
    dfs(1,1);
    cout<<dp[1][1]<<"\n";
}
