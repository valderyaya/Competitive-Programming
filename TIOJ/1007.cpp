//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

ll dp[100]={1},n,m;
int main(){Rosario
  cin>>n>>m;
	REP1(i,1,n) dp[i]=1<<i;
	for(int i=n;i<=m-1;++i) 
      for(int j=i;j>=i-n;--j) 
          dp[i+1]+=dp[j];
	cout<<dp[m]<<"\n";
    return 0;
}
