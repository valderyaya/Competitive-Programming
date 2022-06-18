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
#define int ll
const int z=1e6+5;
int v[z],w[z],n,in[z],f[z],g[z],ans;
queue<int> q;
int cal(int x){
	int rt=x,m1=f[x],m2=f[x],sum=w[x],r1=g[x],r2=-1e9;
	for(x=v[x];x!=rt;in[x]=0,sum+=w[x],x=v[x]){
		r1=max({r1,f[x]+sum+m1,g[x]});
		r2=max(r2,f[x]-sum+m2);
		m1=max(m1,f[x]-sum);
		m2=max(m2,f[x]+sum);
	}
	return max(r1,r2+sum);
}
main(){Rosario
	cin>>n;
	REP1(i,1,n) cin>>v[i]>>w[i],++in[v[i]];
	REP1(i,1,n) if(in[i]==0) q.emplace(i);
	while(!q.empty()){
		int x=q.front(),val=f[x]+w[x]; q.pop();
		g[v[x]]=max({g[v[x]],f[v[x]]+val,g[x]});
		f[v[x]]=max(f[v[x]],val);
		if(--in[v[x]]==0) q.emplace(v[x]);
	}
	REP1(i,1,n) if(in[i]) ans+=cal(i);
	cout<<ans;
	return 0;
}
