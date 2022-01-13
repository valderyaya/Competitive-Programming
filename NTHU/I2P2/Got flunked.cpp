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

#define _int __int128
void write(_int x){
	if(!x) return ;
	write(x/10);
	putchar('0'+x%10);
}
void print (_int x){
	if(x==(_int)1<<126) return puts("-1"),void();
	if(x<0) cout<<'-';
	write(x<0?-x:x);
	cout<<"\n";
}
_int cal(_int x,ll y){
	return (2*x+1)*(x+((_int)1<<y)-1);
}
ll n,t;
signed main(){//Aincrad
	scanf("%lld",&t);
	while(t--){
		scanf("%lld",&n);
		_int mid,l,r,ans=((_int)1<<126); 
		REP1(i,0,63){
			l=-1,r=(_int)1<<60;
			while(r-l>1){
				mid=(l+r)/2;
				if(cal(mid,i)>=n) r=mid;
				else l=mid;
			}
			if(cal(r,i)==n && (((_int)2*r+1)<<i) < ans)
				ans=(((_int)2*r+1)<<i);
		}
		print(ans);
	}
	return 0;
}
