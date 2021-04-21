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
const int z=1e6+5;
int mn=1e9,n,ans,b[z],w[z];
struct qwq{
	int id,pos;
}a[z];
bitset<z> vis;
 main(){Rosario
	cin>>n;
	REP1(i,1,n) cin>>w[i],mn=min(mn,w[i]);
	REP1(i,1,n) cin>>a[i].id,b[a[i].id]=i;
	REP1(i,1,n) cin>>a[i].pos,a[i].id=b[a[i].pos];
	REP1(i,1,n){
		if(!vis[i]){
			int k=a[i].id,p=w[a[i].pos],len=1,s=p;
			a[i].id=i; vis[i]=1;
			while(k!=i){
				p=min(p,w[a[k].pos]);
				++len, s+=w[a[k].pos];
				vis[k]=1;
				swap(a[k].id,k);
			}
			ans+=min((len-2)*p+s,p+(len+1)*mn+s);
		}
	}cout<<ans;
	return 0;
}
