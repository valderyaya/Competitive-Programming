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

vector<pii> v;
int n,m,dp[40005];
int main(){Rosario
    cin>>n>>m;
    int val,w,s;
    while(n--){
        cin>>val>>w>>s;
        for(int i=1;s>i;s-=i,i<<=1) v.em(mkp(i*w,i*val));
        v.em(mkp(s*w,s*val));
    }
    for(auto &i:v)
        for(int j=m;j>=i.F;--j) dp[j]=max(dp[j],dp[j-i.F]+i.S);
    cout<<dp[m]<<"\n";
    return 0;
}
