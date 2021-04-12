#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define REP(i,n) for (int i=0;i<(n);i++)
#define REP1(i,a,b) for(int i=(a);i<=(b);i++)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define F first
#define S second
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&(-x)) 

int t,n,m,x,y,xx,yy,xxx,yyy,dx[]={1,0,0,-1},dy[]={0,1,-1,0};
char a[25][25],p[]={'D','R','L','U'};
bool vis[25][25];
int main(){Rosario
   cin>>t;
   while(t--){
        cin>>n>>m;
        memset(vis,0,sizeof(vis));
        REP(i,n){
            REP(j,m) {cin>>a[i][j];
            if(a[i][j]=='S') x=i,y=j;
            if(a[i][j]=='T') xx=i,yy=j;}
        }
        while(1){
            if(x==xx&&y==yy) break;
            REP(i,4){
               xxx=x+dx[i],yyy=y+dy[i];
               if(xxx<0||xxx>=n||yyy<0||yyy>=m||vis[xxx][yyy]||a[xxx][yyy]=='#') continue;
                vis[x][y]=1;cout<<p[i];x=xxx,y=yyy;break;
            }
        }cout<<"\n";
   }
//    system("pause");
    return 0;
}

// int power(int a,int n){
//     int ans=1;
//     for(;n;n>>=1,a*=a)
//         if(n&1)
//             ans*=a;
//     return ans;
// }

// inline int read() {
//     int ret=0,f=1;char ch=getchar_unlocked();
//     while (ch<'0'||ch>'9') {if (ch=='-') f=-f;ch=getchar_unlocked();}
//     while (ch>='0'&&ch<='9') ret=(ret<<3)+(ret<<1)+(ch^48),ch=getchar_unlocked();
//     return ret*f;
// }

