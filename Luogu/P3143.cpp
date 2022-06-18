#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)
#define wait system("pause");

int n,k,dp[50005],a[50005],r=1,ans=0,mx=0;
int main(){Rosario
    cin>>n>>k;a[n]=2e9;
    REP(i,n) cin>>a[i];
    sort(a,a+n);
    REP(i,n){
        while(a[i]+k>=a[r]) r++;
        dp[r]=max(dp[r],r-i);
        mx=max(mx,dp[i]);
        ans=max(ans,mx+r-i);
    }cout<<ans<<"\n";
//    wait
    return 0;
}
