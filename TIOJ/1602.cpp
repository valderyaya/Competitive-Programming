//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define Rosario ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

int st,sd,n,m,a[1505][1505],dx[]={1,0,0,-1},dy[]={0,1,-1,0},x,xx,y,yy;
set<pii> s;
queue<pii> q;
bool vis[1505][1505]={};
int main(){Rosario
    cin>>n>>m;
    REP(i,n) REP(j,m) cin>>a[i][j];
    cin>>st>>sd;q.emplace(mkp(sd,st));vis[sd][st]=1;
    while(q.size()){
        x=q.front().F,y=q.front().S;q.pop();s.insert(mkp(y,x));
        REP(i,4){
            xx=x+dx[i],yy=y+dy[i];
            if(xx<0||xx>=n||yy<0||yy>=m||vis[xx][yy]||a[xx][yy]<a[x][y]) continue;
            q.emplace(mkp(xx,yy));vis[xx][yy]=1;
        }
    }
    for(pii i:s) cout<<'('<<i.F<<','<<i.S<<")\n";
    
//    system("pause");
    return 0;
}
