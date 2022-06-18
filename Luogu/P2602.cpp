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

ll l,r,f[15][15],a[15],len;
ll dfs(ll pos,ll sum,bool st,bool limit,ll d){
	if(pos>len) return sum;
	if(!limit&&f[pos][sum]!=-1) return f[pos][sum];
	ll res=0,up=limit?a[len-pos+1]:9;
	for(ll i=0;i<=up;++i) res+=dfs(pos+1,sum+((i==d)&&(!st||i)),st&&(i==0),limit&&(i==up),d);
	if(!limit&&!st) f[pos][sum]=res;
	return res;
}
ll solve(ll x,int d){
	for(len=0;x;x/=10) a[++len]=x%10;
	memset(f,-1,sizeof(f));
	return dfs(1,0,1,1,d);
}
int main(){Rosario
	cin>>l>>r;
	REP1(i,0,9) cout<<solve(r,i)-solve(l-1,i)<<" \n"[i==9];
	return 0;
}
