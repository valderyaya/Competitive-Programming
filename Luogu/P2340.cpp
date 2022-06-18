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
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,f[800005];
int main(){Rosario
	cin>>n;
	memset(f,-125,sizeof(f));
	f[400000]=0;
	for(int x,y,i=0;i<n;++i){
		cin>>x>>y;
		if(x>=0){
			for(int j=800000;j>=x;--j) f[j]=max(f[j],f[j-x]+y);
		}else{
			for(int j=0;j<=800000+x;++j) f[j]=max(f[j],f[j-x]+y);
		}
	}int ans=0;
	REP1(i,400000,800000) if(f[i]>=0) ans=max(ans,f[i]+i-400000);
	cout<<ans;
	return 0;
}
