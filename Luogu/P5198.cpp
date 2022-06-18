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


int n,d[]={0,1,0,-1,0},area,cnt;
pii ans;
char a[1005][1005];
void solve(int x,int y){
    queue<pii> q;int xx,yy;
    q.emplace(mkp(x,y));a[x][y]='-';
    while(!q.empty()){
        tie(x,y)=q.front();q.pop();
        REP(i,4){
            xx=x+d[i],yy=y+d[i+1];
            if(xx>=0&&xx<n&&yy>=0&&yy<n){
                if(a[xx][yy]=='-') continue;
                if(a[xx][yy]=='#'){
                    a[xx][yy]='-';++area;
                    q.emplace(mkp(xx,yy));
                }else if(a[xx][yy]=='.') ++cnt;
            }else ++cnt;
        }
    }
}
int main(){Rosario
    cin>>n;
    REP(i,n) REP(j,n) cin>>a[i][j];
    REP(i,n) REP(j,n){
        if(a[i][j]=='#'){
            area=1;cnt=0;
            solve(i,j);
            if(area>ans.F||(area==ans.F&&cnt<ans.S)) ans=mkp(area,cnt);
        }
    }
    cout<<ans.F<<' '<<ans.S<<"\n";
//    system("pause");
    return 0;
}
