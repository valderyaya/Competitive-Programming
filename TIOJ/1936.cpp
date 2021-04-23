#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

ll t,n,a[1025][1025],b[1025][1025],c[1025][1025],d[1025];
void violet(ll a[][1025],ll b[],ll c[]){
	for(int i=0;i<n;++i)
		REP(j,n) c[i]+=a[i][j]*b[j];
}
bool evergarden(ll a[],ll b[]){
	REP(i,n) if(a[i]!=b[i]) return 0;
	return 1;
}

int main(){Rosario
    cin>>t; srand(time(0));
	while(t--){
		cin>>n;
		REP(i,n) REP(j,n) cin>>a[i][j];
		REP(i,n) REP(j,n) cin>>b[i][j];
		REP(i,n) REP(j,n) cin>>c[i][j];
		bool ck=1;
		REP(i,5) {
			REP(j,n) d[j]=rand()%10000;
			ll ta[1025]={};
			violet(b,d,ta);
			ll tb[1025]={};
			violet(a,ta,tb);
			ll tc[1025]={};
			violet(c,d,tc);
			if(!evergarden(tb,tc)){ck=0;break;}
		}
		cout<<(ck?"Loli is god.":"QAQ!")<<"\n";
	}
    return 0;
}
