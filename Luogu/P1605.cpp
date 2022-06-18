// luogu-judger-enable-o2
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define sz(x) (sizeof(x)/sizeof(*x))
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);


int ma[6][6],ans=0,dx[]={1,0,0,-1},dy[]={0,1,-1,0},n,m,t;
void dfs(int x,int y){
    if(ma[x][y]==2){ans++;return;}
    REP(i,4){
        int xx=x+dx[i],yy=y+dy[i];
        if(xx<1||xx>n||yy<1||yy>m||ma[xx][yy]==1) continue;
        ma[x][y]=1;
        dfs(xx,yy);
        ma[x][y]=0;
    }
}
int main(){
    oi;
    int x,y,xx,yy;
    cin>>n>>m>>t>>x>>y>>xx>>yy;
    ma[xx][yy]=2;
    while(t--){
        cin>>xx>>yy;
        ma[xx][yy]=1;
    }
    dfs(x,y);
    cout<<ans<<"\n";
//    system("pause");
    return 0;
}
