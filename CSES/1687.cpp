#include<bits/stdc++.h>
using namespace std;
#define Rosario ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define F first
#define S second
#define ALL(x) x.begin(),x.end()
#define pii pair<int,int>
#define REP(i,n) for(int i=0;i<n;++i)
#define REP1(i,a,b) for(int i=a;i<=b;++i)
#define lb(x) x&-x
#define em emplace_back
 
 
int n,q,lca[20][200001];
vector<int> v[200001];
void dfs(int x,int p){
    for(auto &i:v[x]){
        lca[0][i]=x;
        dfs(i,x);
    }
}
int main(){Rosario
    cin>>n>>q;
    for(int i=2,x;i<=n;++i) cin>>x,v[x].em(i);
    dfs(1,0); lca[0][1]=0;
    for(int i=1;i<20;++i) for(int j=1;j<=n;++j) lca[i][j]=lca[i-1][lca[i-1][j]];
    for(int k,x,y;q--;){
        cin>>x>>y; 
        for(k=0;y;y>>=1,++k) {
            if(y&1) x=lca[k][x];
            //cout<<"y: "<<y<<' '<<x<<endl;
        }
        cout<<(x?x:-1)<<"\n";
    }
}
