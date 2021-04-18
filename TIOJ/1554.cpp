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

int n,a[20][20];
double dp[1048800]={1};
int cal(int x){
    int res=0;
    REP(i,n) if(x>>i&1) res++;
    return --res;
}
int main(){Rosario
    cin>>n;
    REP(i,n) REP(j,n) cin>>a[i][j];
    int N=(1<<n);
    for(int i=1;i<N;++i){
        int now=cal(i);
        for(int j=0;j<n;++j)
            if(i>>j&1)
                dp[i]=max(dp[i],dp[i^(1<<j)]*a[j][now]/100.);
    }
    cout<<fixed<<setprecision(2)<<dp[N-1]*100<<"\n";
}
