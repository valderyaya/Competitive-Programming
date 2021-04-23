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

ll a,b,c,t;
int main(){Rosario
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		if(a>b) swap(a,b);
		if(a>c) swap(a,c);
		if(b>c) swap(b,c);
		if(a==1&&b==1&&c==1) cout<<"Second\n";
		else if(a==1&&b==1) cout<<"First\n";
		else{
			--a,--b,--c;
			if((a^c^b)==0) cout<<"Second\n";
			else cout<<"First\n";
		}
	}
	return 0;
}
