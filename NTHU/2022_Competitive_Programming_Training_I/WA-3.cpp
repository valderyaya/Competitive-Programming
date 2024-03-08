//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
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

string a,b;
int dp[3001][3001],pre[3001][3001];
void dfs(int x,int y){
    if(!pre[x][y]) return;
    if(pre[x][y]==1) dfs(x-1,y);
    else if(pre[x][y]==2) dfs(x,y-1);
    else dfs(x-1,y-1), cout<<a[x-1],void();
}
signed main(){StarBurstStream
    cin>>a>>b;
    REP(i,a.size()) REP(j,b.size()) {
        if(a[i]==b[j]) dp[i+1][j+1]=dp[i][j]+1, pre[i+1][j+1]=3;
        else{
            if(dp[i+1][j] > dp[i][j+1]) dp[i+1][j+1]=dp[i+1][j], pre[i+1][j+1]=2;
            else dp[i+1][j+1]=dp[i][j+1], pre[i+1][j+1]=1;
        }
    }
    dfs(a.size(),b.size());
}
