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

int n,m,cnt[405],tmp[405];
bool ck(){
	REP1(i,1,n){
		if(cnt[i]<2) continue;
		for(int j=1;j<=n;++j) tmp[j]=cnt[j];
		tmp[i]-=2;
		bool c=1;
		REP1(j,1,n-2){
			tmp[j]%=3;
			if(tmp[j]<=tmp[j+1]&&tmp[j]<=tmp[j+2]){
				tmp[j+1]-=tmp[j];
				tmp[j+2]-=tmp[j];
				tmp[j]=0;
			}else{c=0;break;}
		}
		if(!(tmp[n]%3)&&!(tmp[n-1]%3)&&!(tmp[n-2]%2)&&c) return 1;
	}
	return 0;
}
int main(){Rosario
	cin>>n>>m;
	int x;
	REP(i,3*m+1) cin>>x,cnt[x]++;
	x=1;
	REP1(i,1,n){
		++cnt[i];
		if(ck()) cout<<i<<' ',x=0;
		--cnt[i];
	}
	if(x) cout<<"NO";
	return 0;
}
