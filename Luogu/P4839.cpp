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

const int z=5e4+5;
struct qwq{
	int a[32];
	void ins(int x){
		for(int i=31;~i;--i)
			if(x>>i&1){
				if(a[i]) x^=a[i];
				else return a[i]=x,void();
			}
	}
	void ins(qwq &x){
		for(int i=31;~i;--i) if(x.a[i]) ins(x.a[i]);
	}
	int query(){
		int res=0;
		for(int i=31;~i;--i) res=max(res,res^a[i]);
		return res;
	}
}seg[z<<2],ans;
int n,m;
void mod(int l,int r,int x,int rt,int val){
	seg[rt].ins(val);
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid) mod(l,mid,x,rt<<1,val);
	else mod(mid+1,r,x,rt<<1|1,val);
}
void que(int l,int r,int ql,int qr,int rt){
	if(ql<=l&&r<=qr) return ans.ins(seg[rt]),void();
	int mid=l+r>>1;
	if(ql<=mid) que(l,mid,ql,qr,rt<<1);
	if(qr>mid) que(mid+1,r,ql,qr,rt<<1|1);
}
int main(){Rosario
	cin>>n>>m;
	for(int k,x,y;n;--n){
		cin>>k>>x>>y;
		if(k==1) mod(1,m,x,1,y);
		else{
			memset(ans.a,0,sizeof(ans.a));
			que(1,m,x,y,1);
			cout<<ans.query()<<"\n";
		}
	}
	return 0;
}
