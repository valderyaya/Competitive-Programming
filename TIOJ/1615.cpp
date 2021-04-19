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

const int z=1000000;
bitset<1000005> v;
vector<int> p;
void init(){
	for(int i=2;i<z;++i){
		if(!v[i]) p.em(i);
		for(auto &j:p){
			if(i*j>z) break;
			v[i*j]=1;
			if(i%j==0)break;
		}
	}
}

int main(){Rosario
	init();
	int cnt,n,m;
	while(cin>>n>>m){cnt=0;
		if(n>m) swap(n,m);
		cnt=upper_bound(ALL(p),n)-p.begin();
		ll x=1; for(int i=n+1;i<=m;++i) x*=i;
		++x;
		REP(i,cnt) while(x%p[i]==0) x/=p[i];
		for(int i=cnt;i<p.size()&&x>1;++i) if(x%p[i]==0){
			++cnt;
			while(x%p[i]==0) x/=p[i];
		}
		cout<<cnt+(x>z?1:0)<<"\n";
	}
	return 0;
}
