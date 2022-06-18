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

const int z=1e5+505;
int cnt,pri[z],sz[z],ch[2][z],n,m,q,rt;
string val[z];
int node(string s){
	val[++cnt]=s;
	pri[cnt]=rand();
	sz[cnt]=1;
	return cnt;
}
void up(int x){sz[x]=sz[ch[0][x]]+sz[ch[1][x]]+1;}
int merge(int a,int b){
	if(!a||!b) return a+b;
	if(pri[a]<pri[b]){
		ch[1][a]=merge(ch[1][a],b);
		return up(a),a;
	}else{
		ch[0][b]=merge(a,ch[0][b]);
		return up(b),b;
	}
}
void split(int p,int &a,int &b,int k){
	if(!p) return a=b=0,void();
	if(sz[ch[0][p]]+1<=k){
		a=p;
		split(ch[1][p],ch[1][a],b,k-sz[ch[0][p]]-1);
	}else{
		b=p;
		split(ch[0][p],a,ch[0][b],k);
	}
	up(p);
}
string s;
void ins(int x){
	int a,b;
	split(rt,a,b,x);
	rt=merge(a,merge(node(s),b));
}
string que(int p,int x){
	if(sz[ch[0][p]]+1==x) return val[p];
	if(sz[ch[0][p]]+1>x) return que(ch[0][p],x);
	return que(ch[1][p],x-sz[ch[0][p]]-1);
}
// void print(int p){
// 	if(!p) return;
// 	print(ch[0][p]);
// 	cout<<val[p]<<endl;
// 	print(ch[1][p]);
// }
int main(){Rosario
	srand(time(0));
	cin>>n;
	while(n--){
		cin>>s;
		rt=merge(rt,node(s));
	}
	int x;
	cin>>m;
	while(m--){
		cin>>s>>x;
		ins(x);
	}
	//print(rt);
	cin>>q;
	while(q--){
		cin>>x;++x;
		cout<<que(rt,x)<<"\n";
	}
	return 0;
}
