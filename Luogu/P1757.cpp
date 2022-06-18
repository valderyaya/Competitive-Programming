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

int n,m,dp[1005],w[1001],p,c[1001],x;
vector<int> v[205];
int main(){Rosario
    cin>>m>>n;
    REP(i,n){
        cin>>w[i]>>c[i]>>x;
        p=max(p,x); v[x].em(i);
    }
    REP1(i,1,p)
        for(int j=m;j>=0;--j)
            for(auto &k:v[i])
                if(j>=w[k]) dp[j]=max(dp[j],dp[j-w[k]]+c[k]);
    cout<<dp[m]<<"\n";
    return 0;
}
