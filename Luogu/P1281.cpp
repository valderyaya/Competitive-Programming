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

int n,m,a[505],r,l=1e9;
bool ck(int mid){
	int x=0,c=0;
	for(int i=n;i;--i){
		if(i==1) ++c;
		if(x+a[i]>mid) ++c,x=a[i];
		else x+=a[i];
	}
	return c<=m;
}
void print(int l,int r,int k){
	int x=0;
	for(int i=r;i>=l;--i)
		if(x+a[i]>k){
			print(l,i,k);
			cout<<i+1<<' '<<r<<'\n';
			return;
		}else x+=a[i];
	cout<<"1 "<<r<<'\n';
}
int main(){Rosario
	cin>>n>>m;
	REP1(i,1,n) cin>>a[i],r+=a[i],l=min(l,a[i]);
	while(l<r){
		int mid=l+r>>1;
		if(ck(mid)) r=mid;
		else l=mid+1;
	}
	print(1,n,l);
	return 0;
}
