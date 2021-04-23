//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

#define int ll
struct qq{
	int val,df,id;
	bool operator<(const qq &x)const{
		return df<x.df;
	}
}a[5005];
int id[5005],n,m,dp[5005]={},mx=0;
 main(){Rosario
	cin>>n>>m;
	REP1(i,1,m) cin>>id[i];
	REP1(i,1,n) cin>>a[i].val>>a[i].df>>a[i].id;
	sort(a+1,a+1+n);
	REP1(i,1,n){
		for(int j=i-1;~j;--j) dp[i]=max(dp[i],dp[j]+a[i].val-(a[i].id==a[j].id?id[a[i].id]:0));
		mx=max(mx,dp[i]);
	}cout<<mx;
	return 0;
}
