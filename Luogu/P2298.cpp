//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
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
#define lb(x) (x&-x)
#define wait system("pause");

int n,m,a[2001][2001],dx[]={1,0,0,-1},dy[]={0,1,-1,0};
char aa[2001][2001];
pii st,ed;
void solve(){
    queue<pii> q;
    q.emplace(st);
    while(!q.empty()){
        pii x=q.front();q.pop();
        if(x==ed) return cout<<a[x.F][x.S],void();
        REP(i,4){
            int xx=x.F+dx[i],yy=x.S+dy[i];
            if(xx<0||xx>=n||yy<0||yy>=m||aa[xx][yy]=='#'||a[xx][yy]) continue;
            q.emplace(mkp(xx,yy)); a[xx][yy]=a[x.F][x.S]+1;
        }
    }
    cout<<"No Way!";
}
int main(){Rosario
    cin>>n>>m;
    REP(i,n) REP(j,m){
        cin>>aa[i][j];
        if(aa[i][j]=='m') st=mkp(i,j);
        else if(aa[i][j]=='d') ed=mkp(i,j);
    }
    solve();
    return 0;
}
