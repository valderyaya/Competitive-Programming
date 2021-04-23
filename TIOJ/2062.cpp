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

const int z=2e6+1;
struct edge{int to,nxt;}e[z<<1];
int cnt=0,n,m,c[z],h[z],a[z],b[z],c1,c2;
inline void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
    e[++cnt]=edge{u,h[v]};
    h[v]=cnt;
}
queue<int> q;
int main(){Rosario
    cin>>n>>m;
    register int x,y;
    while(m--) cin>>x>>y,add(x,y);
    REP1(k,1,n){
        if(!c[k]){
            q.emplace(k); c[k]=1;
            while(!q.empty()){
                x=q.front(); q.pop();
                if(~c[x]) a[++c1]=x;
                else b[++c2]=x;
                for(int i=h[x];i;i=e[i].nxt){
                    y=e[i].to;
                    if(!c[y]) c[y]=-c[x],q.emplace(y);
                    else if(c[y]==c[x]){
                        cout<<"-1\n"; return 0;
                    }
                }
            }
        }
    }
    cout<<c1<<' '<<c2<<"\n";
    REP1(i,1,c1) cout<<a[i]<<' ';
    cout<<"\n";
    REP1(i,1,c2) cout<<b[i]<<' ';
    return 0;
}
