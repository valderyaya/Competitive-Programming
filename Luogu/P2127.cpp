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

#define int ll
const int z=1e5+5;
int mn=1e9,n,ans;
struct qwq{
	int x,id;
	bool operator<(const qwq &a){return x<a.x;}
}a[z];
 main(){Rosario
	cin>>n;
	REP1(i,1,n) cin>>a[i].x,a[i].id=i,mn=min(mn,a[i].x);
	sort(a+1,a+1+n);
	REP1(i,1,n){
		if(a[i].id!=i){
			int k=a[i].id,p=a[i].x,len=1,s=a[i].x;
			a[i].id=i;
			while(k!=i){
				p=min(p,a[k].x);
				++len, s+=a[k].x;
				swap(a[k].id,k);
			}
			ans+=min((len-2)*p+s,p+(len+1)*mn+s);
		}
	}cout<<ans;
	return 0;
}
