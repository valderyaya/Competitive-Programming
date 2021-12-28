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
#define Aincrad ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
 
int n,q,seg[800050],m;
signed main(){Aincrad
	cin>>n>>q;
	for(m=1;m<n+2;m<<=1);
	REP1(i,m+1,m+n) cin>>seg[i];
	for(int i=m-1;i;--i) seg[i]=min(seg[i<<1],seg[i<<1|1]);
	for(int l,r,ret;q--;){
		cin>>l>>r;
		for(l+=m-1,r+=m+1,ret=1e9;l^r^1;l>>=1,r>>=1){
			if(~l&1) ret=min(ret,seg[l^1]);
			if(r&1) ret=min(ret,seg[r^1]);
		}
		cout<<ret<<"\n";
	}
	return 0;
}
