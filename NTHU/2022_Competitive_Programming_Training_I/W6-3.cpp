#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
#define mkp make_pair
 
int n,m,dx[4]={-1,0,1,0},dy[]={0,1,0,-1},cnt[1001][1001],pre[1001][1001];
string s[1001];
char p[4]={'U','R','D','L'};
void dfs(int x,int y){
    if(!pre[x][y]) return;
    if(pre[x][y]==1) dfs(x+1,y);
    else if(pre[x][y]==2) dfs(x,y-1);
    else if(pre[x][y]==3) dfs(x-1,y);
    else dfs(x,y+1);
    cout<<p[pre[x][y]-1];
}
signed main(){Rosario
    cin>>n>>m;
    REP(i,n) cin>>s[i];
    REP(i,n) REP(j,m) if(s[i][j]=='A'){
        queue<pii> q;
        q.push({i,j});
        cnt[i][j]=1;
        int x,y,xx,yy;
        while(!q.empty()){
            tie(x,y)=q.front(); q.pop();
            REP(k,4){
                xx=x+dx[k],yy=y+dy[k];
                if(xx<0||xx>=n||yy<0||yy>=m||s[xx][yy]=='#'||cnt[xx][yy]) continue;
                cnt[xx][yy]=cnt[x][y]+1;
                pre[xx][yy]=k+1;
                if(s[xx][yy]=='B'){
                    cout<<"YES\n"<<cnt[x][y]<<"\n";
                    // REP(u,n) REP(v,m){
                    //     cout<<pre[u][v]-1<<" \n"[v==m-1];
                    // }
                    dfs(xx,yy);
                    return 0;
                }
                q.push({xx,yy});
            }
        }
        cout<<"NO\n";
        return 0;
    }
}
