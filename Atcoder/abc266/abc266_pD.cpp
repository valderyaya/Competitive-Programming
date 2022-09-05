#include<bits/stdc++.h>
using namespace std;

#define int long long
const int z=1e5+5;
int mx,dp[5][z],n,val[z],pos[z],tim;
signed main(){
    cin>>n;
    for(int i=0,x,y,v;i<n;++i){
        cin>>x>>y>>v;
        val[x]=v, pos[x]=y;
        tim=max(tim,x);
    }
    for(int i=1;i<5;++i) dp[i][0]=-1e18;
    for(int i=1;i<=tim;++i){
        for(int j=0;j<5;++j){
            dp[j][i]=dp[j][i-1];
            if(j) dp[j][i]=max(dp[j][i],dp[j-1][i-1]);
            if(j!=4) dp[j][i]=max(dp[j][i],dp[j+1][i-1]);
        }
        dp[pos[i]][i]+=val[i];
    }
    for(int i=0;i<5;++i) mx=max(mx,dp[i][tim]);
    cout<<mx<<"\n";
}
