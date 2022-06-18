#include<bits/stdc++.h>
#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m,mx=0,a[105][105]={},cnt[105][105]={},xx,yy,dx[]={1,0,0,-1},dy[]={0,1,-1,0};
int dfs(int x,int y){
    if(cnt[x][y]) return cnt[x][y];
    cnt[x][y]=1;
    REP(i,4){
        xx=x+dx[i],yy=dy[i]+y;
        if(xx<0||yy<0||xx>=n||yy>=m||a[x][y]<=a[xx][yy]) continue;
        cnt[x][y]=max(cnt[x][y],dfs(xx,yy)+1);
    }
    return cnt[x][y];
}
int main(){Rosario
    cin>>n>>m;
    REP(i,n) REP(j,m) cin>>a[i][j];
    REP(i,n) REP(j,m) mx=max(mx,dfs(i,j));
    cout<<mx<<"\n";
//    system("pause");
    return 0;
}
