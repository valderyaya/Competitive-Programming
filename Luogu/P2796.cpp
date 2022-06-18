//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

ll n,sum,dp[100001];
const ll md=1e9+7;
vector<int> v[100001];
void dfs(int x,int p){
    dp[x]=1;
    for(auto &i:v[x]){
        if(i==p) continue;
        dfs(i,x);
        dp[x]*=dp[i]+1;
        dp[x]%=md;
    }
}
signed main(){Aincrad
    cin>>n;
    for(int x,y,i=1;i<n;++i) cin>>x>>y,v[x].em(y),v[y].em(x);
    dfs(1,0);
    REP1(i,1,n) sum=(sum+dp[i])%md;
    cout<<sum<<"\n";
    return 0;
}
