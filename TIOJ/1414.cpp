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
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m,dx[]={1,1,1,0,0,-1,-1,-1},dy[]={0,1,-1,1,-1,-1,1,0};
char a[105][105],b[105][105];
void solve(int x,int y){
    queue<pii> q;q.emplace(mkp(x,y));
    int xx,yy;a[x][y]='0';
    while(q.size()){
        x=q.front().F,y=q.front().S;q.pop();
        REP(i,8){
            xx=x+dx[i],yy=y+dy[i];
            if(xx<0||xx>=n||yy<0||yy>=m||a[xx][yy]=='0') continue;
            a[xx][yy]='0';q.emplace(mkp(xx,yy));
        }
    }
}
int main(){Rosario
    while(cin>>n>>m){
        REP(i,n)
            REP(j,m){
                cin>>a[i][j];
                b[i][j]=(a[i][j]=='2'?'2':'0');
            }
        int cnta=0,cntb=0;
        REP(i,n)
            REP(j,m){
                if(a[i][j]=='2'){
                    cntb++;
                    queue<pii> q;q.emplace(mkp(i,j));
                    int x,y,xx,yy;a[i][j]='1';
                    while(q.size()){
                        x=q.front().F,y=q.front().S;q.pop();
                        REP(i,8){
                            xx=x+dx[i],yy=y+dy[i];
                            if(xx<0||xx>=n||yy<0||yy>=m||a[xx][yy]!='2') continue;
                            a[xx][yy]='1';q.emplace(mkp(xx,yy));
                        }
                    }
                }
            }
            REP(i,n)
            REP(j,m){
                if(a[i][j]=='1'){
                    cnta++;
                    queue<pii> q;q.emplace(mkp(i,j));
                    int x,y,xx,yy;a[i][j]='0';
                    while(q.size()){
                        x=q.front().F,y=q.front().S;q.pop();
                        REP(i,8){
                            xx=x+dx[i],yy=y+dy[i];
                            if(xx<0||xx>=n||yy<0||yy>=m||a[xx][yy]=='0') continue;
                            a[xx][yy]='0';q.emplace(mkp(xx,yy));
                        }
                    }
                }
            }
        cout<<cnta<<' '<<cntb<<"\n";
    }
//    system("pause");
    return 0;
}
