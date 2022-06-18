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

struct qq{
	int a,b,id;
	bool operator<(const qq &x){return a==x.a?b>x.b:a<x.a;}
}a[50005];
int n,ans[50005],st[50005],top=0;
double sp(int i,int j){return (double)(a[j].b-a[i].b)/(double)(a[i].a-a[j].a);}
int main(){Rosario
	cin>>n;
	REP(i,n) cin>>a[i].a>>a[i].b,a[i].id=i;
	sort(a,a+n);
	REP(i,n){
		if(i!=0&&a[i].a==a[i-1].a) continue;
		while(top>1&&sp(st[top],i)<=sp(st[top-1],st[top])) --top;
		st[++top]=i;
		ans[top]=a[i].id;
	}
	sort(ans+1,ans+1+top);
	REP1(i,1,top) cout<<ans[i]+1<<' ';
	return 0;
}
