#include<bits/stdc++.h>
using namespace std;
 
const int md=1e9+7;
int n,dp[1005][1005];
string s[1005];
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=0;i<n;++i) cin>>s[i];
    dp[1][1]=(s[0][0]!='*');
    for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
 	    if(s[i-1][j-1]=='.') dp[i][j]+=(dp[i-1][j]+dp[i][j-1])%md;
    cout<<dp[n][n]<<"\n";    
    return 0;
}
