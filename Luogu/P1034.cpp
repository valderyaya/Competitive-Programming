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

int n,m,ans=1e9;
pii pt[55];
struct qwq{
	int lx,rx,ly,ry;
	bool ck;
	void add(int x,int y){
		if(!ck) ck=1,lx=rx=x,ly=ry=y;
		else{
			if(x<lx) lx=x;
			else if(x>rx) rx=x;
			if(y<ry) ry=y;
			else if(y>ly) ly=y;
		}
	}
	bool in(int x,int y){
		return x>=lx&&x<=rx&&y>=ry&&y<=ly;
	}
	int area(){
		return (rx-lx)*(ly-ry);
	}
	bool operator*(qwq &t){
		if(!ck||!t.ck) return 0;
		return (t.in(lx,ly)||(t.in(lx,ry)||t.in(rx,ly)||t.in(rx,ry)));
	}
}a[5];
bool bom(){
	REP1(i,1,m) for(int j=i+1;j<=m;++j) if(a[i]*a[j]) return 0;
	return 1;
}
void dfs(int i,int sum){
	if(sum>ans) return;
	if(i==n) {
		if(bom()) ans=min(ans,sum);
		return ;
	}
	REP1(j,1,m){
		qwq tmp=a[j];
		a[j].add(pt[i+1].F,pt[i+1].S);
		dfs(i+1,sum-tmp.area()+a[j].area());
		a[j]=tmp;
	}
}
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) cin>>pt[i].F>>pt[i].S;
	dfs(0,0);
	cout<<ans<<"\n";
	return 0;
}
