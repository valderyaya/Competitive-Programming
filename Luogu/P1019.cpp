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

int n,cnt[25],mx=0;
string s[25];
int cal(string &x,string &y){
	for(int i=1;i<min(x.size(),y.size());++i){
		bool ck=1;
		REP(j,i) if(x[x.size()-i+j]!=y[j]){ck=0;break;}
		if(ck) return i;
	}
	return 0;
}
void dfs(string now,int len){
	mx=max(mx,len);
	REP(i,n){
		if(cnt[i]>=2) continue;
		int x=cal(now,s[i]);
		if(x>0){
			++cnt[i];
			dfs(now+s[i],len+s[i].size()-x);
			--cnt[i];
		}
	}
}
int main(){Rosario
	cin>>n;
	REP(i,n+1) cin>>s[i];
	dfs(" "+s[n],s[n].size());
	cout<<mx<<"\n";
	return 0;
}
