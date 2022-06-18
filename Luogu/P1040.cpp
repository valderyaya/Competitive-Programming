//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int dp[35][35],rt[35][35],n;
void print(int l,int r){
    if(l>r) return;
    if(l==r) return cout<<l<<' ',void();
    cout<<rt[l][r]<<' ';
    print(l,rt[l][r]-1);
    print(rt[l][r]+1,r);
}
int main(){Rosario
    cin>>n;
    REP1(i,1,n) cin>>dp[i][i];
    REP1(k,2,n)
        for(int l=1;l+k-1<=n;l++){
            int r=l+k-1;
            if(dp[l][r]<dp[l][l]+dp[l+1][r]) dp[l][r]=dp[l][l]+dp[l+1][r],rt[l][r]=l;
            if(dp[l][r]<dp[r][r]+dp[l][r-1]) dp[l][r]=dp[r][r]+dp[l][r-1],rt[l][r]=r;
            for(int i=l+1;i<=r-1;i++) 
                if(dp[l][r]<dp[l][i-1]*dp[i+1][r]+dp[i][i]) dp[l][r]=dp[l][i-1]*dp[i+1][r]+dp[i][i],rt[l][r]=i;
        }
    cout<<dp[1][n]<<"\n";
    print(1,n);
    return 0;
}
