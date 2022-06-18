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

const double eps=1e-2;
int n,m,pa[1005],cnt;
pii a[1005];
struct qwq{
	int x,y;
	double dis;
	bool operator<(const qwq &p){return dis<p.dis;}
};
vector<qwq> v;
int fin(int x){return pa[x]==x?x:pa[x]=fin(pa[x]);}
void un(int x,int y){
	pa[x]=y,--cnt;
}
double cal(int i,int j){
	return sqrt((a[i].F-a[j].F)*(a[i].F-a[j].F)+(a[i].S-a[j].S)*(a[i].S-a[j].S));
}
void solve(){
	sort(ALL(v));
	for(auto &i:v){
		int x=fin(i.x),y=fin(i.y),z=(cnt==m);
		if(x!=y){
			un(x,y);
			if(z) return cout<<fixed<<setprecision(2)<<i.dis<<"\n",void();
		}
	}
}
int main(){Rosario
	cin>>n>>m; cnt=n;
	REP1(i,1,n) cin>>a[i].F>>a[i].S;
	REP1(i,1,n){
		pa[i]=i;
		REP1(j,1,i-1) v.em(qwq{i,j,cal(i,j)});
	}
	solve();
	return 0;
}
