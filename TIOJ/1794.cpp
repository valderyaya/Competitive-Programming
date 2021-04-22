#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define F first
#define S second
#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m,a[3001][3001],mx=0,cnt,dx[]={1,0,0,-1},dy[]={0,1,-1,0};
int main(){Rosario
    cin>>n>>m;
    REP(i,n) REP(j,m) cin>>a[i][j];
    REP(i,n){
        REP(j,m){
            if(a[i][j]!=-1){
                queue<pii> q;q.emplace(mkp(i,j));cnt=0;
                int x,y,xx,yy,t=a[i][j];a[i][j]=-1;
                while(q.size()){cnt++;
                    x=q.front().F,y=q.front().S;q.pop();
                    REP(i,4){
                        xx=x+dx[i],yy=y+dy[i];
                        if(xx<0||xx>=n||yy<0||yy>=m||a[xx][yy]==-1||a[xx][yy]!=t) continue;
                        q.emplace(mkp(xx,yy));a[xx][yy]=-1;
                    }
                }mx=max(mx,cnt);
            }
        }
    }cout<<mx<<"\n";
//    system("pause");
    return 0;
}
