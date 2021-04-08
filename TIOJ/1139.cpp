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

int t,n,a[1005],f[1005][1005];
int dfs(int l,int r){
	if(l>=r) return 0;
	if(f[l][r]!=-1) return f[l][r];
	int mx=0;
	for(int i=l+1;i<=r;i+=2)
		mx=max(mx,dfs(l+1,i-1)+dfs(i+1,r)+(a[l]==a[i]));
	return f[l][r]=mx;
}
int main(){Rosario
	cin>>t;
	while(t--){
		cin>>n;
		memset(f,-1,sizeof(f));
		REP1(i,1,n) cin>>a[i];
		if(n<=2){
			if(n==1) cout<<"0\n";
			else cout<<(a[1]==a[2])<<"\n";
			continue;
		}
		cout<<dfs(1,n)<<"\n";
	}
	return 0;
	
}
