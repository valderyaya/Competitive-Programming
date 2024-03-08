//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

struct qq{ll a[5],cnt=0;};
set<ll> s;
queue<qq> q;
ll hs(qq x){
	ll res=0;
	REP(i,5) res+=x.a[i],res*=51;
	return res;
}
void pb(qq x){
	if(!s.count(hs(x))){
		s.insert(hs(x));
		q.emplace(x);
	}
}
ll n,f[5],m,g=0,mx=0;
int main(){Rosario
    cin>>n;  qq x;
	REP(i,n) cin>>f[i],g=__gcd(g,f[i]),mx=max(mx,f[i]);
	cin>>m; REP(i,5) x.a[i]=0;
	if(m>mx||m%g) return cout<<"-1",0;
	q.emplace(x);
	while(!q.empty()){
		x=q.front(); q.pop();
		REP(i,n) if(x.a[i]==m) return cout<<x.cnt,0;
		REP(i,n){
			qq t=x; t.cnt++;
			if(t.a[i]>0) t.a[i]=0,pb(t);
			if(t.a[i]<f[i]) t.a[i]=f[i],pb(t);
			REP(j,5){
				if(i==j) continue;
				t=x; t.cnt++;
				ll tmp=f[j]-t.a[j],xx=min(tmp,t.a[i]);
				t.a[i]-=xx; t.a[j]+=xx;
				pb(t);
			}
		}
	}cout<<"-1";
    return 0;
}
