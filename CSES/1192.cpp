#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
#define mkp make_pair
 
int n,m,tot;
string s[1001];
void dfs(int x,int y){
    if(x<0||x>=n||y<0||y>=m||s[x][y]=='#') return;
    s[x][y]='#';
    dfs(x+1,y); dfs(x-1,y); dfs(x,y+1); dfs(x,y-1);
}
signed main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>s[i];
    REP(i,n) REP(j,m) if(s[i][j]=='.'){
        ++tot; dfs(i,j);
    }cout<<tot<<"\n";
}
