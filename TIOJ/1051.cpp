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
#define lb(x) (x&-x)


struct qwq{
	int x,y,v;
	bool operator<(const qwq &a)const{return x<a.x&&y<a.y&&v>a.v;}
}c[550];
int id,prv[550],f[550],mx,pos,t,n,a[2][550];
void print(int x){
	if(!~x) return;
	print(prv[x]);
	cout<<c[x].v<<' ';
}
signed main(){Rosario
	cin>>t;
	while(t--){
		cin>>n;  id=pos=0; mx=-1;
		memset(f,0,sizeof(f));
		memset(prv,-1,sizeof(prv));
		REP(i,2) REP(j,n) cin>>a[i][j];
		REP(i,n) REP(j,n) if(a[0][i]==a[1][j]){ c[id++]=qwq{i,j,a[0][i]}; break;}
		REP(i,id) REP(j,i) if(c[j]<c[i]&&f[j]+1>f[i]){
			f[i]=f[j]+1;
			prv[i]=j;
			if(f[i]>mx) mx=f[i],pos=i;
		}
		if(id) print(pos); 
		cout<<"\n";
	}
	return 0;
}
