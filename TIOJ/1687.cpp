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
#define pii pair<int,int>
#define mkp make_pair
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(x) (x&-x)


int n,m,lca[100005][21],dep[100005],an,d;
vector<int> v[100005];
bitset<100005> vis;
void dfs(int x,int d){
    vis[x]=1;dep[x]=d;
    for(int i:v[x]){
        if(!vis[i]){
            lca[i][0]=x;
            dfs(i,d+1);
        }
    }
}
void build(){
    for(int j=1;j<20;j++)  
        for(int i=1;i<=n;i++) lca[i][j]=lca[lca[i][j-1]][j-1];
}
int fin(int x,int y){
    if(dep[x]>dep[y]) swap(x,y);
    for(int i=dep[y]-dep[x],k=0;i;k++,i>>=1){
        if(i&1) y=lca[y][k];
    }
    if(x==y) return x;
    for(int i=19;i>=0;i--){
        if(lca[x][i]!=lca[y][i]){
            x=lca[x][i],y=lca[y][i];
        }
    }
    return lca[x][0];
}
int main(){Rosario
    cin>>n>>m;int a,b,c;
    REP(i,n-1) cin>>a>>b,v[a].em(b),v[b].em(a);
    dfs(1,0);build();
    while(m--){
        cin>>a>>b>>c;
        an=fin(a,b);d=dep[a]+dep[b]-dep[an]-dep[an];
        if(c>d){cout<<"-1\n";continue;}
        if(c<=dep[a]-dep[an]){
            for(int k=0;c;k++,c>>=1) if(c&1) a=lca[a][k];
            cout<<a<<"\n";
        }else{
            c=d-c;
            for(int k=0;c;k++,c>>=1) if(c&1) b=lca[b][k];
            cout<<b<<"\n";
        }
    }
//    system("pause");
    return 0;
}
