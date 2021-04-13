//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
#define F first
#define S second
#define pb push_back
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define ALL(x) (x).begin(),(x).end()
#define mkp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
//#define lb(x) (x&-x)

const int mod=32768;
struct edge{int to,nxt,w;}e[1000005];
int t,num,n,m,sum[1005],h[1005],cnt,in[1005],c[1005];
void add(int u,int v,int w){
    e[++cnt]=edge{v,h[u],w};
    h[u]=cnt;
}
string s[105];
queue<int> q;
void topo(){
    q.emplace(0); c[0]=1; sum[0]=0;
    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int i=h[x];i;i=e[i].nxt){
            int v=e[i].to;
            c[v]+=c[x];
            sum[v]=(sum[v]+sum[x]+c[x]*e[i].w)%mod;
            if(--in[v]==0) q.emplace(v);
        }
    }
}
int main(){Rosario
    cin>>t;
    REP1(k,1,t){
        cin>>num>>n>>m; cnt=0;
        memset(in,0,sizeof(in));
        memset(c,0,sizeof(c));
        memset(sum,0,sizeof(sum));
        memset(h,0,sizeof(h));
        REP1(i,1,num) cin>>s[i];
        for(int x,y,z;m;--m){
            cin>>x>>y>>z;
            add(x,y,z%mod);
            ++in[y];
        }
        topo();
        cout<<"Game #"<<k<<"\n";
        REP1(i,1,num) cout<<s[i]<<": "<<sum[i]<<"\n";
    }
    return 0;
}
