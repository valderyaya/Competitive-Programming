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
//#define lb(x) (x&-x)
//#define line cout<<"-------------------------\n";

const int inf=1e9;
int n,m,a[55][55]={},sx,sy,ex,ey,fw,dx[]={-1,0,1,0},dy[]={0,1,0,-1};
struct qq{int x,y,f,t;};
bool out(int x,int y){return x<1||x>=n||y<1||y>=m;}
bool beat(int x,int y){return (a[x+1][y]||a[x][y]||a[x][y+1]||a[x+1][y+1]);}
int hash_(int x,int y,int k){return x*2600+y*55+k;}
bitset<200000> vis;
void bfs(){
    queue<qq> q;
    q.emplace(qq{sx,sy,fw,0});
    int x,y,t,f;
    while(!q.empty()){
        qq p=q.front(); q.pop();
        if(p.x==ex&&p.y==ey){cout<<p.t; exit(0);}
        x=hash_(p.x,p.y,p.f);
        if(vis[x]) continue;
        vis[x]=1;  t=p.t+1; 
        f=(p.f+3)%4;
        q.emplace(qq{p.x,p.y,f,t});
        f=(p.f+5)%4;  
        q.emplace(qq{p.x,p.y,f,t});
        f=p.f;
        REP1(i,1,3){
            x=p.x+dx[f]*i,y=p.y+dy[f]*i;
            if(out(x,y)||beat(x,y)) break;
            q.emplace(qq{x,y,f,t});
        }
    }
    cout<<"-1";
}
int main(){Rosario
    cin>>n>>m;  char ch;
    REP1(i,1,n) REP1(j,1,m) cin>>a[i][j];
    cin>>sx>>sy>>ex>>ey>>ch;
    if(ch=='N') fw=0;
    else if(ch=='E') fw=1;
    else if(ch=='S') fw=2;
    else if(ch=='W') fw=3;
    bfs();
    return 0;
}
