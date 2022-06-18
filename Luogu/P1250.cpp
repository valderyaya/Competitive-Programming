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

const int z=5e3+5;
int n,m,b[30005],cnt;
bitset<30005> vis;
void add(int x,int v){
	for(;x<=n;x+=lb(x)) b[x]+=v;
}
int que(int x){
	int res=0;
	for(;x;x-=lb(x)) res+=b[x];
	return res;
}
struct qwq{
	int l,r,x;
	bool operator<(const qwq &a){return r==a.r?l>a.l:r<a.r;}
}a[z];
int main(){Rosario
	cin>>n>>m;
	REP(i,m) cin>>a[i].l>>a[i].r>>a[i].x;
	sort(a,a+m);
	REP(i,m){
		int x=a[i].x-(que(a[i].r)-que(a[i].l-1));
		if(x>0){
			for(int j=a[i].r;x&&j>=a[i].l;--j) if(!vis[j]) vis[j]=1,add(j,1),++cnt,--x;
		}
	}
	cout<<cnt;
	return 0;
}
