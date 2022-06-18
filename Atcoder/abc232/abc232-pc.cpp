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
 
int x[10][10],y[10][10],v[10],n,m;
signed main(){Aincrad
	cin>>n>>m;
	for(int a,b,i=0;i<m;++i){
		cin>>a>>b;--a,--b;
		x[a][b]=x[b][a]=1;
	}
	for(int a,b,i=0;i<m;++i){
		cin>>a>>b;--a,--b;
		y[a][b]=y[b][a]=1;
	}
	for(int i=0;i<n;++i) v[i]=i;
	do{
		bool ck=1;
		REP(i,n) REP(j,n) if(x[i][j]!=y[v[i]][v[j]]){ck=0;break;}
		if(ck) return cout<<"Yes\n",0;
	}while(next_permutation(v,v+n));
	cout<<"No\n";
	return 0;
}
