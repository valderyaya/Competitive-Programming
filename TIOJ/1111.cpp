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

int n,ans[3],dx[]={1,1,1,0,0,-1,-1,-1},dy[]={1,0,-1,1,-1,1,-1,0};
string s[505];
bool ck(int x,int y,int xx,int yy){
    if(xx<0||xx>=n||yy<0||yy>=n) return 1;
    return s[x][y]!=s[xx][yy];
}
int dfs(int x,int y,int now,int to){
    if(now==1){int res=0;
        REP(i,8){int xx=x+dx[i],yy=y+dy[i];
            if(xx<0||xx>=n||yy<0||yy>=n||s[x][y]!=s[xx][yy]||ck(x,y,x-dx[i],y-dy[i])==0) continue;
            res+=dfs(xx,yy,now+1,i);
        }return res;
    }int xx=x+dx[to],yy=y+dy[to];
    if(now==5){
        if(xx>=0&&xx<n&&yy>=0&&yy<n&&s[xx][yy]==s[x][y]) return 0;
        return 1;
    }
    if(xx>=0&&xx<n&&yy>=0&&yy<n&&s[xx][yy]==s[x][y]) return dfs(xx,yy,now+1,to);
    return 0;
}
int main(){Rosario
    while(cin>>n,n){ans[0]=ans[1]=ans[2]=0;
        REP(i,n) cin>>s[i];
        REP(i,n) REP(j,n) if(s[i][j]!='.') ans[s[i][j]-'A']+=dfs(i,j,1,0);
        REP(i,3) cout<<char('A'+i)<<' '<<ans[i]/2<<"\n";
        cout<<"\n";
    }
    return 0;
}
