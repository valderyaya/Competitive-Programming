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

const ll mod=1e9+7;
ll f[1005][10][10],a[1005],len;
string l,r;
ll dfs(ll pos,ll prv,ll pprv,bool st,bool lmt){
	if(pos>len) return 1;
	if(!lmt&&prv!=-1&&pprv!=-1&&f[pos][prv][pprv]!=-1) return f[pos][prv][pprv];
	ll res=0,up=lmt?a[pos]:9;
	for(ll i=0;i<=up;++i){
		if(!st&&i!=prv&&i!=pprv) res+=dfs(pos+1,i,prv,0,lmt&&i==up),res%=mod;
		else if(st) res+=dfs(pos+1,(st&&i==0?-1:i),-1,st&&i==0,lmt&&i==up),res%=mod;
	}
	if(!lmt&&!st&&prv!=1&&pprv!=-1) f[pos][prv][pprv]=res;
	return res;
}
ll solve(){
	REP(i,l.size()) a[i+1]=l[i]-'0';
	memset(f,-1,sizeof(f)); len=l.size();
	ll x=dfs(1,-1,-1,1,1); --x;
	REP(i,r.size()) a[i+1]=r[i]-'0';
	len=r.size();
	ll y=dfs(1,-1,-1,1,1);
	REP1(i,1,l.size()-1){
		if(l[i]==l[i-1]){++x;break;}
		if(i>1&&l[i]==l[i-2]){++x;break;}
	}
	return (y-x)%mod;
}
int main(){Rosario
	cin>>l>>r;
	ll x=0,y=0;
	for(auto &i:l) x=(x*10+i-'0')%mod;
	for(auto &i:r) y=(y*10+i-'0')%mod;
	cout<<((y-x-solve()+1)%mod+mod)%mod<<"\n";	
	return 0;
}
