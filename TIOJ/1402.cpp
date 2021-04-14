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
#define wait system("pause");

int n,m,a[501][501],dx[]={1,0,0,-1},dy[]={0,1,-1,0};
bool vis[501][501];
ll sum=0;
struct node{
    int x,y,h;
    bool operator<(const node &a)const{return h>a.h;}
};
priority_queue<node,vector<node>> q;
bool in(int x,int y){return x>=0&&x<n&&y>=0&&y<m;}
int main(){Rosario
    while(cin>>n>>m){sum=0;
        REP(i,n) REP(j,m){
            cin>>a[i][j]; vis[i][j]=0;
            if(i==0||j==0||i==n-1||j==m-1) q.emplace(node{i,j,a[i][j]}),vis[i][j]=1;
        }
        while(!q.empty()){
            node o=q.top();q.pop();
            REP(i,4){
                int x=o.x+dx[i],y=o.y+dy[i];
                if(!in(x,y)||vis[x][y]) continue;
                if(a[x][y]<o.h){
                    sum+=o.h-a[x][y];
                    a[x][y]=o.h;
                }
                q.emplace(node{x,y,a[x][y]});
                vis[x][y]=1;
            }
        }
        cout<<sum<<"\n";
    }
    return 0;
}
