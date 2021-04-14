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

const int z=1e5+5;
struct qq{
	int l,r,c;
	bool operator<(const qq &x)const{return r<x.r;}
}a[z];
int n,b[z],m[z];
void add(int x){for(;x<z;x+=lb(x))b[x]++;}
int que(int x){
	int res=0;
	for(;x;x-=lb(x)) res+=b[x];
	return res;
}
int main(){Rosario
	while(cin>>n,n){int ans=0;
		REP(i,n) cin>>a[i].l>>a[i].r>>a[i].c,++a[i].l,++a[i].r;
		sort(a,a+n); memset(b,0,sizeof(b)); memset(m,0,sizeof(m));
		REP(i,n){
			int k=a[i].c-(que(a[i].r)-que(a[i].l));
			for(int j=a[i].r;j>a[i].l&&k>0;--j) if(!m[j]){
				m[j]=1; add(j); ++ans; --k; 
			}
		}cout<<ans<<"\n";
	}
	return 0;
}
