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
#define pii pair<int,int>
#define mkp make_pair
#define oi ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
//#define lowbit(x) (x&(-x)) 

struct p{int x,y;};
int dx[]={2,1,-1,-2,-2,-1,1,2},dy[]={1,2,2,1,-1,-2,-2,-1},n,m,a[401][401];
int main(){
    //oi;
    int x,y,xx,yy;
    cin>>n>>m>>x>>y;
    queue<p> q;q.emplace(p{x,y});a[x][y]=1;
    while(q.size()){
        x=q.front().x,y=q.front().y;q.pop();
        REP(i,8){
            xx=x+dx[i],yy=y+dy[i];
            if(xx<1||xx>n||yy<1||yy>m||a[xx][yy]) continue;
            a[xx][yy]=a[x][y]+1;q.emplace(p{xx,yy});
        }
    }
    REP1(i,1,n){
        REP1(j,1,m){
            cout<<left<<setw(5)<<(a[i][j]?a[i][j]-1:-1);
        }
        cout<<"\n";
    }
//    system("pause");
    return 0;
}
