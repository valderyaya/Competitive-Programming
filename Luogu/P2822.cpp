//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define em emplace_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int c[2005][2005],s[2005][2005],t,k,n,m;
signed main(){Rosario
    cin>>t>>k;
    REP1(i,0,2000){
        c[i][0]=1;
        REP1(j,1,i) c[i][j]=(c[i-1][j]+c[i-1][j-1])%k;
    }
    REP1(i,1,2000) {
        REP1(j,1,i) s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1]+(c[i][j]==0);
        s[i][i+1]=s[i][i];
    }
    while(t--){
        cin>>n>>m;
        cout<<s[n][(m>n?n:m)]<<'\n';
    }
    return 0;
}
