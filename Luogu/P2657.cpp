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

int l,r,a[12],i;
ll f[12][10],R,L;
ll dfs(int pos,int prv,int st,int limit){
	if(pos>i) return 1;
	if(!limit&&f[pos][prv]!=-1) return f[pos][prv];
	ll res=0,up=limit?a[i-pos+1]:9;
	for(int j=0;j<=up;++j){
		if(abs(j-prv)<2) continue;
		if(st&&j==0) res+=dfs(pos+1,-2,1,limit&&(j==up));
		else res+=dfs(pos+1,j,0,limit&&(j==up));
	}
	if(!st&&!limit) f[pos][prv]=res;
	return res;
}
ll solve(int x){
	for(i=0;x;x/=10) a[++i]=x%10;
	memset(f,-1,sizeof(f));
	return dfs(1,-2,1,1);
}
int main(){Rosario
	cin>>l>>r;
	L=solve(l-1),R=solve(r);
	cout<<R-L<<"\n";
	return 0;
}
