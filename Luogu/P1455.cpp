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
#define wait system("pause");

int n,m,w,pa[10005],dp[10005],sum[10005],cost[10005];
int fin(int x){return x==pa[x]?x:pa[x]=fin(pa[x]);}
int main(){Rosario
    cin>>n>>m>>w;int a,b;
    REP1(i,1,n) pa[i]=i;
    REP1(i,1,n) cin>>cost[i]>>sum[i];
    REP(i,m){
        cin>>a>>b;
        a=fin(a),b=fin(b);
        if(a!=b) pa[a]=b;
    }
    REP1(i,1,n) 
        if(fin(i)!=i){
            sum[fin(i)]+=sum[i];
            cost[fin(i)]+=cost[i];
            sum[i]=cost[i]=0;
        }
    REP1(i,1,n) for(int j=w;j>=cost[i];j--) dp[j]=max(dp[j],dp[j-cost[i]]+sum[i]);
    cout<<dp[w]<<"\n";
//   system("pause");
    return 0;
}
