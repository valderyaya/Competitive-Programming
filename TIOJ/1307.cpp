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

int dep[10005],t,n,m,lca[17][10005];
vector<int> v[10005];
void dfs(int x,int p){
    for(auto &i:v[x])
        if(!dep[i]&&i!=p) lca[0][i]=x,dep[i]=dep[x]+1,dfs(i,x);
}
void build(){
    for(int j=1;j<15;++j)
        for(int i=1;i<=n;++i) lca[j][i]=lca[j-1][lca[j-1][i]];
}
int Lca(int a,int b){
    if(dep[a]>dep[b]) swap(a,b);
    for(int i=dep[b]-dep[a],k=0;i;i>>=1,++k) if(i&1) b=lca[k][b];
    if(a==b) return a;
    for(int i=15;~i;--i) if(lca[i][a]!=lca[i][b]) a=lca[i][a],b=lca[i][b];
    return lca[0][a];
}
int jump(int x,int d){
    for(int k=0;d;d>>=1,++k) if(d&1) x=lca[k][x];
    return x;
}
string a,b;
int main(){Rosario
    cin>>t; int x,y,z,df,mid;
    while(t--){
        cin>>n>>m; 
        REP(i,n) {
            v[i].clear(),dep[i]=0;
            REP(j,17) lca[j][i]=0;
        }
        REP(i,n-1) cin>>x>>y,v[x].em(y),v[y].em(x);
        dep[0]=1; lca[0][0]=0; dfs(0,0); build();
        while(m--){
            cin>>a>>x>>b>>y; z=Lca(x,y);
            if(dep[x]<dep[y]) swap(x,y);
            df=dep[x]+dep[y]-dep[z]-dep[z]; mid=df>>1;
            int dx=dep[x]-dep[z],dy=dep[y]-dep[z];
            if(df%2==0){
                int o;
                if(dx>=mid) o=jump(x,mid);
                else o=jump(y,dy-(mid-dx));
                cout<<a<<" and "<<b<<": "<<o<<"\n";
            }else{
                int o,p;
                if(dx<mid) o=jump(y,mid),p=jump(y,mid+1);
                else if(dy<mid) o=jump(x,mid),p=jump(x,mid+1);
                else o=jump(x,mid),p=jump(y,mid);
                if(o>p) swap(o,p);
                cout<<a<<" and "<<b<<": "<<o<<' '<<p<<"\n";
            }
        }
    }
    return 0;
}
