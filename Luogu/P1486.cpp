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

const int z=1e5+5;
int val[z],ch[z][2],cnt,sz[z],pri[z],rt,det,ans,n,mn;
int node(int x){
	val[++cnt]=x;
	sz[cnt]=1;
	pri[cnt]=rand();
	return cnt;
}
void up(int x){
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+1;
}
int merge(int a,int b){
	if(!a||!b) return a|b;
	if(pri[a]<pri[b]){
		ch[a][1]=merge(ch[a][1],b);
		up(a); return a;
	}else{
		ch[b][0]=merge(a,ch[b][0]);
		up(b); return b;
	}
}
void split(int p,int &a,int &b,int k){
	if(!p) return a=b=0,void();
	if(val[p]<=k){
		a=p;split(ch[p][1],ch[a][1],b,k);
	}else{
		b=p;split(ch[p][0],a,ch[b][0],k);
	}up(p);
}
void ins(int x){
	int a,b;
	x-=det;
	split(rt,a,b,x);
	rt=merge(a,merge(node(x),b));
}
void sub(int x){
	int a,b;
	det-=x;
	split(rt,a,b,mn-det-1);
	ans+=sz[a];
	rt=b;
}
int que(int p,int x){
	if(sz[ch[p][0]]+1==x) return val[p];
	if(sz[ch[p][0]]>=x) return que(ch[p][0],x);
	return que(ch[p][1],x-sz[ch[p][0]]-1); 
}
// void print(int x){
// 	if(!x) return;
// 	print(ch[x][0]);
// 	cout<<val[x]<<' ';
// 	print(ch[x][1]);
// }
int main(){Rosario
	srand(76842);
	cin>>n>>mn;
	int x;
	for(char c;n;--n){
		cin>>c>>x;
		if(c=='I'&&x>=mn) ins(x);
		else if(c=='A') det+=x;
		else if(c=='S') sub(x);
		else if(c=='F'){
			if(x>sz[rt]) cout<<"-1\n";
			else cout<<que(rt,sz[rt]-x+1)+det<<"\n";
		}
	}cout<<ans;
	return 0;
}
