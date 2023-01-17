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
 
const int z=1001;
int n,m,dx[4]={-1,0,1,0},dy[4]={0,1,0,-1},prv[z][z],tot[z][z],cnt[z][z];
string s[z];
queue<pii> q;
pii st;
void dfs(int x,int y){
    if(!prv[x][y]) return;
    if(prv[x][y]==1){
        dfs(x+1,y);
        cout<<'U';
    }else if(prv[x][y]==2){
        dfs(x,y-1);
        cout<<'R';
    }else if(prv[x][y]==3){
        dfs(x-1,y);
        cout<<'D';
    }else if(prv[x][y]==4){
        dfs(x,y+1);
        cout<<'L';
    }
}
signed main(){Rosario
    cin>>n>>m;
    REP(i,n) REP(j,m) tot[i][j]=1e9;
    REP(i,n) cin>>s[i];
    REP(i,n) REP(j,m) {
        if(s[i][j]=='M') tot[i][j]=1,q.push({i,j});
        if(s[i][j]=='A') cnt[i][j]=1,st={i,j};
    }
    while(!q.empty()){
        auto o=q.front(); q.pop();
        REP(i,4){
            int x=o.F+dx[i], y=o.S+dy[i];
            if(x<0||x>=n||y<0||y>=m||s[x][y]=='#'||tot[x][y]!=1e9) continue;
            tot[x][y]=tot[o.F][o.S]+1;
            q.push({x,y});
        }
    }
    q.emplace(st);
    while(!q.empty()){
        auto o=q.front(); q.pop();
        if(o.F==0||o.F==n-1||o.S==0||o.S==m-1){
            // REP(i,n) REP(j,m) cout<<cnt[i][j]<<" \n"[j==m-1];
            // cout<<"\n";
            // REP(i,n) REP(j,m) cout<<tot[i][j]<<" \n"[j==m-1];
            cout<<"YES\n"<<cnt[o.F][o.S]-1<<"\n";
            dfs(o.F,o.S);
            return 0;
        }
        REP(i,4){
            int x=o.F+dx[i], y=o.S+dy[i];
            if(x<0||x>=n||y<0||y>=m||s[x][y]=='#'||cnt[x][y]||tot[x][y]<=cnt[o.F][o.S]+1) continue;
            cnt[x][y]=cnt[o.F][o.S]+1;
            prv[x][y]=i+1;
            q.push({x,y}); 
        }
    }
    
    cout<<"NO\n";
}
