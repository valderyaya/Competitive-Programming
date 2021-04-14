#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second

int a,b,c,x,y,cnt=0;
bool ma[10001][10001]={};
void dfs(int x,int y){
	if(x<1||x>a||y<1||y>b||ma[x][y]==false) return;
	ma[x][y]=0;
	dfs(x+1,y);dfs(x+1,y+1);dfs(x+1,y-1);dfs(x,y+1);dfs(x,y-1);dfs(x-1,y);dfs(x-1,y-1);dfs(x-1,y+1);
	dfs(x+2,y);dfs(x+2,y+1);dfs(x+2,y+2);dfs(x+2,y-1);dfs(x+2,y-2);dfs(x+1,y+2);dfs(x+1,y-2);
	dfs(x,y+2);dfs(x,y-2);dfs(x-1,y+2);dfs(x-1,y-2);dfs(x-2,y);dfs(x-2,y-1);dfs(x-2,y-2);dfs(x-2,y+1);
	dfs(x-2,y+2);
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>a>>b>>c;
	while(c--){
		cin>>x>>y;
		ma[x][y]=1;
	}
	REP1(i,1,a){
		REP1(j,1,b){
			if(ma[i][j]){
				cnt++;
				dfs(i,j);
			}
		}
	}
	cout<<cnt<<"\n";
//    system("pause");
	return 0;
}
