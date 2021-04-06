//#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define mkp make_pair
#define pii pair<int,int>
#define oi ios::sync_with_stdio(0),cin.tie(0);
#define pll pair<ll,ll> 
//#define lb(x) (x&-x)

struct qq{int x,y,z;}a;
int xx,yy,zz,m[51][51][51]={},x,y,z,dx[]={0,0,0,1,-1,0,0},dy[]={0,1,-1,0,0,0,0},dz[]={0,0,0,0,0,1,-1};
void print(int ax,int ay,int az){
    if(!ax&&!ay&&!az) {cout<<"(1,1,1)";return;}
    int t=m[ax][ay][az];
    print(ax-dx[t],ay-dy[t],az-dz[t]);
    cout<<"->("<<ax+1<<','<<ay+1<<','<<az+1<<")";
}
int main(){
    //oi;
    cin>>x>>y>>z;
    REP(k,z){
        REP(j,y){
            REP(i,x) cin>>m[i][j][k];
        }
    }
    if(m[0][0][0]||m[x-1][y-1][z-1]) {cout<<"no route\n";exit(0);}
    if(x==1&&y==1&&z==1){cout<<"(1,1,1)";exit(0);}
    bool ck=1;
    m[0][0][0]=1;
    queue<qq> q;
    q.emplace(qq{0,0,0});
    while(q.size()){
        a=q.front();q.pop();
        if(a.x==x-1&&a.y==y-1&&a.z==z-1){ck=0;break;}
        REP1(i,1,6){
            xx=a.x+dx[i],yy=a.y+dy[i],zz=a.z+dz[i];
            if(xx<0||xx>=x||yy<0||yy>=y||zz<0||zz>=z||m[xx][yy][zz]) continue;
            q.emplace(qq{xx,yy,zz});
            m[xx][yy][zz]=i;
        }
    }
    if(ck) cout<<"no route\n";
    else print(x-1,y-1,z-1);
//    system("pause");
    return 0;
}
