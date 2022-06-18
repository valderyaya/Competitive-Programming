//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

const int z=1000005;
int ans=1,n,sz[z];
ll dp[z],mn;
vector<int> v[z];
void dfs(int x,int p,int d){
    sz[x]=1; dp[1]+=d;
    for(auto &i:v[x]){
        if(i==p) continue;
        dfs(i,x,d+1);
        sz[x]+=sz[i];
    }
}
void dfs2(int x,int p){
    for(auto &i:v[x]){
        if(i==p) continue;
        dp[i]=dp[x]-sz[i]*2+n;
        if(dp[i]>mn) mn=dp[i],ans=i;
        dfs2(i,x);
    }
}
signed main(){Aincrad
    cin>>n;
    for(int x,y,i=1;i<n;++i) cin>>x>>y,v[x].em(y),v[y].em(x);
    dfs(1,0,0);
    mn=dp[1];
    // cout<<mn<<endl;
    // REP1(i,1,n) cout<<sz[i]<<endl;
    dfs2(1,0);
    cout<<ans<<"\n";
    return 0;
}
