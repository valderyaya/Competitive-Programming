//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//using namespace __gnu_pbds;
using namespace std;
#define F first
#define S second
typedef long long ll;
#define REP(i,n) for(register int i=0;i<(n);++i)
#define REP1(i,a,b) for(register int i=(a);i<=(b);++i)
#define em emplace_back
#define mkp make_pair
#define pb push_back
#define ALL(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define pll pair<ll,ll>
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)

const int z=1e6+3;
struct edge{int to,nxt;}e[z<<1];
int in[z],cnt=0,out[z],tme=0,n,h[z],m,bit[3][z];
void up(int id,int x,int c){for(;x<=n;x+=lb(x)) bit[id][x]+=c;}
int que(int id,int x){
    int res=0;
    for(;x;x-=lb(x)) res+=bit[id][x];
    return res;
}
int get(int id,int l,int r){return que(id,r)-que(id,l-1);}
void add(int u,int v){
    e[++cnt]=edge{v,h[u]};
    h[u]=cnt;
}
void dfs(int x,int p){
    in[x]=++tme;
    for(int i=h[x];i;i=e[i].nxt){
        int v=e[i].to;
        if(v==p) continue;
        dfs(v,x);
    }
    out[x]=tme;
}
string s;
int main(){Rosario
    cin>>n;
    int x,y,c;
    REP(i,n-1) cin>>x>>y,add(x,y),add(y,x);
    dfs(1,0); cin>>m;
    while(m--){
        cin>>s;
        if(s[0]=='G'){
            cin>>x>>y>>c;
            if((y==2&&in[x]==out[x])||((y==1||y==0)&&x==1)) cout<<"Error\n";
            else up(y,in[x],c);
        }else if(s[0]=='D'){
            cin>>x>>y>>c;
            if(get(y,in[x],in[x])<c) cout<<"Error\n";
            else up(y,in[x],-c);
        }else{
            cin>>x;
            REP(i,3) cout<<get(i,in[x],out[x])<<' ';
            cout<<"\n";
        }
    }
    return 0;
}
