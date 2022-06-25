#pragma GCC optimize("O2")
#include<bits/stdc++.h>
using namespace std;
#define valder ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
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

int n,sx,sy,ex,ey,cnt[1505][1505];
string s[1505];
queue<pii> q;
const int inf = 1e9;
bool vis[1505][1505];
signed main(){valder
    cin>>n>>sx>>sy>>ex>>ey;
    if((abs(sx-ex)+abs(sy-ey))&1) return cout<<-1,0;
    --sx,--sy,--ex,--ey;
    for(int i=0;i<n;++i) cin>>s[i];
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j) cnt[i][j]=inf;
    q.emplace(mkp(sx,sy));
    cnt[sx][sy]=0;
    vis[sx][sy]=1;
    int x,y,xx,yy,c;
    while(!q.empty()){
        tie(x,y)=q.front(); q.pop();
        c=cnt[x][y]; vis[x][y]=0;
        int i;
        for(i=1;;++i){
            xx=x+i, yy=y+i;
            if(xx>=n||yy>=n||s[xx][yy]=='#') break;
        }
        for(--i;i;--i){
            xx=x+i, yy=y+i;
            if(c+1<cnt[xx][yy]){
                if(xx==ex&&yy==ey) return cout<<c+1,0;
                cnt[xx][yy]=c+1;
                if(!vis[xx][yy]) q.emplace(mkp(xx,yy)),vis[xx][yy]=1;
            }
        }

        for(i=1;;++i){
            xx=x-i, yy=y-i;
            if(xx<0||yy<0||s[xx][yy]=='#') break;
        }
        for(--i;i;--i){
            xx=x-i, yy=y-i;
            if(c+1<cnt[xx][yy]){
                if(xx==ex&&yy==ey) return cout<<c+1,0;
                cnt[xx][yy]=c+1;
                if(!vis[xx][yy]) q.emplace(mkp(xx,yy)),vis[xx][yy]=1;
            }
        }

        for(i=1;;++i){
            xx=x-i, yy=y+i;
            if(xx<0||yy>=n||s[xx][yy]=='#') break;
        }
        for(--i;i;--i){
            xx=x-i, yy=y+i;
            if(c+1<cnt[xx][yy]){
                if(xx==ex&&yy==ey) return cout<<c+1,0;
                cnt[xx][yy]=c+1;
                if(!vis[xx][yy]) q.emplace(mkp(xx,yy)),vis[xx][yy]=1;
            }
        }

        for(i=1;;++i){
            xx=x+i,yy=y-i;
            if(xx>=n||yy<0||s[xx][yy]=='#') break;
        }
        for(--i;i;--i){
            xx=x+i,yy=y-i;
            if(c+1<cnt[xx][yy]){
                if(xx==ex&&yy==ey) return cout<<c+1,0;
                cnt[xx][yy]=c+1;
                if(!vis[xx][yy]) q.emplace(mkp(xx,yy)),vis[xx][yy]=1;
            }
        }
    }
    cout<<-1;
}
