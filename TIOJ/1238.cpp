//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int dx[]={1,0,0,-1},dy[]={0,1,-1,0},n,cnt,p[55],m[505][505];
string s[505];
int fin(int x){return x==p[x]?x:p[x]=fin(p[x]);}
void un(int a,int b){
    if(a==b) return;
    p[a]=b; --cnt;
}
int main(){Rosario
    cin>>n;
    REP1(i,1,50) p[i]=i;
    REP(i,n){
        cin>>s[i];
        REP(j,n) m[i][j]=(s[i][j]=='x'?++cnt:(s[i][j]=='.'?0:-1));
    }
    REP(i,n) REP(j,n) if(m[i][j]>0){ int now=m[i][j];
        queue<pii> q; q.emplace(mkp(i,j)); m[i][j]=-1;
        while(!q.empty()){
            pii pt=q.front(); q.pop();
            REP(i,4){
                int x=pt.F+dx[i],y=pt.S+dy[i];
                if(x<0||x>=n||y<0||y>=n||m[x][y]==-1) continue;
                if(m[x][y]>0) un(fin(now),fin(m[x][y]));
                m[x][y]=-1; q.emplace(mkp(x,y));
            }
        }
    }
    cout<<(cnt==1?"Strong!":"Weak!")<<"\n";
    return 0;
}
