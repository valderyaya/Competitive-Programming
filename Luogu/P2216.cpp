//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#include<bits/extc++.h>
//using namespace __gnu_pbds;
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

int n,m,x,a[1001][1001],mx[1001][1001],mn[1001][1001],A[1001][1001],B[1001][1001],dp[2][1001],l,r,L,R,ans=1e9;
int main(){Rosario
    cin>>n>>m>>x;
    REP(i,n){l=r=L=R=0;
        REP(j,m){cin>>a[i][j];
            while(r>l&&j-dp[0][l]>=x) l++;
            while(r>l&&a[i][dp[0][r-1]]<=a[i][j]) r--;
            dp[0][r++]=j;mx[i][j]=a[i][dp[0][l]];
            while(R>L&&j-dp[1][L]>=x) L++;
            while(R>L&&a[i][dp[1][R-1]]>=a[i][j]) R--;
            dp[1][R++]=j;mn[i][j]=a[i][dp[1][L]];
        }
    }
    REP(j,m){l=r=L=R=0;
        REP(i,n){
            while(r>l&&i-dp[0][l]>=x) l++;
            while(r>l&&mx[dp[0][r-1]][j]<=mx[i][j]) r--;
            dp[0][r++]=i;A[i][j]=mx[dp[0][l]][j];;
            while(R>L&&i-dp[1][L]>=x) L++;
            while(R>L&&mn[dp[1][R-1]][j]>=mn[i][j]) R--;
            dp[1][R++]=i;B[i][j]=mn[dp[1][L]][j];
        }
    }
    for(int i=x-1;i<n;i++) for(int j=x-1;j<m;j++) ans=min(ans,A[i][j]-B[i][j]);
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
