//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(int i=0;i<(n);++i)
#define REP1(i,a,b) for(int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

int n,m,q,f[255][255],ans[255][255];
struct qwq{
    int v,id;
    bool operator<(const qwq &a)const{return v<a.v;}
}a[255];
int main(){Rosario
    cin>>n>>m>>q;
    int x,y,c;
    REP1(i,1,n){
        cin>>a[i].v; a[i].id=i;
        REP1(j,1,n) f[i][j]=(i==j?0:1e9),ans[i][j]=1e9;
    }
    sort(a+1,a+1+n);
    while(m--){
        cin>>x>>y>>c;
        f[x][y]=f[y][x]=min(c,f[x][y]);
    }
    REP1(k,1,n) REP1(i,1,n) REP1(j,1,n){ 
        f[a[i].id][a[j].id]=min(f[a[i].id][a[j].id],f[a[i].id][a[k].id]+f[a[k].id][a[j].id]);
        ans[a[i].id][a[j].id]=min(ans[a[i].id][a[j].id],f[a[i].id][a[j].id]+max({a[i].v,a[j].v,a[k].v}));
    }
    while(q--){
        cin>>x>>y;
        cout<<ans[x][y]<<"\n";
    }
    return 0;
}
