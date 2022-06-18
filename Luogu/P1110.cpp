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

const int z=5e5+5;
int n,m,st[z],ed[z],ans=1e9;
multiset<int> det,s;
void cal(int x){
	if(!s.empty()){
		auto it=s.upper_bound(x);
		if(it!=s.end()) ans=min(ans,abs(*it-x));
		if(it!=s.begin()) ans=min(ans,abs(*prev(it)-x));
	}
	s.insert(x);
}
void rd(int &x){
	x=0;char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
}
char str[z];
int main(){//Rosario
	rd(n),rd(m);
	int x,y;
	REP1(i,1,n){
		rd(x);
		st[i]=ed[i]=x;
		cal(x);
		if(i!=1)det.insert(abs(st[i]-st[i-1]));
	}
	while(m--){
		scanf("%s",str);
		if(str[4]=='R'){
			rd(x),rd(y);
			if(x!=n){
				auto it=det.lower_bound(abs(ed[x]-st[x+1]));
				det.erase(it);
				det.insert(abs(y-st[x+1]));
			}
			det.insert(abs(ed[x]-y));
			ed[x]=y;
			cal(y);
		}else if(str[4]=='G'){
			printf("%d\n",*det.begin());
		}else{
			printf("%d\n",ans);
		}
	}
	return 0;
}
