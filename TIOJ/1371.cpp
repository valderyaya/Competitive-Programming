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
pii operator-(pii a,pii b){return mkp(a.F-b.F,a.S-b.S);}
int cross(pii a,pii b){return a.F*b.S-a.S*b.F;}
int ori(pii a,pii b,pii c){
	int x=cross(b-a,c-a);
	if(x==0) return 0;
	return x>0?1:-1;
}
struct qq{
	pii a;
	int id;
	bool operator<(const qq &x)const{return  a.F==x.a.F?a.S<x.a.S:a.F<x.a.F;}
}pt[100005],st[100005];
bool cmp(qq a,qq b){return a.id<b.id;}
int n,idx=0,idx2;
main(){Rosario
	cin>>n;
	REP(i,n) cin>>pt[i].a.F>>pt[i].a.S,pt[i].id=i+1;
	sort(pt,pt+n);
	REP(i,n){
		while(idx>1&&ori(st[idx-2].a,st[idx-1].a,pt[i].a)<=0) --idx;
		st[idx++]=pt[i];
	}
	idx2=idx;
	for(int i=n-1;i>=0;--i){
		while(idx2>idx&&ori(st[idx2-2].a,st[idx2-1].a,pt[i].a)<=0) --idx2;
		st[idx2++]=pt[i];
	}
	sort(st,st+idx2-1,cmp);
	cout<<idx2-1<<"\n";
	REP(i,idx2-1) cout<<st[i].id<<"\n";
	return 0;
}
