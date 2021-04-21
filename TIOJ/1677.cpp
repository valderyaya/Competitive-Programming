//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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
#define lb(x) (x&-x)

ll dp[47]={0,1,1};
bool ck;
void dfs(ll n,ll c){
    if(c<=0||c>dp[n]) return;
    if(c==1&&n<3){
        cout<<(n==1?0:1)<<"\n";
        ck=0;return;
    }
    if(dp[n-2]<c) dfs(n-1,c-dp[n-2]);
    else dfs(n-2,c);
}
int main(){Rosario
    for(int i=3;i<=46;i++) dp[i]=dp[i-1]+dp[i-2];
    ll m,n,k;
    cin>>m;
    while(m--){
        cin>>n>>k;
        if(n<=46&&k>dp[n]){cout<<"-1\n";continue;}
        n=min(n,(ll)46);ck=1;
        dfs(n,k);
        if(ck) cout<<"-1\n";
    }
//    system("pause");
    return 0;
}
