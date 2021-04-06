//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

int n,m,a[10][10],ans;
void cg(int x,int y){
	if(x<0||x>=n||y<0||y>=m) return;
	a[x][y]^=1;
}
void pes(int x,int y){cg(x,y);cg(x-1,y);cg(x+1,y);cg(x,y-1);cg(x,y+1);}
void dfs(int x,int y,int cnt){
	if(y==m){
		bool c=1;
		++x,y=0;
		if(x==n){
			REP(i,m) if(a[x-1][i]){c=0;break;}
			if(c) ans=min(ans,cnt);
			return;
		}
	}
	if(x==0){
		dfs(x,y+1,cnt);
		pes(x,y);
		dfs(x,y+1,cnt+1);
		pes(x,y);
	}else if(x==n-1&&y&&a[x][y-1]!=a[x-1][y]){
		return;
	}else{
		if(a[x-1][y]){
			pes(x,y);
			dfs(x,y+1,cnt+1);
			pes(x,y);
		}else dfs(x,y+1,cnt);
	}
}
string s[10];
int main(){Rosario
    while(getline(cin,s[0])){
		if(s[0]=="#") break;
		n=1, m=s[0].size(); ans=1e9;
		while(getline(cin,s[n]),s[n]!="") ++n;
		REP(i,n) REP(j,m) a[i][j]=s[i][j]=='O';
		//REP(i,n) REP(j,m) cout<<a[i][j]<<" \n"[j==m-1];
		dfs(0,0,0);
		if(ans==1e9) cout<<"Another Skeleton in the Ancient Tomb!\n";
		else cout<<"Minimum Steps : "<<ans<<"\n";
	}
    return 0;
}
