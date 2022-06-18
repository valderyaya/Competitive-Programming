#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
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

struct qq{int x,y,c;};
int dx[]={2,1,-1,-2,-2,-1,1,2,2,-2,-2,2},dy[]={1,2,2,1,-1,-2,-2,-1,2,2,-2,-2};
bool vis[21][21];
void solve(int x,int y){
    queue<qq> q;
    memset(vis,0,sizeof(vis));
    q.emplace(qq{x,y,0}); vis[x][y]=1;
    qq w;
    while(!q.empty()){
        w=q.front();q.pop();
        REP(i,12){
            x=w.x+dx[i],y=w.y+dy[i];
            if(x<1||x>20||y<1||y>20||vis[x][y]) continue;
            if(x==1&&y==1){
                cout<<w.c+1<<"\n";
                return ;
            }
            vis[x][y]=1;
            q.emplace(qq{x,y,w.c+1});
        }
    }
}
int main(){Rosario
    int x,y;
    cin>>x>>y;
    solve(x,y);
    cin>>x>>y;
    solve(x,y);
//    system("pause");
    return 0;
}
