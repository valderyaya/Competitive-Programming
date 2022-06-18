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

bool ck(int x){
	int y=0,t=x;
	while(t) y=y*10+t%10,t/=10;
	return x==y;
}
vector<int> p;
bitset<10000005> is;
int a,b;
int main(){Rosario
	cin>>a>>b;
	b=min(b,10000000);
	for(int i=2;i<=b;++i){
		if(!is[i]) p.em(i);
		for(auto &j:p){
			if(i*j>b)break;
			is[i*j]=1;
			if(i%j==0) break;
		}
	}
	REP1(i,a,b) if(!is[i]&&ck(i)) cout<<i<<"\n";
	return 0;
}
