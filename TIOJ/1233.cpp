//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
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

int n,m,dx[]={1,1,1,0,0,-1,-1,-1},dy[]={1,0,-1,1,-1,1,0,-1},sum=0;
char a[520][520];
void bfs(int x,int y){
    queue<pii> q;q.emplace(mkp(x,y));
    int xx,yy;
    while(q.size()){
        x=q.front().F,y=q.front().S;q.pop();
        REP(i,8){
            xx=x+dx[i],yy=y+dy[i];
            if(xx<0||xx>=n||yy<0||y>=m||a[xx][yy]=='#'||a[xx][yy]=='0') continue;
            a[xx][yy]='#';q.emplace(mkp(xx,yy));
        }
    }
}
int main(){//Rosario
    cin>>n>>m;
    REP(i,n) REP(j,m) cin>>a[i][j];
    REP(i,n) REP(j,m){
        if(a[i][j]=='1'){
            sum++;
            bfs(i,j);
        }
    }
    if(sum==0) cout<<0;
    else if(sum==1) cout<<1;
    else if(sum==2) cout<<2;
    else if(sum<=4) cout<<3;
    else if(sum<=6) cout<<4;
    else if(sum<=10) cout<<5;
    else if(sum<=12) cout<<6;
    else if(sum<=14) cout<<7;
    else if(sum<=16) cout<<8;
    else if(sum<=18) cout<<9;
    else cout<<10;
    cout<<"\n";
//    system("pause");
    return 0;
}
