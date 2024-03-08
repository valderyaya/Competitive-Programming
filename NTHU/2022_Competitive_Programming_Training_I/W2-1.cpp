//#pragma GCC optimize("unroll-loops, no-stack-protector, Ofast")
#include<bits/stdc++.h>
using namespace std;
#define StarBurstStream ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define em emplace_back
#define lb(x) x&-x
#define pll pair<ll,ll>
#define mkp make_pair

string s;
int cal,dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool vis[10][10];
char dz[]={'D','R','U','L'};
void dfs(int x,int y,int idx){
    //cout<<x<<' '<<y<<endl;
    if(vis[x][y-1]&&vis[x][y+1]&&!vis[x-1][y]&&!vis[x+1][y]) return;
    if(vis[x+1][y]&&vis[x-1][y]&&!vis[x][y+1]&&!vis[x][y-1]) return;
    if(x==7&&y==1){
        if(idx==48) ++cal;
        return;
    }
    if(idx==48) return;
    vis[x][y] = 1;
    if(s[idx]==dz[0]){if(!vis[x+dx[0]][y+dy[0]]) dfs(x+dx[0],y+dy[0],idx+1);}
    else if(s[idx]==dz[1]) {if(!vis[x+dx[1]][y+dy[1]]) dfs(x+dx[1],y+dy[1],idx+1);}
    else if(s[idx]==dz[2]) {if(!vis[x+dx[2]][y+dy[2]]) dfs(x+dx[2],y+dy[2],idx+1);}
    else if(s[idx]==dz[3]) {if(!vis[x+dx[3]][y+dy[3]]) dfs(x+dx[3],y+dy[3],idx+1);}
    else {REP(i,4) if(!vis[x+dx[i]][y+dy[i]]) dfs(x+dx[i],y+dy[i],idx+1);}
    vis[x][y] = 0;
}
signed main(){StarBurstStream
    cin>>s;
    REP(i,9) vis[0][i]=vis[8][i]=vis[i][0]=vis[i][8]=1;
    dfs(1,1,0);
    cout<<cal<<"\n";
}
