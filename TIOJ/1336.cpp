#include<bits/stdc++.h>
// #include<ext/rope>
// using namespace __gnu_cxx;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define pii pair<int,int>
typedef long long ll;
#define mkp make_pair
#define em emplace_back
#define F first
#define S second
#define ALL(x) (x).begin(),(x).end()
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define pll pair<ll,ll>
//#define lb(x) (x&-x)

int n,m,dx[]={1,1,1,0,0,-1,-1,-1},dy[]={1,0,-1,1,-1,1,0,-1},a=0,b=0;
char ma[105][105],now;
bool vis[105][105];
queue<pii> q;
int main(){//Rosario
    cin>>n>>m;
    REP(i,m) REP(j,n) cin>>ma[i][j];
    REP(i,m) REP(j,n){
        if(!vis[i][j]&&(ma[i][j]=='-'||ma[i][j]=='G')){
            now=ma[i][j];q.emplace(mkp(i,j));vis[i][j]=1;
            if(now=='G') a++;
            else b++;
            while(!q.empty()){
                int x=q.front().F,y=q.front().S,xx,yy;q.pop();
                REP(k,8){
                    xx=x+dx[k],yy=y+dy[k];
                    if(xx<0||xx>=m||yy<0||yy>=n||vis[xx][yy]||ma[xx][yy]!=now) continue;
                    vis[xx][yy]=1;q.emplace(mkp(xx,yy));
                }
            }
        }
    }cout<<a<<' '<<b<<"\n";
//    system("pause");
    return 0;
}
