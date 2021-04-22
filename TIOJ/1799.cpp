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

const int z=5000005;
ll n,a[z],s[z],sum=0,m;
int main(){Rosario
	cin>>n; m=n/2+1;
	REP1(i,1,n) cin>>a[i],sum+=a[i];
	sum/=n;
	REP1(i,1,n) a[i]-=sum,s[i]=s[i-1]+a[i];
	sort(s+1,s+1+n); sum=0;
	REP1(i,1,n) sum+=abs(s[m]-s[i]);
	cout<<sum;
	return 0;
}
