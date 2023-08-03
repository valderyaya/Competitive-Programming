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
#define lb(x) x&(-x)
#define pll pair<ll,ll>
#define mkp make_pair

const int inf=1e9;
int dp[10001][26][26],ans=inf, d[26][26],n;
string s, p[3]={"QWERTYUIOP","ASDFGHJKL","ZXCVBNM"};
signed main(){StarBurstStream
    cin>>n>>s;
    REP1(i,0,n) REP(j,26) REP(k,26) dp[i][j][k]=inf;
    REP(i,3) REP1(j,i,2) REP(k,p[i].size()) REP(l,p[j].size()){
        int x=p[i][k]-'A', y=p[j][l]-'A', dx=j-i, dy=abs(k-l);
        if(k>l) dy-=min(k-l,j-i);
        d[x][y]=d[y][x]=dx+dy;
    }
    dp[0]['F'-'A']['J'-'A']=0;
    REP(i,n){
        int p=s[i]-'A';
        REP(j,26) REP(k,26){
            if(dp[i][j][k]!=inf){
                dp[i+1][p][k]=min(dp[i+1][p][k],dp[i][j][k]+d[j][p]);
                dp[i+1][j][p]=min(dp[i+1][j][p],dp[i][j][k]+d[k][p]);
            }
        }
    }
    REP(i,26) REP(j,26) ans=min(ans, dp[n][i][j]);
    cout<<ans<<"\n";
    return 0;
}
