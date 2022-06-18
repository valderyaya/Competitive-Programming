//https://www.luogu.com.cn/problem/AT4501

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

int l,r,n,ans,a[200005];
int main(){Rosario
	cin>>n;
	REP(i,n) cin>>a[i];
	sort(a,a+n);
	for(int k=1<<30;k;k>>=1){
		l=0,r=n-1;
		while(l<r){
			if(!~a[l]||(~a[r]&&a[l]+a[r]<k)) ++l;
			else if(!~a[r]||a[l]+a[r]>k) --r;
			else ++ans,a[l]=a[r]=-1;
		}
	}
	cout<<ans<<"\n";
	return 0;
}
