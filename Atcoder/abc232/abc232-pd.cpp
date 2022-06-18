#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define all(x) x.begin(),x.end()
#define em emplace_back
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

int n,m,mx=1,dp[105][105];
string s[105];
signed main(){Rosario
	cin>>n>>m;
	REP(i,n) cin>>s[i];
	REP1(i,0,n) REP1(j,0,m) dp[i][j]=-1e9;
	dp[1][1]=1;
	REP1(i,1,n) REP1(j,1,m){
		if(i==1&&j==1) continue;
		if(s[i-1][j-1]=='#')continue;
		dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
		mx=max(mx,dp[i][j]);
	}
	cout<<mx<<"\n";
}
